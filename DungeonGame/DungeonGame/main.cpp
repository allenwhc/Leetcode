/*
*	Dungeon Game
*	Last Modified: 7/6/2015
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon){
		int m = dungeon.size();
		int n = dungeon[0].size();
		if (m == 0 || n == 0) return 0;
		vector<vector<int>> hp(m, vector<int>(n));

		//If the last room has negative number, then the knight needs at least (1-dungeon[m-1][n-1]) health points.
		//Otherwise, the knights needs only 1 health point
		hp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);

		//Initializes the last row of hp[][]
		for (int i = m - 2; i >= 0; i--)
			hp[i][n - 1] = max(1, hp[i + 1][n - 1] - dungeon[i][n - 1]);

		//Initializes the last column of hp[][]
		for (int i = n - 2; i >= 0; i--)
			hp[m - 1][i] = max(1, hp[m - 1][i + 1] - dungeon[m - 1][i]);

		//Calculates the health points the knight needs before entering room (i,j)
		for (int i = m - 2; i >= 0; i--){
			for (int j = n - 2; j >= 0; j--){
				int rightMinHP = max(1, hp[i][j + 1] - dungeon[i][j]);	//Calculates the minimum hp if knight goes right
				int downMinHP = max(1, hp[i + 1][j] - dungeon[i][j]);	//Calculates the minimum hp if knight goes down
				hp[i][j] = min(rightMinHP, downMinHP);	//Set hp[i][j] to be the smaller hp betweent the right and the down path
			}
		}
		return hp[0][0];
	}
};

void main(int argc, char* argv[]){
	vector<vector<int>> dungeon = { { -2, -3, 3 }, { -5, -10, 1 }, { 10, 30, -5 } };
	Solution s;
	cout << "The minimum health point should be: " << s.calculateMinimumHP(dungeon) << endl;
	system("pause");
}