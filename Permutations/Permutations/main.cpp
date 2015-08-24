/*
*	Permutations I & II
*	Last Modified: 6/29/2015
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
	//Permutaions I, no duplicate elements in the array
	vector<vector<int>> permute(vector<int>& nums){
		vector<vector<int>> result;
		vector<int> solution;
		int n = nums.size();
		if (n == 0){
			solution.push_back(0);
			result.push_back(solution);
			return result;
		}
		else if (n == 1){
			solution.push_back(1);
			result.push_back(solution);
			return result;
		}
		else{
			sort(nums.begin(), nums.end());
			do
			{
				solution.clear();
				for (int i = 0; i < n; i++)
					solution.push_back(nums[i]);
				result.push_back(solution);
			} while (next_permutation(nums.begin(), nums.end()));
			return result;
		}
	}

	//Permutations II, might contain duplicate elements in the array
	vector<vector<int>> permuteUnique(vector<int>& nums){
		vector<vector<int>> allSol;
		vector<int> sol;
		vector<int> duplicate(nums.size(), 0);
		int n = nums.size();
		if (n == 0) return allSol;
		sort(nums.begin(), nums.end());
		generate(nums, duplicate, sol, allSol, 0);
		return allSol;
	}

	void generate(vector<int>nums, vector<int>& duplicate, vector<int>& sol, vector<vector<int>>& allSol, int step){
		if (step == nums.size()){
			allSol.push_back(sol);
			return;
		}
		for (int i = 0; i < nums.size(); i++){
			
			if (duplicate[i] == 0){
				if (i>0 && nums[i] == nums[i - 1] && duplicate[i - 1] == 0) continue;
				duplicate[i] = 1;
				sol.push_back(nums[i]);
				generate(nums, duplicate, sol, allSol, step + 1);
				sol.pop_back();
				duplicate[i] = 0;
			}
		}
	}
};

void main(int argc, char *argv[]){
	vector<int> nums1 = { 0, -1, 1 };
	vector<int> nums2 = { 1, 1, 2, 2, 4 };
	vector<vector<int>> resultPermutations;
	vector<vector<int>> unique;
	Solution s;
	resultPermutations = s.permute(nums1);
	unique = s.permuteUnique(nums2);
	cout << "Permutaions I (No duplicates): " << endl;
	cout << "The array is: [";
	for (int i = 0; i < nums1.size(); i++){
		cout << nums1[i];
		if (i != nums1.size() - 1) cout << ",";
	}
	cout << "]" << endl;
	cout << "The permutations are: " << endl;
	cout << "[";
	for (int i = 0; i < resultPermutations.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < resultPermutations[0].size(); j++)
		{
			cout << resultPermutations[i][j];
			if (j != resultPermutations[i].size() - 1)
				cout << ",";
		}
		cout << "]";
		if (i != resultPermutations.size() - 1)
			cout << "," << endl;
	}
	cout << "]" << endl;

	cout << endl << "Permutations II (Duplicates exist):" << endl;
	cout << "The array is: [";
	for (int i = 0; i < nums2.size(); i++){
		cout << nums2[i];
		if (i != nums2.size() - 1) cout << ",";
	}
	cout << "]" << endl;
	cout << "The permutations are: " << endl;
	cout << "[";
	for (int i = 0; i < unique.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < unique[0].size(); j++)
		{
			cout << unique[i][j];
			if (j != unique[i].size() - 1)
				cout << ",";
		}
		cout << "]";
		if (i != unique.size() - 1)
			cout << "," << endl;
	}
	cout << "]" << endl;
	system("pause");
}