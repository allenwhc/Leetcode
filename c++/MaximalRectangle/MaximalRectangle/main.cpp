/*
*	Maximal Rectangle
*	Last Modified: 7/28/2015
*/

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int row = matrix.size();
		if (row == 0) return 0;
		int col = matrix[0].size();
		if (col == 0) return 0;
		vector<vector<int>> helper(row, vector<int>(col));
		//vector<vector<int>> area(row, vector<int>(col));

		//Initialize the first column
		for (int i = 0; i < row; i++)
			if (matrix[i][0] == '1')
				helper[i][0] = 1;

		//Count continuous '1's in matrix
		for (int i = 0; i < row; i++){
			for (int j = 1; j < col; j++){
				if (matrix[i][j] == '1'){
					helper[i][j] = helper[i][j - 1] + 1;
				}
			}
		}

		//Compute rectangle area
		int maxRect = 0;
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				if (helper[i][j] != 0){
					int k = i - 1;
					int temp = helper[i][j];
					int minimum = helper[i][j];
					while (k >= 0){
						if (helper[k][j] == 0)
							break;
						else{
							minimum = min(minimum, helper[k][j]);	//Get the smaller length
							temp = max(temp, minimum*(i - k + 1));	//Compute the area
							k--;
						}
					}
					//area[i][j] = temp;
					maxRect = max(maxRect, temp);
				}
			}
		}
		/*for (vector<int> s : area)
		{
			for (int ss : s)
				cout << ss << " ";
			cout << endl;
		}*/
		return maxRect;
	}
};

void main(int argc, char *argv[]){
	vector<vector<char>> matrix = {
		{ '0', '1', '1', '0', '1' },
		{ '1', '1', '1', '1', '0' },
		{ '0', '1', '1', '1', '0' },
		{ '1', '1', '1', '0', '0' },
		{ '1', '0', '0', '1', '1' },
		{ '0', '1', '1', '1', '0' } };
	cout << "The matrix is" << endl;
	for (vector<char> mm : matrix){
		for (char m : mm)
			cout << m << " ";
		cout << endl;
	}
	Solution sol;
	cout << "The area of maximal rectangle is: " << sol.maximalRectangle(matrix) << endl;
	system("pause");
}