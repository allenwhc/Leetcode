/*
*	Combinations
*	Last Modified: 6/4/2015
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
	vector<vector<int>> combine(int n, int k){
		vector<vector<int>> result;
		vector<int> solution(k);
		if (n <= 0 || k <= 0){
			result[0].push_back(0);
			return result;
		}
		else
		{
			vector<bool> v(n);
			fill(v.begin() + n - k, v.end(), true);
			do
			{
				solution.clear();
				for (int i = 0; i < n; i++){
					if (v[i])
					{
						solution.push_back(i + 1);
					}
				}
				result.push_back(solution);
			} while (next_permutation(v.begin(),v.end()));
			return result;
		}
	}
};

void main(int argc, char *argv[]){
	int n, k;
	cout << "Input the integer range n: ";
	cin >> n;
	cout << "Input the combination numbers k: ";
	cin >> k;
	vector<vector<int>> resultCombinations;
	Solution s;
	resultCombinations = s.combine(n, k);
	cout << "The combinations are: " << endl;
	cout << "[";
	for (int i = 0; i < resultCombinations.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < resultCombinations[0].size(); j++)
		{
			cout << resultCombinations[i][j];
			if (j != resultCombinations[i].size() - 1)
				cout << ",";
		}
		cout << "]";
		if (i != resultCombinations.size() - 1)
			cout << "," << endl;
	}
	cout << "]" << endl;
	system("pause");
}