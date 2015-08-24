/*
*	Subsets I & II
*	Last Modified: 7/7/2015
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
	//Subsets I, all elements are distinct
	vector<vector<int>> subsets(vector<int>& nums){
		int n = nums.size();
		vector<vector<int>> allSubset;
		vector<int> subset;
		allSubset.push_back(subset);	//Adds empty set to the solution
		if (n == 0) return allSubset;
		sort(nums.begin(), nums.end());	//Sorts the input array
		generateCombination(nums, 0, subset, allSubset);
		return allSubset;
	}

	void generateCombination(vector<int>& nums, int step, vector<int>& subset, vector<vector<int>>& allSubset){
		for (int i = step; i < nums.size(); i++){
			subset.push_back(nums[i]);
			allSubset.push_back(subset);
			if (i < nums.size() - 1) generateCombination(nums, i + 1, subset, allSubset);
			subset.pop_back();
		}
	}

	//Subsets II, duplicate elements may be contained
	vector<vector<int>> subsetsWithDup(vector<int>& nums){
		vector<vector<int>> allSubsets;
		vector<int> subset;
		int n = nums.size();
		if (n == 0) return allSubsets;
		allSubsets.push_back(subset);
		sort(nums.begin(), nums.end());
		generate(nums, 0, subset, allSubsets);
		return allSubsets;
	}

	void generate(vector<int>& nums, int step, vector<int>& subset, vector<vector<int>>& allSubsets){
		for (int i = step; i < nums.size(); i++){
			subset.push_back(nums[i]);
			allSubsets.push_back(subset);
			if (i < nums.size() - 1) generate(nums, i + 1, subset, allSubsets);
			subset.pop_back();
			while (i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
		}
	}
};

void main(int argc, char *argv[]){
	vector<int> nums = { 1, 2, 3 };
	Solution s;
	vector<vector<int>> result = s.subsets(nums);
	cout << "The solution of all possible sets of [";
	for (int i = 0; i < nums.size(); i++){
		cout << nums[i];
		if (i != nums.size() - 1) cout << ",";
	}
	cout << "] is: " << endl;
	cout << "[" << endl;
	for (int i = 0; i < result.size(); i++){
		cout << "[";
		for (int j = 0; j < result[i].size(); j++){
			if (result[i].size() == 0) cout << " ";
			else{
				cout << result[i][j];
				if (j != result[i].size() - 1) cout << ",";
			}
		}
		cout << "]";
		if (i != result.size() - 1) cout << "," << endl;
 	}
	cout << endl << "]" << endl;

	vector<int> nums2 = { 1, 2, 2 };
	cout << "The solution of all possible sets of [";
	for (int i = 0; i < nums2.size(); i++){
		cout << nums2[i];
		if (i != nums2.size() - 1) cout << ",";
	}
	cout << "] is: " << endl;
	vector<vector<int>> res = s.subsetsWithDup(nums2);
	cout << "[" << endl;
	for (int i = 0; i < res.size(); i++){
		cout << "[";
		for (int j = 0; j < res[i].size(); j++){
			if (res[i].size() == 0) cout << " ";
			else{
				cout << res[i][j];
				if (j != res[i].size() - 1) cout << ",";
			}
		}
		cout << "]";
		if (i != res.size() - 1) cout << "," << endl;
	}
	cout << endl << "]" << endl;
	system("pause");
}