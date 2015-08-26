/*
*	Product of Array Except Self
*	Last Modified: 7/17/2015
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		vector<int> product(n, 1);
		int temp = 1;
		//Calculate the product of left part
		for (int i = 1; i < n; i++)
			product[i] = product[i - 1] * nums[i - 1]; 

		for (int i = n - 1; i >= 0; i--){
			product[i] *= temp;
			temp *= nums[i];
		}
		return product;
	}
};

void main(int argc, char *argv[]){
	vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 3, 0, -2, 4 }, { -4, 2, 3, 5 }, { 2, -1, 3, -2 } };
	Solution s;
	int n = nums.size();
	vector<vector<int>> res(n);
	for (int i = 0; i < n; i++)
		res[i] = s.productExceptSelf(nums[i]);
	for (int i = 0; i < n; i++){
		cout << "The result of product except self in ";
		for (int k = 0; k < res[i].size(); k++)
			cout << nums[i][k] << " ";
		cout << "is: ";
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
}