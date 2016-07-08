#include <vector>
#include <iostream>
using namespace std;
vector<int> largestDivisibleSubset(vector<int>& nums) {
		if(nums.empty()) return {};
		sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<int> dp(n, 1), index(n, -1);
		vector<int> res;
		int max_divisible_subset = 0, end_index = -1;
		for(int i=0; i<n; i++){
			for(int j=i-1; j>=0; j--){
				if(!(nums[i]%nums[j]) && dp[i] < dp[j] + 1){
					dp[i] = dp[j] + 1;
					index[i] = j;
				}
			}
			if(max_divisible_subset < dp[i]){
				max_divisible_subset = dp[i];
				end_index = i;
			}
		}
	//    for(auto &v: index) cout << v << endl;
		for(int i=end_index; i!=-1; i=index[i]) res.push_back(nums[i]);
		return res;
	}

int main(int argc, char const *argv[])
{
	vector<int> nums = {2,7,3,4,6,10,9,12};
	for(auto &v: largestDivisibleSubset(nums))
		cout << v << " ";
	cout << endl;
	return 0;
}