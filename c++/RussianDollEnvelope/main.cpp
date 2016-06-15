#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxEnvelopes(vector<pair<int,int>> &envelopes){
	if (envelopes.empty()) return 0;
	int n = envelopes.size();
	sort(envelopes.begin(), envelopes.end(), [](pair<int, int> p1, pair<int,int> p2){return p1.first != p2.first ? p1.first < p2.first: p1.second > p2.second;});
	vector<int> dp(n, 0), v(n+1, INT_MAX);
	for (int i=0; i<n; i++){
		int idx = lower_bound(++v.begin(), v.end(), envelopes[i].second) - v.begin();
		dp[i] = idx;
		v[idx] = envelopes[i].second;
	}
	return *max_element(dp.begin(), dp.end());
}

int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        for (int i=0; i<nums.size(); i++){
            dp[lower_bound(nums.begin(), nums.end(), nums[i])-nums.begin()] = nums[i];
        }
        sort(dp.begin(), dp.end());
      //  for (auto it = dp.begin(); it != dp.end(); it++) cout << *it << endl;
     //   int res = find(dp.begin(), dp.end(), INT_MAX) - dp.begin();
      //  cout << res << endl;
        return distance(dp.begin(), find(dp.begin(), dp.end(), INT_MAX));
    }

int main(int argc, char const *argv[])
{
	vector<int> nums = {-1,-2,-3,-4,-5,-6};
	vector<pair<int, int>> envelopes = {{2,100},{3,200},{4,300},{5,500},{5,400},{5,250},{6,370},{6,360},{7,380}};
	cout << maxEnvelopes(envelopes) << endl;
	cout <<lengthOfLIS(nums) << endl;
	return 0;
}