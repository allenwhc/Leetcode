/*
*	Sudoku Solver
*	Last Modified: 6/24/2015
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	void solveSudoku(vector<vector<char>>& board){
		if (board.size() == 0) return;
		isSolved(board);
	}
private:
	bool isSolved(vector<vector<char>>& board){
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				if (board[i][j] == '.'){
					for (char num = '1'; num <= '9'; num++){
						if (isValid(board, i, j, num)){
							board[i][j] = num;
							if (isSolved(board)) return true;
							else board[i][j] = '.';
						}
					}
					return false;
				}
			}
		}
		return true;
	}
	
	bool isValid(vector<vector<char>>& board, int& i, int& j, char& c){
		for (int row = 0; row < 9; row++){
			if (board[row][j] == c) return false;
		}
		for (int col = 0; col < 9; col++){
			if (board[i][col] == c) return false;
		}
		for (int row = i / 3 * 3; row < i / 3 * 3 + 3; row++){
			for (int col = j / 3 * 3; col < j / 3 * 3 + 3; col++){
				if (board[row][col] == c) return false;
			}
		}
		return true;
	}
};

void main(int argc, char *argv[]){
	vector<vector<char>> board = {
		{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
		{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
		{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
		{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
		{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
		{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
		{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
		{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
		{ '.', '.', '.', '.', '8', '.', '.', '7', '9' } };
	cout << "The given unsolved Sudoku is: " << endl;
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
	Solution s;
	s.solveSudoku(board);
	cout << "A solution of the given partially filled Sudoku is: " << endl;
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
	system("pause");
}