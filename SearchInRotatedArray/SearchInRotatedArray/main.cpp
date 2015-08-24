/*
*	Search in Rotated Sorted Array I & II 
*	Last Modified: 7/1/2015
*/

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class Solution{
public:
	//Search in Rotated Sorted I, returns the index in the rotated array of a target integer
	int search(vector<int>& nums, int target){
		int n = nums.size();
		if (n == 0) return -1;
		else{
			int start = 0;
			int end = n - 1;
			while (start <= end){
				int middle = start + (end - start) / 2;
				if (nums[middle] == target) return middle;
				else if (nums[middle] >= nums[start]){
					if (target < nums[middle] && target >= nums[start]) end = middle - 1;
					else start = middle + 1;
				}
				else{
					if (target > nums[middle] && target <= nums[end]) start = middle + 1;
					else end = middle - 1;
				}
			}
			return  -1;
		}
	}

	//Search in Rotated Sorted Array II, determines if the target integer is in the array
	bool isExist(vector<int>& nums, int target){
		int n = nums.size();
		if (n == 0) return false;
		int start = 0, end = n - 1;
		while (start <= end){
			int middle = (start + end) / 2;
			if (nums[middle] == target) return true;
			else{
				if (nums[middle] == nums[start]) start++;
				else if (nums[middle] > nums[start]){
					if (target >= nums[start] && target < nums[middle]) end = middle - 1;
					else start = middle + 1;
				}
				else{
					if (target <= nums[end] && target > nums[middle]) start = middle + 1;
					else end = middle - 1;
				}
			}
		}
		return false;
	}
};

void main(int argc, char *argv[]){
	vector<int> nums = {  4 };
	vector<int> rotated1(nums.size());
	cout << "Search in rotated sorted array I: " << endl;
	cout << "The original sorted array is: ";
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
	int target = 4;
	srand(time(NULL));
	int pivot1 = rand() % nums.size();
	Solution s;
	if (pivot1 != 0){
		for (int i = 0; i < nums.size() - pivot1; i++)
			rotated1[i] = nums[i + pivot1];
		for (int i = nums.size() - pivot1; i < nums.size(); i++)
			rotated1[i] = nums[i - nums.size() + pivot1];
	}
	else{
		for (int i = 0; i < nums.size(); i++)
			rotated1[i] = nums[i];
	}
	cout << "The input randomly-pivot rotated array is: ";
	for (int i = 0; i < nums.size(); i++)
		cout << rotated1[i] << " ";
	cout << endl;
	int index = s.search(rotated1, target);
	cout << "The index of " << target << " in the rotated array is: " << index << endl;

	vector<int> nums2 = { 1, 3, 1, 1, 1 };
	vector<int> rotated2(nums2.size());
	int pivot2 = rand() % nums2.size();
	int target2 = 3;
	cout << endl << "Search in rotated sorted array II: " << endl;
	cout << "The original sorted array with duplicates is: ";
	for (int i = 0; i < nums2.size(); i++)
		cout << nums2[i] << " ";
	cout << endl << "The randomly-pivot rotated array is: ";
	if (pivot2 != 0){
		for (int i = 0; i < nums2.size() - pivot2; i++)
			rotated2[i] = nums2[i + pivot2];
		for (int i = nums2.size() - pivot2; i < nums2.size(); i++)
			rotated2[i] = nums2[i - nums2.size() + pivot2];
	}
	else{
		for (int i = 0; i < nums2.size(); i++)
			rotated2[i] = nums2[i];
	}
	for (int i = 0; i < rotated2.size(); i++)
		cout << rotated2[i] << " "; 
	cout << endl;
	bool isExist = s.isExist(rotated2, target2);
	if (isExist) cout << target2 << " is in the array" << endl;
	else cout << target2 << " is not in the array" << endl;
	system("pause");
}