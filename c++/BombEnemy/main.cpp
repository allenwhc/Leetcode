#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxKilledEnemies(vector<vector<char>> &grid){
	if(grid.empty()) return 0;
	int m = grid.size(), n = grid[0].size();
	int res = 0, rowHits = 0;
	vector<int> colHits(n, 0);

	for (int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if (!i || grid[i-1][j] == 'W'){
				colHits[j] = 0;
				for (int k=i; k<m && grid[k][j] != 'W'; k++)
					colHits[j] += grid[k][j] == 'E';
			}
			if(!j || grid[i][j-1] == 'W'){
				rowHits = 0;
				for(int k=j; k<n && grid[i][k] != 'W'; k++)
					rowHits += grid[i][k] == 'E';
			}
			if(grid[i][j] == '0') res = max(res, rowHits + colHits[j]);
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	vector<vector<char>> grid = {{'0','E','0','0'},{'E','0','W','E'},{'0','E','0','0'}};
	cout << maxKilledEnemies(grid) << endl;
	return 0;
}