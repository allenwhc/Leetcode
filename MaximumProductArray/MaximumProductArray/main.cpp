/*
*	Maximum Product Array
*	Last Modified: 6/19/2015
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
	int maxProduct(vector<int>& nums){
		int n = nums.size();
		int localMax = nums[0], localMin = nums[0], globalMax = nums[0];
		for (int i = 1; i < n; i++){
			int temp = localMax;
			localMax = max(max(nums[i], localMax*nums[i]), nums[i] * localMin);
			localMin = min(min(nums[i], temp*nums[i]), nums[i] * localMin);
			globalMax = max(globalMax, localMax);
		}
		return globalMax;
	}
};

void main(int argc, char *argv[]){
	vector<int> nums = { 2, -3, -2, -4 };
	Solution s;
	int maxProduct = s.maxProduct(nums);
	cout << "The maximum product of a subarray is: " << maxProduct << endl;
	system("pause");
}