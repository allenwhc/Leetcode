/*
*	Minimum Sum of Triangle
*	Last Modified: 6/1/2015
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
	int minimumTotal(vector<vector<int>> &triangle){
		//If the triangle has only one element
		if (triangle.size() == 1 && triangle[0].size() == 1)
			return triangle[0].back();
		int rows = triangle.size();
		cout <<"The number of rows in the triangle: "<< rows << endl;
		vector<int> minSum(triangle[rows - 1].size());
		for (int i = rows - 1; i >= 0; i--)
		{
			int cols = triangle[i].size();
			for (int j = 0; j < cols; j++)
			{
				if (i == rows - 1)	//If reaches the last row
				{
					minSum[j] = triangle[i][j];
					continue;
				}
				minSum[j] = min(minSum[j], minSum[j + 1]) + triangle[i][j];
			}
		}
		return minSum[0];
	}
};

void main(int argc, char*argv[]){
	vector<vector<int>> triangle = {
		{ -1 },
		{ 2, 3 },
		{ 1, -1, -3}
	};
	int minimumTotal = 0;
	Solution s;
	minimumTotal = s.minimumTotal(triangle);
	cout << "The minimum total of the triangle is: " << minimumTotal << endl;
	system("pause");
}