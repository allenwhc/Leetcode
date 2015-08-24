/*
*	Surrounded Regions
*	Last Modified: 7/16/2015
*/

#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		int m = board.size();
		if (m == 0) return;
		int n = board[0].size();
		if (n == 0) return;
		vector<vector<bool>> isLive(m, vector<bool>(n, false));	//Initialize a 2D boolean array with false 
		queue<pair<int, int>> q;

		//Scan the first row
		for (int i = 0; i < n; i++){
			if (board[0][i] == 'O'){
				isLive[0][i] = true;
				q.push(make_pair(0, i));
			}
		}

		//Scan the first column
		for (int i = 0; i < m; i++){
			if (board[i][0] == 'O'){
				isLive[i][0] = true;
				q.push(make_pair(i, 0));
			}
		}

		//Scan the last row
		for (int i = 0; i < n; i++){
			if (board[m - 1][i] == 'O'){
				isLive[m - 1][i] = true;
				q.push(make_pair(m - 1, i));
			}
		}

		//Scan the last column
		for (int i = 0; i < m; i++){
			if (board[i][n - 1] == 'O'){
				isLive[i][n - 1] = true;
				q.push(make_pair(i, n - 1));
			}
		}


		//Start Breadth-first search
		while (!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			//Check left neighbor
			if (x - 1>0 && board[x - 1][y] == 'O' && isLive[x - 1][y] == false){
				isLive[x - 1][y] = true;
				q.push(make_pair(x - 1, y));
			}
			//Check right neighbor
			if (x + 1 < n - 1 && board[x + 1][y] == 'O' && isLive[x + 1][y] == false){
				isLive[x + 1][y] = true;
				q.push(make_pair(x + 1, y));
			}
			//Check up neighbor
			if (y - 1 > 0 && board[x][y - 1] == 'O' && isLive[x][y - 1] == false){
				isLive[x][y - 1] = true;
				q.push(make_pair(x, y - 1));
			}
			//Check bottom neighbor
			if (y + 1 < m - 1 && board[x][y + 1] == 'O' && isLive[x][y + 1] == false){
				isLive[x][y + 1] = true;
				q.push(make_pair(x, y + 1));
			}
		}

		//Replace "dead" 'O's with 'X's
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (board[i][j] == 'O' && !isLive[i][j])
					board[i][j] = 'X';
			}
		}
		return; 
	}
};

void main(int argc, char *argv[]){
	vector<vector<char>> board = { { 'X', 'X', 'X', 'X', 'X' }, 
									{ 'X', 'X', 'O', 'O', 'X' }, 
									{ 'X', 'X', 'X', 'X', 'X' }, 
									{ 'X', 'O', 'O', 'O', 'X' }, 
									{ 'X', 'X', 'X', 'O', 'X' } };
	cout << "The original board is: " << endl;
	for (vector<char> cc : board){
		for (char c : cc)
			cout << c;
		cout << endl;
	}
	Solution s;
	s.solve(board);
	cout << "The revised board is: " << endl;
	for (vector<char> cc : board){
		for (char c : cc)
			cout << c;
		cout << endl;
	}
	system("pause");
}