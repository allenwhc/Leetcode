/*
*	Remove Element
*	Last Modified: 6/23/2015
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int removeElement(vector<int>& nums, int val){
		int n = nums.size();
		int current = 0;
		for (int i = 0; i < n; i++){
			if (nums[i] == val) continue;
			nums[current] = nums[i];
			current++;
		}
		return current;
	}
};

void main(int argc, char *argv[]){
	vector<int> nums = { 4, 5 };
	int val = 4;
	Solution s;
	int length = s.removeElement(nums, val);
	cout << "Length of original array: " << nums.size() << endl;
	cout << "Length of outcomed array after deleting " << val << ":" << length << endl;
	system("pause");
}