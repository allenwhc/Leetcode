/*
*	Find Minimum in Rotated Sorted Array I & II
*	Last Modified: 7/2/2015
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
	//Find Minimum in Rotated Sorted Array I, no duplicates in the array
	int findMin(vector<int>& nums){
		if (nums.size() == 0) return 0;
		else if (nums.size() == 1)
			return nums.back();
		else
		{
			sort(nums.begin(), nums.end());
		}
		return nums[0];
	}

	//Find Minimum in Rotated Sorted Array II, with duplicates in the array
	int findMin2(vector<int>& nums){
		int n = nums.size();
		if (n == 0) return 0;
		else if (n == 1) return nums.back();
		else if (n == 2) return min(nums[0], nums[1]);
		else{
			int start = 0, end = n - 1;
			while (start < end){
				int middle = (start + end) / 2;
				if (nums[start] < nums[end]) return nums[start];
				if (nums[middle] == nums[start]) start++;
				else if (nums[middle] > nums[start]) start = middle;
				else end = middle;
			}
			return min(nums[start], nums[end]);
		}
	}
};

void main(int argc, char* argv[]){
	Solution s;
	vector<int> nums = { 3, 8, 2, 4, 10, 6, 7 };
	cout << "Find Minimum in Rotated Sorted Array I (No duplicates): " << endl;
	cout << "The sorted array is: ";
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i];
		if (i < nums.size() - 1)
			cout << ",";
	}
	srand(time(NULL));
	int pivot = rand() % nums.size();	//Generates a random pivot between 0 and nums.size() - 1;
	vector<int> rotatedNums(nums.size());
	if (pivot != 0)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			if (i < nums.size() - pivot)
				rotatedNums[i] = nums[i + pivot];
			else
				rotatedNums[i] = nums[i - nums.size() + pivot];
		}
	}
	else
	{
		for (int i = 0; i < nums.size(); i++)
		{
			rotatedNums[i] = nums[i];
		}
	}
	cout << endl;
	cout << "The rotated sorted array is: ";
	for (int i = 0; i < rotatedNums.size(); i++)
	{
		cout << rotatedNums[i];
		if (i < rotatedNums.size() - 1)
			cout << ",";
	}
	cout << endl;
	int minimum;
	minimum = s.findMin(rotatedNums);
	cout << "The minimum number in the rotated sorted array is: " << minimum << endl;

	//Find Minimum in Rotated Sorted Array II
	cout << endl;
	cout << "Find Minimum in Rotated Sorted Array II (with duplicates): " << endl;
	vector<int> nums2 = { 1, 1, 3 };
	cout << "The sorted array is: ";
	for (int i = 0; i < nums2.size(); i++)
	{
		cout << nums2[i];
		if (i < nums2.size() - 1)
			cout << ",";
	}
	vector<int> rotatedNums2(nums2.size());
	int pivot2 = rand() % nums2.size();
	if (pivot2 != 0)
	{
		for (int i = 0; i < nums2.size(); i++)
		{
			if (i < nums2.size() - pivot2)
				rotatedNums2[i] = nums2[i + pivot2];
			else
				rotatedNums2[i] = nums2[i - nums2.size() + pivot2];
		}
	}
	else
	{
		for (int i = 0; i < nums2.size(); i++)
		{
			rotatedNums2[i] = nums2[i];
		}
	}
	cout << endl;
	cout << "The rotated sorted array is: ";
	for (int i = 0; i < rotatedNums2.size(); i++)
	{
		cout << rotatedNums2[i];
		if (i < rotatedNums2.size() - 1)
			cout << ",";
	}
	cout << endl;
	int minimum2;
	minimum2 = s.findMin2(rotatedNums2);
	cout << "The minimum number in the rotated sorted array is: " << minimum2 << endl;
	system("pause");
}