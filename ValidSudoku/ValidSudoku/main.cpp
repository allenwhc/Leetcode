/*
*	Valid Sudoku
*	Last Modified: 6/23/2015
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	//Checks if a given sudoku is valid
	bool isValidSudoku(vector<vector<char>>& board){
		if (board.size() == 0) return false;
		int row[9], col[9], martix[9];
		for (int i = 0; i < 9; i++){
			memset(row, 0, 9 * sizeof(int));
			memset(col, 0, 9 * sizeof(int));
			for (int j = 0; j < 9; j++){
				//Checks row
				if (board[i][j] != '.'){
					if (row[board[i][j] - 49] == 1) return false;
					row[board[i][j] - 49]++;
				}

				//Checks column
				if (board[j][i] != '.'){
					if (col[board[j][i] - 49] == 1) return false;
					col[board[j][i] - 49]++;
				}
			}
		}

		//Checks 9x9 matrix
		for (int i = 0; i < 9; i = i + 3){
			for (int j = 0; j < 9; j = j + 3){
				memset(martix, 0, 9 * sizeof(int));
				for (int rows = 0; rows < 3; rows++){
					for (int cols = 0; cols < 3; cols++){
						if (board[rows + i][cols + j] == '.') continue;
						if (martix[board[rows + i][cols + j] - 49] == 1) return false;
						martix[board[rows + i][cols + j] - 49]++;
					}
				}
			}
		}
		return true;
	}
};

void main(int argc, char* argv[]){
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
	Solution s;
	bool valid = s.isValidSudoku(board);
	cout << "The given sudoku is ";
	if (valid) cout << "valid" << endl;
	else cout << "not valid" << endl;
	system("pause");
}