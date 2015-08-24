/*
*	Find Peak Elements
*	Last Modified: 6/9/2015
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution{
public:
	int findPeakElement(vector<int>& nums){
		int n = nums.size();
		if (n <= 1)
			return 0;
		else if (n == 2)
		{
			if (nums[0] > nums[1])
				return 0;
			if (nums[1] > nums[0])
				return 1;
		}
		else{
			int start = 0;
			int end = n - 1;
			int middle = 0;
			while (start <= end){
				middle = (end - start) / 2 + start;
				if ((middle == 0 || nums[middle] > nums[middle - 1]) && (middle == n - 1 || nums[middle] > nums[middle + 1]))
					return middle;
				else if (nums[middle] < nums[middle - 1])
				{
					end = middle - 1;
				}
				else if (nums[middle < nums[middle + 1]])
				{
					start = middle + 1;
				}
			}
			return middle;
		}
	}
};

void main(int argc, char *argv[]){
	vector<int> nums = { 3, 2, 1 };
	int peak = 0;
	Solution s;
	peak = s.findPeakElement(nums);
	cout << "The index of the peak element is: " << peak << endl;
	system("pause");
}