#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int m, int n, int i, int j){
	if(i<0 || i>=m || j<0 || j>=n || visited[i][j] || board[i][j] == '.') return;
	visited[i][j] = true;
	dfs(board,visited,m,n,i-1,j);
	dfs(board,visited,m,n,i+1,j);
	dfs(board,visited,m,n,i,j-1);
	dfs(board,visited,m,n,i,j+1);
}

int countBattleships(vector<vector<char>>& board){
	if(board.empty() || board[0].empty()) return 0;
	int m = board.size(), n = board[0].size();
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	int res = 0;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(board[i][j] == 'X' && !visited[i][j]){
				res ++;
				dfs(board, visited, m, n, i, j);
			}
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	vector<vector<char>> board = {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};
	cout << countBattleships(board) << endl;
	return 0;
}