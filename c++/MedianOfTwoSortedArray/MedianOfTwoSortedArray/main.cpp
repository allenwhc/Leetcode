/*
*	Median of Two Sorted Array
*	Last Modified: 7/13/2015
*/

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
		int n = nums1.size();
		int m = nums2.size();
		//If m+n is odd
		if ((m + n) % 2 != 0) return (double)findMedian(nums1, nums2, 0, n - 1, 0, m - 1, (m + n) / 2);
		else return (findMedian(nums1, nums2, 0, n - 1, 0, m - 1, (m + n) / 2) + findMedian(nums1, nums2, 0, n - 1, 0, m - 1, (m + n) / 2 - 1)) / 2.0;
	}

	int findMedian(vector<int>& nums1, vector<int>& nums2, int start1, int end1, int start2, int end2, int k){
		int len1 = end1 - start1 + 1;
		int len2 = end2 - start2 + 1;

		if (len1 == 0) return nums2[start2 + k];
		if (len2 == 0) return nums1[start1 + k];
		if (k == 0) return min(nums1[start1], nums2[start2]);

		int middle1 = k*(len1) / (len1 + len2);
		int middle2 = k - middle1 - 1;

		middle1 += start1;
		middle2 += start2;

		if (nums1[middle1] <= nums2[middle2]){
			k -= middle1 - start1 + 1;
			end2 = middle2;
			start1 = middle1 + 1;
		}
		else{
			k -= middle2 - start2 + 1;
			end1 = middle1;
			start2 = middle2 + 1;
		}
		return findMedian(nums1, nums2, start1, end1, start2, end2, k);
	}

};

void main(int argc, char* argv[]){
	vector<int> nums1 = { 1, 3, 5, 6, 7, 9, 10 };
	vector<int> nums2 = { -3, -1, 0, 2, 4, 8 };
	cout << "The first sorted array is: ";
	for (int i = 0; i < nums1.size(); i++){
		cout << nums1[i];
		if (i != nums1.size() - 1) cout << ",";
	}
	cout << endl << "The second sorted array is: ";
	for (int i = 0; i < nums2.size(); i++){
		cout << nums2[i];
		if (i != nums2.size() - 1) cout << ",";
	}
	cout << endl;
	Solution s;
	cout << "The median of the above two sorted arrays is: " << s.findMedianSortedArrays(nums1, nums2) << endl;
	system("pause");
}