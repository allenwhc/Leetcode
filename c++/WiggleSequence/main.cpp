#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Dynamic programming solution
*  Time complexity: O(n^2)
*  Extra space: O(n)
*/
int wiggleMaxLength(vector<int> &nums){
	if(nums.size() < 2) return nums.size();
	vector<int> dp(nums.size(), 0);
	dp[0] = 1, dp[1] = dp[0] + (nums[1]!=nums[0]);
	for(int i=2; i<nums.size(); i++){
		for(int j=1; j<i; j++){
			dp[i] = max(dp[i], dp[j] + ((nums[i] - nums[j]) * (nums[j] - nums[j-1]) < 0));
			//cout << i << "," << dp[i] << endl;
		}
	}
	return dp[nums.size()-1];
}


/*
*	Greedy Solution
*	Time complexity: O(n)
*	Extra space: O(1)
*/
int wiggleMaxLength2(vector<int> &nums){
	if(nums.size() < 2) return nums.size();
	int length = nums.size();
	char prev = '#';
	for(int i=1; i<nums.size(); i++){
		//cout << prev <<","<<length<<endl;
		if(nums[i]>nums[i-1]){
			length -= prev == '+';
			prev = '+';
		}else if(nums[i]<nums[i-1]){
			length -= prev == '-';
			prev = '-';
		}else length--;
	}
	return length;
}

int main(int argc, char const *argv[])
{
	vector<int> nums = {3,3,3,2,5};
	cout << "Max length of a wiggle sequence: " << wiggleMaxLength2(nums) << endl;
	return 0;
}