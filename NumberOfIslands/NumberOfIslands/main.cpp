/*
*	Number of Islands
*	Last Modified: 7/2/2015
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
	int numIslands(vector<vector<char>>& grid){
		int m = grid.size();
		if (m == 0) return 0;
		int n = grid[0].size();
		if (n == 0) return 0;
		int num = 0;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (grid[i][j] != '1') continue;
				num++;
				merge(grid, i, j);
			}
		}
		return num;
	}
	void merge(vector<vector<char>>& grid, int i, int j){
		int m = grid.size();
		int n = grid[0].size();
		if (i < 0 || i >= m || j < 0 || j >= n) return;
		if (grid[i][j] == '1'){
			grid[i][j] = '2';	//Change '1' to '-1'
			merge(grid, i - 1, j);	//Recursively on the up adjacent land
			merge(grid, i + 1, j);	//Recursively on the down adjacent land
			merge(grid, i, j - 1);	//Recursively on the left adjacent land
			merge(grid, i, j + 1);	//Recursively on the right adjacent land
		}
	}
};

void main(int argc, char* argv[]){
	vector<vector<char>> grid1 = { { '1', '1', '1', '1', '0' }, { '1', '1', '0', '1', '0' }, { '1', '1', '0', '0', '0' }, { '0', '0', '0', '0', '0' } };
	vector<vector<char>> grid2 = { { '1', '1', '0', '0', '0' }, { '1', '1', '0', '0', '0' }, { '0', '0', '1', '0', '0' }, { '0', '0', '0', '1', '1' } };
	Solution s;
	cout << "The map of grid 1 is: " << endl;
	for (int i = 0; i < grid1.size(); i++){
		for (int j = 0; j < grid1[i].size(); j++)
			cout << grid1[i][j];
		cout << endl;
	}
	int num1 = s.numIslands(grid1);
	cout << "The number of islands in grid 1 is: " << num1 << endl;

	cout << endl;
	cout << "The map of grid 2 is: " << endl;
	for (int i = 0; i < grid2.size(); i++){
		for (int j = 0; j < grid2[i].size(); j++)
			cout << grid2[i][j];
		cout << endl;
	}
	int num2 = s.numIslands(grid2);
	
	cout << "The number of islands in grid 2 is: " << num2 << endl;
	system("pause");
}