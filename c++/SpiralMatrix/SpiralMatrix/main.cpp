/*
*	Spiral Matrix I & II
*	Last Modified: 6/22/2015
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
	//Spiral Matrix I: returns all elements in spiral order
	vector<int> spiralOrder(vector<vector<int>>& matrix){
		vector<int> spiral;
		int m = matrix.size();
		if (m == 0) return spiral;
		int n = matrix[0].size();
		int top = 0;
		int down = m - 1;
		int left = 0;
		int right = n - 1;

		while (true){
			//First row
			for (int i = left; i <= right; i++)
				spiral.push_back(matrix[top][i]);
			top++;
			if (top > down || left > right) break;

			//Last column
			for (int i = top; i <= down; i++)
				spiral.push_back(matrix[i][right]);
			right--;
			if (top > down || left > right) break;

			//Last row
			for (int i = right; i >= left; i--)
				spiral.push_back(matrix[down][i]);
			down--;
			if (top > down || left > right) break;

			//First column
			for (int i = down; i >= top; i--)
				spiral.push_back(matrix[i][left]);
			left++;
			if (top > down || left > right) break;
		}
		return spiral;
	}

	//Spiral Matrix II: generate square matrix in spiral order
	vector<vector<int>> generateMatrix(int n){
		vector<vector<int>> spiralMatrix(n,vector<int>(n));
		if (n == 0) return spiralMatrix;
		else if (n == 1){
			spiralMatrix[0][0] = 1;
			return spiralMatrix;
		}
		else{
			int top = 0;
			int down = n - 1;
			int left = 0;
			int right = n - 1;
			int stopFirstRow = 1, stopLastColumn = 1, stopLastRow = 1, StopFirstColumn = 1;
			while (true){
				//Fills the first row
				for (int i = left; i <= right; i++)
					spiralMatrix[top][i] = StopFirstColumn + i - left;
				stopFirstRow = spiralMatrix[top][right] + 1;
				cout << "SFR: " << stopFirstRow << endl;
				top++;
				if (top > down || left > right) break;

				//Fills the last column
				for (int i = top; i <= down; i++)
					spiralMatrix[i][right] = stopFirstRow + i - top;
				stopLastColumn = spiralMatrix[down][right] + 1;
				cout << "SLC: " << stopLastColumn << endl;
				right--;
				if (top > down || left > right) break;

				//Fills the last row
				for (int i = right; i >= left; i--)
					spiralMatrix[down][i] = stopLastColumn - i + right;
				stopLastRow = spiralMatrix[down][left] + 1;
				cout << "SLR: " << stopLastRow << endl;
				down--;
				if (top > down || left > right) break;

				//Fills the first column
				for (int i = down; i >= top; i--)
					spiralMatrix[i][left] = stopLastRow - i + down;
				StopFirstColumn = spiralMatrix[top][left] + 1;
				cout << "SFC: " << StopFirstColumn << endl;
				left++;
				if (top > down || left > right) break;
			}
			return spiralMatrix;
		}
	}
};

void main(int argc, char *argv[]){
	vector<vector<int>> matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	//vector<vector<int>> matrix = { { 1 }, { 2 }, { 3 } };
	Solution s;
	vector<int> spiral = s.spiralOrder(matrix);
	cout << "Spiral Matrix I" << endl;
	cout << "The spiral order of elements in the matrix is: [";
	for (int i = 0; i < spiral.size(); i++){
		cout << spiral[i];
		if (i != spiral.size() - 1) cout << ",";
	}
	cout << "]" << endl;

	cout << endl << "Spiral Matrix II: " << endl;
	int n = 1;
	vector<vector<int>> result = s.generateMatrix(n);
	cout << "The " << n << "-level matrix in spiral order is: " << endl;
	cout << "[" << endl;
	for (int i = 0; i < result.size(); i++){
		cout << "[";
		for (int j = 0; j < result[i].size(); j++){
			cout << result[i][j];
			if (j != result[i].size() - 1) cout << ",";
		}
		cout << "]";
		if (i != result.size() - 1) cout << ",";
		cout << endl;
	}
	cout << "]" << endl;
	system("pause");
}