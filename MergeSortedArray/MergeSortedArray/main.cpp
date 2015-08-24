/*
*	Merge Sorted Array
*	Last Modified: 7/26/2015
*/

#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (n == 0) return;
		//1. Move m elements in nums1 to its end
		int j = nums1.size() - 1;
		for (int i = m - 1; i >= 0; i--){
			nums1[j] = nums1[i];
			j--;
		}

		//2. Start from the jth element in nums1, and 0th in nums2
		int i = j + 1;	//Index for nums1;
		int k = 0;	//Index for the merged array
		j = 0;	//Index for nums2;
		while (k < (m + n)){
			if ((j == n) || (i < (m + n) && nums1[i] <= nums2[j])){
				nums1[k] = nums1[i];
				i++;
				k++;
			}
			else{
				nums1[k] = nums2[j];
				j++;
				k++;
			}
		//	cout << "i=" << i << ", j=" << j << ", k=" << k << ", nums1[" << k - 1 << "]=" << nums1[k - 1] << endl;
		}
		/*for (int l : nums1)
			cout << l << " ";
		cout << endl;*/
		return;
	}
};

void main(int argc, char *argv[]){
	vector<int> nums1 = { -1, 0, 0, 3, 3, 3, 0, 0, 0 };
	vector<int> nums2 = { 1, 2, 2 };
	int n = nums2.size();
	int m = 6;
	cout << "Original sorted array 1: ";
	for (int arr1 : nums1)
		cout << arr1 << " "; 
	cout << endl;
	cout << "Original sorted array 2: ";
	for (int arr2 : nums2)
		cout << arr2 << " ";
	cout << endl;
	Solution s;
	s.merge(nums1, m, nums2, n);
	cout << "The merged sorted array: ";
	for (int arr : nums1)
		cout << arr << " ";
	cout << endl;
	system("pause");
}