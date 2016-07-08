#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

int LIS(vector<int> &nums){
	if(nums.size() <=1 ) return nums.size();
	vector<int> dp(nums.size(), 1);
	for(int i=1; i<nums.size(); i++){
		for(int j=0; j<i; j++){
			if(nums[i] > nums[j] && dp[i] < dp[j] + 1){
				dp[i] = dp[j] + 1;
			}
		}
	}
	return *max_element(dp.begin(), dp.end());
}

vector<int> getLIS(vector<int> &nums){
	if(nums.empty()) return {};

}

int main(int argc, char const *argv[])
{
	vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
	cout << LIS(nums) << endl;
	for(auto &v: getLIS(nums)) cout << v << " ";
	cout << endl;
	return 0;
}