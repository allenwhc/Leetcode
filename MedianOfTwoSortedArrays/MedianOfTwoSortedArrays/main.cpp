/*
*	Median of Two Sorted Arrays
*	Last Modified: 6/10/2015
*/

#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
		int m = nums1.size();
		int n = nums2.size();
		int array1[];
		int array2[];
		if ((m + n) % 2 != 0)
			return (getMedian(nums1, m, nums2, n, (m + n) / 2 + 1));
		else
			return (getMedian(nums1, m, nums2, n, (m + n) / 2) + getMedian(nums1, m, nums2, n, (m + n) / 2 + 1)) / 2.0;
	}
private:
	int getMedian(vector<int> &nums1, int m, vector<int> &nums2, int n, int k){
		if (m <= 0) return nums1[k - 1];
		if (n <= 0) return nums2[k - 1];
		if (k <= 1) return min(nums1[0], nums2[0]);
		if (m / 2 + n / 2 <= k){
			if (nums1[m / 2] >= nums2[n / 2])
				return getMedian(nums1, m, nums2 + n / 2 + 1, n - (n / 2 + 1), k - (n / 2 + 1));
		}
	}
};

void main(int argc, char *argv[]){
	Solution s;
	vector<int> nums1 = { 1, 3, 4, 5, 7, 9, 10 };
	vector<int> nums2 = { 2, 5, 7, 10, 13, 15 };
	double median = s.findMedianSortedArrays(nums1, nums2);
	cout << "The median of the two sorted array is: " << median << endl;
	system("pause");
}