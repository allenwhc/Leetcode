#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/*
*	DP solution
*	Time complexity: O(n^3)
*	Extra space: O(n^2)
*/
int maxCoins(vector<int>& nums){
	if(nums.empty()) return 0;
	int n = nums.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for(int i=0; i<n; i++){
		dp[i][i] = nums[i] * (i==0?1:nums[i-1]) * (i==n-1?1:nums[i+1]);
	}
	for(int len=2; len<=n; len++){
		for(int i=0; i<=n-len; i++){
			int temp = INT_MIN;
			for(int j=i; j<=i+len-1; j++){
				int left = (j==0?0:dp[i][j-1]);
				int right = (j==i+len-1?0:dp[j+1][i+len-1]);
				int self = nums[j] * (i==0?1:nums[i-1]) * (i+len==n?1:nums[i+len]);
				int curr = left + right + self;
				// cout << len << "," << i << "," << j << ": left="<<left<<",right="<<right<<",self="<<self << endl;
				// cout << "curr=" << curr << endl;
				temp = max(temp, curr);
				// cout << "temp=" << temp << endl;
			}
			dp[i][i+len-1] = temp;
		}
	}
	// for(vector<int> v: dp){
	// 	for(int x: v) cout << x << " ";
	// 	cout << endl;
	// }
	return dp[0][n-1];
}

int main(int argc, char const *argv[])
{
	vector<int> nums = {3,1,5,8};
	cout << maxCoins(nums) << endl;
	return 0;
}