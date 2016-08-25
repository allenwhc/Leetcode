#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
*	Dynamic Programming Solution
*	Time complexity: O(n^2)
*	Extra space: O(n)
*/
int combinationSum4(vector<int> &nums, int target){
	sort(nums.begin(), nums.end());
	vector<int> dp(target+1, 0);
	for(int i=1; i<=target; i++){
		for(auto &x: nums){
			if(x>i) break;
			else if(x==i) dp[i]+=1;
			else dp[i]+=dp[i-x];
		}
	}
	return dp[target];
}

int main(int argc, char const *argv[])
{
	vector<int> nums = {2,3,5};
	int target = 11;
	cout << combinationSum4(nums, target) << endl;
	return 0;
}