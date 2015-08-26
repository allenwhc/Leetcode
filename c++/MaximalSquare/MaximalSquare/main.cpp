/*
*	Maximal Square
*	Last Modified: 7/6/2015
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
	int maximalSquare(vector<vector<char>>& matrix){
		if (matrix.empty()) return 0;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int>> square(m, vector<int>(n));
		for (int i = 0; i < m; i++)
			square[i][0] = matrix[i][0] - '0';
		for (int i = 0; i < n; i++)
			square[0][i] = matrix[0][i] - '0';
		for (int i = 1; i < m; i++){
			for (int j = 1; j < n; j++){
				if (matrix[i][j] == '0') square[i][j] = 0;
				else{
					//square[i][j]=min(square[i-1][j], square[i][j-1], square[i-1][j-1]) + 1
					int min1 = min(square[i - 1][j], square[i][j - 1]);	
					int min2 = min(min1, square[i - 1][j - 1]);
					square[i][j] = min2 + 1;
				}
			}
		}
		//Finds the maximum square in square[][]
		int maximum = INT_MIN;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++)
				maximum = max(maximum, square[i][j]);
		}
		return maximum*maximum;
	}
};

void main(int argc, char* argv[]){
	/*vector<vector<char>> matrix = { { '0', '1', '1', '1', '0' },
									{ '0', '1', '1', '1', '1' },
									{ '0', '1', '1', '1', '1' },
									{ '0', '0', '0', '1', '0' } };*/
	vector<vector<char>> matrix = {};
	Solution s;
	cout << "The area of a maximal all '1's square is: " << s.maximalSquare(matrix) << endl;
	system("pause");
}