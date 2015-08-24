/*
*	Contains Duplicate I
*	Last Modified: 6/3/2015
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution{
public:
	bool containsDuplicate(vector<int>& nums){
		if (nums.size() == 1)
			return false;
		else{
			sort(nums.begin(), nums.end());
			vector<int>::iterator it;
			it = unique(nums.begin(), nums.end());
			if (nums.size() != distance(nums.begin(), it))
				return true;
			return false;
		}
	}
};

void main(int argc, char *argv[]){
	bool isDuplicate[3] = { 0, 0, 0 };
	string indication[2] = { "yes", "no" };
	vector<vector<int>> nums;
	vector<int> nums1 = { 1 };
	vector<int> nums2 = { 1, 2, 3, 4, 5 };
	vector<int> nums3 = { 1, 4, 2, 3, 4 };
	nums.push_back(nums1);
	nums.push_back(nums2);
	nums.push_back(nums3);
	Solution s;
	for (int i = 0; i < 3; i++)
	{
		isDuplicate[i] = s.containsDuplicate(nums[i]);
		if (isDuplicate[i] == false)
			cout << indication[1] << endl;
		else
			cout << indication[0] << endl;
	}
	system("pause");
}

