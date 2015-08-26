/*
*	Unique Paths I & II
*	Last Modified: 6/29/2015
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	//Unique Paths I
	int uniquePaths(int m, int n){
		if (m == 0 || n == 0) return 0;
		if (m == 1 || n == 1) return 1;
		vector<vector<int>> paths(m, vector<int>(n));
		for (int i = 0; i < m; i++)
			paths[i][0] = 1;
		for (int i = 0; i < n; i++)
			paths[0][i] = 1;
		for (int i = 1; i < m; i++){
			for (int j = 1; j < n; j++){
				paths[i][j] = paths[i][j - 1] + paths[i - 1][j];
			}
		}
		return paths[m - 1][n - 1];
	}

	//Unique Paths II
	int uniquePathsWithObstacle(vector<vector<int>>& obstacleGrid){
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if (m == 0 || n == 0) return 0;
		if (m == 1){
			for (int i = 0; i < n; i++){
				if (obstacleGrid[0][i] == 1){
					return 0;
				}
			}
			return 1;
		}
		if (n == 1){
			for (int i = 0; i < m; i++){
				if (obstacleGrid[i][0] == 1){
					return 0;
				}
			}
			return 1;
		}
		vector<vector<int>> uniquePaths(m, vector<int>(n));
		if (obstacleGrid[0][0] == 1) return 0;
		else{
			int firstRow = 0, firstCol = 0;
			while (firstRow < n){
				if (obstacleGrid[0][firstRow] == 0){
					uniquePaths[0][firstRow] = 1;
					firstRow++;
				}
				else break;
			}
			while (firstCol < m){
				if (obstacleGrid[firstCol][0] == 0){
					uniquePaths[firstCol][0] = 1;
					firstCol++;
				}
				else break;
			}
			for (int i = 1; i < m; i++){
				for (int j = 1; j < n; j++){
					if (obstacleGrid[i][j] == 0)
						uniquePaths[i][j] = uniquePaths[i - 1][j] + uniquePaths[i][j - 1];
					else
						uniquePaths[i][j] = 0;
				}
			}
			return uniquePaths[m - 1][n - 1];
		}
	}
};

void main(int argc, char *argv[]){
	int m = 3;
	int n = 7;
	Solution s;
	int numOfPaths = s.uniquePaths(m, n);
	cout << "Unique Paths I (No obstacles):" << endl;
	cout << "There are " << numOfPaths << " paths from top-left corner to bottom-right corner for a " << m << "*" << n << " grid" << endl;


	vector<vector<int>> grid = { { 0, 0, 0, 0, 1 }, { 0, 1, 0, 0, 0 }, { 1, 0, 0, 0, 0 }, { 0, 0, 0, 1, 0 }, {0, 0, 1, 0, 0} };
	//vector<vector<int>> grid = { { 0, 0 }, { 1, 1 }, { 0, 0 } };
	cout << endl << "Unique Paths II (with obstacle): " << endl;
	cout << "The grid is: " << endl;
	cout << "[" << endl;
	for (int i = 0; i < grid.size(); i++){
		cout << "[";
		for (int j = 0; j < grid[i].size(); j++){
			cout << grid[i][j];
			if (j != grid[i].size() - 1) cout << ",";
		}
		cout << "]";
		if (i != grid.size() - 1) cout << "," << endl;
	}
	cout << endl << "]" << endl;
	int num = s.uniquePathsWithObstacle(grid);
	cout << "There are " << num << " paths from top-left corner to bottom-right corner for the above given " << grid.size() << "*" << grid[0].size() << " grid" << endl;
	system("pause");
}