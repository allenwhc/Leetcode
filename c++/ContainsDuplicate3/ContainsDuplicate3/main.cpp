/*
*	Contains Duplicate III
*	Last Modified: 6/4/2015
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution{
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
		if (nums.size() <= 1 || k < 1 || t < 0)
			return false;
		map<long long, int> hmap;
		int j = 0;
		for (int i = 0; i < nums.size(); i++){
			if (i - j > k && hmap[nums[j]] == j)
				hmap.erase(hmap[nums[j++]]);
			auto a = hmap.lower_bound(nums[i] - t);
			if (a != hmap.end() && abs(a->first - nums[i]) <= t)
				return true;
			hmap[nums[i]] = i;
		}
		return false;
		
	}
};

void main(int argc, char *argv[]){
	int k, t;
	Solution s;
	cout << "Input the maximum index interval k: ";
	cin >> k;
	cout << "Input a difference t: ";
	cin >> t;
	vector<vector<int>> combinedNums;
	vector<int> nums1 = { 1, 3, 1 };
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
		isDuplicate[i] = s.containsNearbyAlmostDuplicate(combinedNums[i], k, t);
		if (isDuplicate[i] == false)
			cout << "No nearby duplicate elements" << endl;
		else
			cout << "Contains nearby duplicate elements" << endl;
	}
	system("pause");
}