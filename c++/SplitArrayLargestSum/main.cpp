#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution
{
public:
	/*
	*	Binary-search + Dynamic programming Solution
	*	Time complexity: O(nlogm)
	*	Extra space: O(1)
	*/
	int splitArray(vector<int>& nums, int m){
		if(nums.empty() || !m) return 0;
		if(find(nums.begin(),nums.end(),INT_MAX) != nums.end()) return m==nums.size()?INT_MAX:INT_MIN;
		int start = *max_element(nums.begin(),nums.end());
		int end = accumulate(nums.begin(),nums.end(),0);
		int sum = INT_MAX;
		while(start<=end){
			int mid = (end-start)/2+start;
			int k = 1;
			int curr_sum = 0, temp = 0;
			for(int i=0; i<nums.size(); i++){
				if(curr_sum + nums[i] > mid){
					curr_sum = nums[i];
					k++;
				}else curr_sum += nums[i];
				temp = max(temp, curr_sum);
			}
			if(k<=m) {
				end = mid - 1;
				sum = min(sum,temp);
			}
			else start = mid + 1;
		}
		return sum;
	}
};


int main(int argc, char const *argv[])
{
	Solution sol;
	vector<int> nums = {2,3,1,2,4,3};
	int m = 5;
	cout << sol.splitArray(nums,m) << endl;
	return 0;
}