/*
*	Search a 2D Matrix I & II
*	Last Modified: 7/22/2015
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
	//Search Matrix I
	bool searchMatrix1(vector<vector<int>>& matrix, int target){
		int rows = matrix.size();
		int cols = matrix[0].size();
		int i = 0;
		if (rows == 1 && cols == 1)
		{
			if (target == matrix[0].back())
				return true;
			else
				return false;
		}	//end if
		else
		{
			vector<int>::iterator it;
			while (i < rows)
			{
				if (target < matrix[i].back())
				{
					it = find(matrix[i].begin(), matrix[i].end(), target);
					if (it != matrix[i].end())
						return true;
					else
						return false;
				}
				else if (target == matrix[i].back())
					return true;
				else
					i++;
			}	//end while
			return false;
		}	//end else
		
	}

	//Search Matrix II
	bool searchMatrix2(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if (m == 0) return false;
		int n = matrix[0].size();
		if (n == 0) return false;

		int i = 0, j = n - 1;	//First start from the top right element
		while (i < m && j >= 0){
			if (matrix[i][j] == target) return true;	//If the current element equals to target, found, return true
			else if (matrix[i][j] > target) j--;	//If the current element is less than target, move to left
			else i++; // If the current element is greater than target, move down
		}
		return false;
	}
};

void main(int argc, char *argv[]){
	bool isSearched;
	Solution s;
	cout << "Search a 2D matrix I: " << endl;
	vector<vector<int>> matrix = { { 1, 3, 5, 7 }, 
								   { 10, 11, 16, 20 }, 
								   { 23, 30, 34, 50 } };
	int target = 8;
	isSearched = s.searchMatrix1(matrix, target);
	if (isSearched)
		cout << target << " is in the matrix." << endl;
	else
		cout << target << " is not in the matrix" << endl;


	cout << endl << "Search a 2D matrix II: " << endl;
	vector<vector<int>> matrix2 = { { 1, 4, 7, 11, 15 },
									{ 2, 5, 8, 12, 19 },
									{ 3, 6, 9, 16, 22 },
									{ 10, 13, 14, 17, 24 },
									{ 18, 21, 23, 26, 30 } };
	cout << "The matrix is: " << endl;
	for (vector<int> m : matrix2){
		for (int mm : m)
			cout << mm << " ";
		cout << endl;
	}
	int target2 = 14;
	bool res = s.searchMatrix2(matrix2, target2);
	if (res) cout << target2 << " is in the matrix." << endl;
	else cout << target2 << " is not in the matrix." << endl;
	system("pause");
}