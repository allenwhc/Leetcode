/*
*	kth Largest Element in An Array
*	Last Modified: 6/15/2015
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
	int findKthLargest(vector<int>& nums, int k){
		int n = nums.size();
		if (n <= 1) return nums.back();
		else{
			sort(nums.begin(), nums.end());
			return nums[n - k];
		}
	}
};

void main(int argc, char *argv[]){
	vector<int> nums = { 3, 2, 1, 5, 6, 4 };
	int k = 2;
	Solution s;
	int kthLargest = s.findKthLargest(nums, k);
	cout << "The " << k << "st/nd/rd/th largest elemnent in the array is: " << kthLargest << endl;
	system("pause");
}