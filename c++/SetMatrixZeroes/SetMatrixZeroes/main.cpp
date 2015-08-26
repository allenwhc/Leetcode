/*
*	Set Matrix Zeroes
*	Last Modified: 6/5/2015
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
	void setZeroes(vector<vector<int>>& matrix){
		int rows = matrix.size();
		int cols = matrix[0].size();
		cout << "rows: " << rows << ", cols: " << cols << endl;
		bool isZeroRow = false, isZeroCol = false;
		//Determines if there exists 0 in the first row or the first column
		//First column
		if (rows == 1)
		{
			if (cols != 1)
			{
				for (int i = 0; i < cols; i++)
				{
					if (matrix[0][i] == 0)
					{
						isZeroCol = true;
						break;
					}
				}
				if (isZeroCol)
				{
					for (int i = 0; i < cols; i++)
						matrix[0][i] = 0;
				}
			}//end if
		}//end if
		if (cols == 1)
		{
			if (rows != 1)
			{
				for (int i = 0; i < rows; i++)
				{
					if (matrix[i][0] == 0)
					{
						isZeroRow = true;
						break;
					}
				}
				if (isZeroRow)
				{
					for (int i = 0; i < rows; i++)
						matrix[i][0] = 0;
				}
			}//end if
		}//end if
		else
		{
			for (int i = 0; i < rows; i++)
			{
				if (matrix[i][0] == 0)
					isZeroCol = true;
			}
			//First row
			for (int i = 0; i < cols; i++)
			{
				if (matrix[0][i] == 0)
					isZeroRow = true;
			}

			//Scans the matrix from the second row and the second column, if finds zero, set that row and column to be 0
			for (int i = 1; i < rows; i++)
			{
				for (int j = 1; j < cols; j++)
				{
					if (matrix[i][j] == 0)
					{
						matrix[0][j] = 0;
						matrix[i][0] = 0;	//If finds zero at (i,j), then sets the corresponding element in the first row and the first column to be 0 (false)
					}
				}
			}

			//Set zeroes to those columns and rows marked 0
			for (int i = 1; i < rows; i++)
			{
				for (int j = 1; j < cols; j++)
				{
					if (matrix[i][0] == 0 || matrix[0][j] == 0)
						matrix[i][j] = 0;
				}
			}

			//Checks if zero exists in the first column and the first row
			if (isZeroRow)
			{
				for (int i = 0; i < cols; i++)
					matrix[0][i] = 0;
			}
			if (isZeroCol)
			{
				for (int i = 0; i < rows; i++)
					matrix[i][0] = 0;
			}
		} //end else
	}
};

void main(int argc, char *argv[]){
	vector<vector<int>> matrix0 = { { -1 }, { 2 }, { 3 } };
	vector<vector<int>> matrix1 = { { 1, -1, 3 },
									{ 2, 0, 5 },
									{ 3, 2, 6 } };
	vector<vector<int>> matrix2 = { { 1, -5, 3 },
									{ 2, 7, 5 },
									{ 0, 0, -3 } };
	vector<vector<int>> matrix3 = { { 11, 5, -3 },
									{ 2, 7, 25 },
									{ 6, -2, -13 } };
	Solution s;
	s.setZeroes(matrix0);
	cout << "Matrix0 after set zeroes: " << endl;
	cout << "[";
	for (int i = 0; i < matrix0.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < matrix0[i].size(); j++)
		{
			cout << matrix0[i][j];
			if (j != matrix0[i].size() - 1)
				cout << ",";
		}
		cout << "]";
		if (i != matrix0.size() - 1)
			cout << "," << endl;
	}
	cout << "]" << endl;

	s.setZeroes(matrix1);
	cout << "Matrix1 after set zeroes: " << endl;
	cout << "[";
	for (int i = 0; i < matrix1.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < matrix1[i].size(); j++)
		{
			cout << matrix1[i][j];
			if (j != matrix1[i].size() - 1)
				cout << ",";
		}
		cout << "]";
		if (i != matrix1.size() - 1)
			cout << "," << endl;
	}
	cout << "]" << endl;

	s.setZeroes(matrix2);
	cout << "Matrix2 after set zeroes: " << endl;
	cout << "[";
	for (int i = 0; i < matrix2.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < matrix2[i].size(); j++)
		{
			cout << matrix2[i][j];
			if (j != matrix2[i].size() - 1)
				cout << ",";
		}
		cout << "]";
		if (i != matrix2.size() - 1)
			cout << "," << endl;
	}
	cout << "]" << endl;

	s.setZeroes(matrix3);
	cout << "Matrix3 after set zeroes: " << endl;
	cout << "[";
	for (int i = 0; i < matrix3.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < matrix3[i].size(); j++)
		{
			cout << matrix3[i][j];
			if (j != matrix3[i].size() - 1)
				cout << ",";
		}
		cout << "]";
		if (i != matrix3.size() - 1)
			cout << "," << endl;
	}
	cout << "]" << endl;
	system("pause");
}