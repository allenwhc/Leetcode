/*
*	Rotate Image
*	Last Modified: 7/2/2015
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	void rotate(vector<vector<int>>& matrix){
		int n = matrix.size();
		if (n <= 1) return;

		//First, transposes the matrix
		for (int row = 0; row < n; row++){
			for (int col = row; col < n; col++)
			{
				int temp = matrix[row][col];
				matrix[row][col] = matrix[col][row];
				matrix[col][row] = temp;
			}
		}
		
		//Then, reverses each row
		for (int row = 0; row < n; row++){
			for (int col = 0; col < n / 2; col++){
				int temp = matrix[row][col];
				matrix[row][col] = matrix[row][n - 1 - col];
				matrix[row][n - 1 - col] = temp;
			}
		}
	}
};

void main(int argc, char* argv[]){
	cout << "Input the dimesion of the matrix: ";
	int n;
	cin >> n; 
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) matrix[0][i] = i + 1;
	for (int i = 1; i < n; i++){
		int start = matrix[i - 1][n - 1] + 1;
		for (int j = 0; j < n; j++){
			matrix[i][j] = start + j;
		}
	}
	cout << "The input image is: " << endl;
	for (int i = 0; i < matrix.size(); i++){
		for (int j = 0; j < matrix[i].size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	Solution s;
	s.rotate(matrix);
	cout << "The 90-degree clockwise rotated image is: " << endl;
	for (int i = 0; i < matrix.size(); i++){
		for (int j = 0; j < matrix[i].size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	system("pause");
}