/*
*	Single Number III
*	Last Modified: 8/17/2015
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> singles;
		int n = nums.size();
		if (n == 0) return singles;
		int a = 0, b = 0;
		int m = 0;
		for (int i = 0; i < n; i++)
			m ^= nums[i];
		
		int mask = m & ~(m - 1);
		for (int element : nums){
			if ((element&mask) != 0)
				a = a ^ element;
			else
				b = b ^ element;
		}
		return { a, b };
	}
};

void main(){
	vector<int> nums = { 1, 2, 1, 3, 2, 5 };
	cout << "The array is: ";
	for (auto x : nums)
		cout << x << " ";
	cout << endl;
	Solution sol;
	cout << "The single numbers are: ";
	for (auto x : sol.singleNumber(nums))
		cout << x << " ";
	cout << endl;
	system("pause");
}