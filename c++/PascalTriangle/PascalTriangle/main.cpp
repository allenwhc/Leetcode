/*
*	Pascal's Triangle I & II
*	Last Modified: 6/9/2015
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	//Return all rows in Pascal's Triangle
	vector<vector<int>> generate1(int numRows){
		vector<vector<int>> triangle(numRows, vector<int>(numRows, 0));
		if (numRows <= 0)
			return triangle;
		else{
			for (int i = 0; i < numRows; i++)
				triangle[i].resize(i + 1);
			if (numRows == 1){
				triangle[0][0] = 1;
				return triangle;
			}
			else if (numRows == 2){
				triangle[0][0] = 1;
				triangle[1][0] = triangle[1][1] = 1;
				return triangle;
			}
			else{
				triangle[0][0] = 1;
				triangle[1][0] = triangle[1][1] = 1;
				for (int i = 2; i < numRows; i++)
				{
					triangle[i][0] = 1;
					triangle[i][i] = 1;
					for (int j = 1; j < i; j++){
						triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
					}
				}
				return triangle;
			}
		}
		
	}

	//Return a particular row in Pascal's Triangle
	vector<int> generate2(int rowIndex){
		vector<int> rowOfPascal(rowIndex + 2);
		for (int i = 0; i < rowOfPascal.size(); i++)
			rowOfPascal[i] = 0;
		rowOfPascal[1] = 1;
		for (int i = 0; i < rowIndex; i++){
			for (int j = rowIndex + 1; j > 0; j--)
				rowOfPascal[j] = rowOfPascal[j] + rowOfPascal[j - 1];
		}
		rowOfPascal.erase(rowOfPascal.begin(), rowOfPascal.begin() + 1);
		return rowOfPascal;
	}
};

void main(int argc, char *argv[]){
	int numRows, rowIndex;
	Solution s;
	cout << "Input the number of rows in Pascal's Triangle: ";
	cin >> numRows;
	vector<vector<int>> pascalTriangle = s.generate1(numRows);
	cout << "The " << numRows << "-row Pascal's Triangle is: " << endl;
	for (int i = 0; i < pascalTriangle.size(); i++){
		for (int j = 0; j < pascalTriangle[i].size(); j++)
		{
			cout << pascalTriangle[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Input the row index you want in Pascal's Triangle: ";
	cin >> rowIndex;
	vector<int> row = s.generate2(rowIndex);
	cout << "The " << rowIndex << " st/nd/rd/th row of Pascal's Triangle is: " << endl;
	for (int i = 0; i < row.size(); i++)
		cout << row[i] << " ";
	cout << endl;
	system("pause");
}