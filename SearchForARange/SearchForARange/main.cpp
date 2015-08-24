/*
*	Search for A Range
*	Last Modified: 6/11/2015
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	vector<int> searchRange(vector<int> &nums, int target){
		vector<int> index = { -1, -1 };
		int n = nums.size();
		int start = 0;
		int end = n - 1;
		while (start < end){
			int middle = start + (end - start) / 2;
			if (nums[middle] < target){
				start = middle + 1;
				continue;
			}
			end = middle;
		}
		int lowerBound = nums[start] == target ? start : -1;
		if (lowerBound == -1)
		{
			return index;
		}
		else{
			start = lowerBound;
			end = n;
			while (start < end){
				int middle = (start + end) / 2;
				if (nums[middle] > target){
					end = middle;
					continue;
				}
				start = middle + 1;
			}
			int upperBound = start - 1;
			index.clear();
			index.push_back(lowerBound);
			index.push_back(upperBound);
			return index;
		}
	}
};

void main(int argc, char *argv[]){
	vector<int> nums = { 5, 7, 7, 8, 8, 10 };
	//vector<int> nums = { 1 };
	int target = 8;
	Solution s;
	vector<int> indexRange = s.searchRange(nums, target);
	cout << "The index range for " << target << " is:" << indexRange[0] << " , " << indexRange[1] << endl;
	system("pause");
}