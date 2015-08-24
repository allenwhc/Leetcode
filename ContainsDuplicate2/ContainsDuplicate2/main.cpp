/*
*	Contains Duplicate II
*	Last Modified: 6/4/2015
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k){
		if (nums.size() <= 1)
			return false;
		vector<int> preserve(nums.size());
		vector<int> index(nums.size());
		for (int i = 0; i < nums.size(); i++)
			preserve[i] = nums[i];
		vector<int>::iterator it;
		sort(nums.begin(), nums.end());
		it = adjacent_find(nums.begin(), nums.end());
		if (it != nums.end())
		{
			for (int i = 0; i < preserve.size(); i++)
			{
				if (preserve[i] == *it)
				{
					index.push_back(i);
				}
			}
			int index1 = index.back();
			index.pop_back();
			int index2 = index.back();
			if (index1 - index2 <= k)
				return true;
			else
				return false;
		}
		else
			return false;
	}
};

void main(int argc, char *argv[]){
	int k;
	Solution s;
	cout << "Input the maximum index interval k: ";
	cin >> k;
	vector<vector<int>> combinedNums;
	vector<int> nums1 = { 1, 2, 1 };
	vector<int> nums2 = { 2, 1, 3, 5, 11, 1, 4, 6 };
	vector<int> nums3 = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> nums4 = { 5, 10, 10, 8, 4, 6, 7 };
	combinedNums.push_back(nums1);
	combinedNums.push_back(nums2);
	combinedNums.push_back(nums3);
	combinedNums.push_back(nums4);
	bool isDuplicate[4] = { 0, 0, 0, 0 };
	for (int i = 0; i < 4; i++)
	{
		isDuplicate[i] = s.containsNearbyDuplicate(combinedNums[i], k);
		if (isDuplicate[i] == false)
			cout << "No nearby duplicate elements" << endl;
		else
			cout << "Contains nearby duplicate elements" << endl;
	}
	system("pause");
}