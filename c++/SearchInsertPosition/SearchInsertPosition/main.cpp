/*
*	Search Insert Position
*	Last Modified: 6/10/2015
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int searchInsert(vector<int>& nums, int target){
		int n = nums.size();
		if (n == 0)
			return 0;
		else if (n == 1){
			if (target <= nums.back())
				return 0;
			else return 1;
		}
		else{
			if (target > nums[n - 1]) return n;
			else if (target <= nums[0]) return 0;
			else{
				int start = 0;
				int end = n - 1;
				int middle = 0;
				while (start <= end){
					middle = start + (end - start) / 2;
					if (target == nums[middle]) return middle;
					else if (target > nums[middle])
						start = middle + 1;
					else
						end = middle - 1;
				}
			}
		}
	}
};

void main(int argc, char *argv[]){
	int target;
	cout << "Input a target number: ";
	cin >> target;
	vector<int> nums = { 1, 3 };
	Solution s;
	int index = s.searchInsert(nums, target);
	cout << "The index that " << target << " should be inserted in is: " << index << endl;
	system("pause");
}