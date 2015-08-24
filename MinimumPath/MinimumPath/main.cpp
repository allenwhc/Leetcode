/*
*	Minimum Sum of Weight
*	Last Modified: 5/29/2015
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
	int minPathSum(vector<vector<int>>& grid){
		if (grid.empty() || grid[0].empty()) return 0;
		int row = grid.size();
		int column = grid[0].size();
		vector<int> path(column + 1, INT_MAX);
		path[1] = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				path[j + 1] = min(path[j + 1], path[j]) + grid[i][j];
				cout << path[j + 1] << "->";
			}
		}
		return path.back();
	}
};

void main(int argc, char*argv[]){
	vector<vector<int>> grid = { {3,4,10,2},
								 {1,7,2,4},
								 {5,4,2,3}
								};
	int weight = 0;
	Solution s;
	weight = s.minPathSum(grid);
	cout << endl;
	cout << "The minimum weight is: " << weight << endl;
	system("pause");
}