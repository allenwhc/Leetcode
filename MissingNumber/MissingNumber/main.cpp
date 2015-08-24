/*
*	Missing Number
*	Last Modified: 8/24/2015
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return -1;
		int sum = n*(n + 1) / 2;
		int num = 0;
		int sub;
		for (int i = 0; i < n; i++)
			sum -= nums[i];
		return sum;
	}

};

void main(){
	vector<int> nums = { 3, 6, 4, 7, 1, 8, 5, 2 };
	cout << "The missing number in ";
	for (int x : nums)
		cout << x << ",";
	Solution sol;
	cout << " is: " << sol.missingNumber(nums) << endl;
	system("pause");
}