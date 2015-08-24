/*
*	N Queens I & II
*	Last Modified: 6/30/2015
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
	//N Queens I, return all solutions
	vector<vector<string>> solveNQueens(int n){
		vector<vector<string>> allSolutions;
		vector<int> position(n, -1);
		if (n == 0 || n == 2 || n == 3) return allSolutions;
		solve(0, n, allSolutions, position);
		return allSolutions;
	}

	bool isValid(int row, int col, vector<int>& position){
		//Checks each queen's position before placing the new queen
		for (int i = 0; i < row; i++){
			//Checks if queens are in the same column or diagonals
			if (col == position[i] || abs(row - i) == abs(col - position[i])) return false;
		}
		return true;
	}

	void solve(int row, int n, vector<vector<string>>& allSols, vector<int>& position){
		if (row == n){
			vector<string> sol(n, string(n, '.'));
			for (int i = 0; i < n; i++) sol[i][position[i]] = 'Q';
			allSols.push_back(sol);
			return;
		}
		else{
			/*for (int i = 0; i < n; i++)
				cout << position[i] << " ";
			cout << endl;*/
			for (int col = 0; col < n; col++){
				//cout << "col=" << col << ", row=" << row << endl;
				if (isValid(row, col, position)){
					position[row] = col;
					solve(row + 1, n, allSols, position);
					position[row] = -1;
				}
			}
		}
	}

	//N Queens II, returns number of all distinct solutions
	int totalNQueens(int n){
		if (n == 0 || n == 2 || n == 3) return 0;
		int count = 0;
		vector<int> solution(n, -1);
		solveNum(0, n, count, solution);
		return count;
	}

	bool isValidNum(int row, int col, vector<int>& position){
		//Checks each queen's position before placing the new queen
		for (int i = 0; i < row; i++){
			//Checks if queens are in the same column or diagonals
			if (col == position[i] || abs(row - i) == abs(col - position[i])) return false;
		}
		return true;
	}

	void solveNum(int row, int n, int& count, vector<int>& position){
		if (row == n){
			count++;
			return;
		}
		else{
			for (int col = 0; col < n; col++){
				if (isValidNum(row, col, position)){
					position[row] = col;
					solveNum(row + 1, n, count, position);
					position[row] = -1;
				}
			}
		}
	}
};

void main(int argc, char *argv[]){
	int n;
	cout << "Input the number of Queens on chessboard: ";
	cin >> n;
	Solution s;
	vector<vector<string>> queens = s.solveNQueens(n);
	int num = s.totalNQueens(n);
	cout << "The number of distinct solutions of a " << n << "-queen problem is: " << num << endl;
	/*cout << "The solutions are as follows: " << endl;
	cout << "[" << endl;
	for (int i = 0; i < queens.size(); i++){
		cout << "[";
		for (int j = 0; j < queens[i].size(); j++)
		{
			cout << queens[i][j];
			if (j != queens[i].size() - 1) cout << endl;
			else cout << "]" << endl;
		}
		cout << endl;
	}
	cout << "]" << endl;*/
	system("pause");
}