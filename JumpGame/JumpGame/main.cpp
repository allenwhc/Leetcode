/*
*	Jump Game I & II
*	Last Modified: 6/29/2015
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
	//Jump Game I
	bool canJump(vector<int>& nums){
		int n = nums.size();
		if (n == 0)
			return false;
		else if (n == 1) return true;
		else{
			int m = 0;
			for (int i = 0; i < n; i++){
				if (i <= m)
					m = max(m, nums[i] + i);
				if (m >= n - 1) return true;
			}
			return false;
		}
	}

	//Jump Game II
	int jump(vector<int>& nums){
		int n = nums.size();
		if (n <= 1) return 0;
		int start = 0, end = 0, count = 0;
		while (end < n){
			count++;
			int m = INT_MIN;
			for (int i = start; i <= end; i++){
				if (nums[i] + i >= n - 1) return count;
				m = max(m, nums[i] + i);
			}
			start = end + 1;
			end = m;
		}
	}
};

void main(int argc, char *argv[]){
	vector<int> nums1 = { 2, 0 };
	vector<int> nums2 = { 3, 2, 1, 0, 4 };
	vector<int> nums = { 2, 3, 1, 1, 4 };
	Solution s;
	bool jump1 = s.canJump(nums1);
	int minJumps = s.jump(nums);
	if (jump1)
		cout << "Can jump!" << endl;
	else
		cout << "Can't jump!" << endl;
	bool jump2 = s.canJump(nums2);
	if (jump2)
		cout << "Can jump!" << endl;
	else
		cout << "Can't jump!" << endl;
	cout << "Minimum number of jumps is: " << minJumps << endl;
	system("pause");
}