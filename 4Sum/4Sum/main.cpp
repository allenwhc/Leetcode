/*
*	4 Sum
*	Last Modified: 7/8/2015
*/

#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target){
		int n = nums.size();
		vector<vector<int>> allSols;
		vector<int> sol;
		sort(nums.begin(), nums.end());
		kSum(0, n - 1, target, 4, nums, sol, allSols);
		return allSols;
	}

	void kSum(int start, int end, int target, int k, vector<int>& nums, vector<int>& sol, vector<vector<int>>& allSols){
		if (k <= 0) return;
		if (k == 1){
			for (int i = start; i <= end; i++){
				if (nums[i] == target){
					sol.push_back(nums[i]);
					allSols.push_back(sol);
					sol.pop_back();
					return;
				}
			}
		}
		if (k == 2){
			twoSum(start, end, target, nums, sol, allSols);
			return;
		}
		for (int i = start; i <= end - k + 1; i++){
			if (i > start&&nums[i] == nums[i - 1]) continue;
			sol.push_back(nums[i]);
			kSum(i + 1, end, target - nums[i], k - 1, nums, sol, allSols);
			sol.pop_back();
		}
	}

	void twoSum(int start, int end, int target, vector<int>& nums, vector<int>& sol, vector<vector<int>>& allSols){
		while (start < end){
			int sum = nums[start] + nums[end];
			if (sum == target){
				sol.push_back(nums[start]);
				sol.push_back(nums[end]);
				allSols.push_back(sol);
				sol.pop_back();
				sol.pop_back();
				start++;
				end--;
				while (nums[start] == nums[start - 1]) start++;
				while (nums[end] == nums[end + 1]) end--;
			}
			else if (sum < target) start++;
			else end--;
		}
	}
};

void main(int argc, char* argv[]){
	vector<int> nums = { 1, 0, -1, 0, -2, 2 };
	int target = 0;
	Solution s;
	vector<vector<int>> res = s.fourSum(nums, target);
	cout << "The solutions which add up to " << target << " in array: ";
	for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
	cout << "are: " << endl;
	for (int i = 0; i < res.size(); i++){
		cout << "(";
		for (int j = 0; j < res[i].size(); j++){
			cout << res[i][j];
			if (j != res[i].size() - 1) cout << ",";
		}
		cout << ")" << endl;
	}
	system("pause");
}