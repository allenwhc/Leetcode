/*
*	Combination Sum I & II & III
*	Last Modified: 7/1/2015
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public: 
	//Each candidate can be used for multiple times
	vector<vector<int>> combinationSum1(vector<int>& candidates, int target){
		int n = candidates.size();
		vector<vector<int>> combination;
		vector<int> solution;
		if (n == 0)
			return combination;	//Return empty
		sort(candidates.begin(), candidates.end());	//Sorts the array
		getCombination(candidates, solution, combination, 0, target);
		return combination;
	}

	//Combination Sum III
	vector<vector<int>> combinationSum3(int k, int n){
		vector<vector<int>> allSol;
		vector<int> sol;
		if (n == 0) return allSol;
		search(allSol, sol, k, n, 0, 1);
		return allSol;
	}

	void search(vector<vector<int>>& allSol, vector<int>& sol, int k, int n, int sum, int curr){
		if (sum > n || sol.size() > k) return;
		if (sum == n && sol.size() == k){
			allSol.push_back(sol);
		}
		else{
			//cout << "sum=" << sum << ", curr=" << curr << endl;
			for (int i = curr; i <= 9; i++){
				sol.push_back(i);
				search(allSol, sol, k, n, sum + i, i + 1);
				sol.pop_back();
			}
		}
	}
private:
	void getCombination(vector<int> &candidates, vector<int> &solution, vector<vector<int>> &combination, int start, int target){
		if (target == 0){
			combination.push_back(solution);
			return;
		}	
		for (int i = start; i < candidates.size(); i++){
			if (i>start&&candidates[i] == candidates[i - 1])
				continue;
			if (candidates[i] <= target){
				solution.push_back(candidates[i]);
				//getCombination(candidates, solution, combination, i, target - candidates[i]);	//For multiple use
				getCombination(candidates, solution, combination, i + 1, target - candidates[i]);	//For single use
				solution.pop_back();
			}
		}
	}
};

void main(int argc, char *argv[]){
	vector<int> candidates = { 10, 1, 2, 7, 6, 1, 5 };
	Solution s;
	int target = 8;
	cout << "Combination Sum I: " << endl;
	vector<vector<int>> combination = s.combinationSum1(candidates, target);
	cout << "The candidate numbers are: " << endl;
	for (int i = 0; i < candidates.size(); i++)
		cout << candidates[i] << " ";
	cout << endl;
	cout << "The combination sum of " << target << " is: " << endl;
	for (int i = 0; i < combination.size(); i++){
		cout << "[";
		for (int j = 0; j < combination[i].size(); j++)
		{
			cout << combination[i][j];
			if (j != combination[i].size() - 1)
				cout << ",";
		}
		cout << "]" << endl;
	}


	//Combination III
	cout << endl << "Combination Sum III: " << endl;
	int k = 3;
	int n = 9;
	vector<vector<int>> res = s.combinationSum3(k, n);
	cout << "All possible solutions that add up to " << n << " with " << k << " integers are:" << endl;
	cout << "[" << endl;
	for (int i = 0; i < res.size(); i++){
		cout << "[";
		for (int j = 0; j < res[i].size(); j++){
			cout << res[i][j];
			if (j != res[i].size() - 1) cout << ",";
		}
		cout << "]";
		if (i != res.size() - 1) cout << ",";
	}
	cout << "]" << endl;
	system("pause");
}