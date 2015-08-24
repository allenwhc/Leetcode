/*
*	Remove Duplicates from Sorted Array I & II
*	Last Modified: 7/14/2015
*/
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution{
public:
	//Remove Duplicates from Sorted Array I
	int removeDuplicates1(vector<int> &nums){
		int n = nums.size();
		if (n <= 1) return n;
		else{
			int i = 1;
			int j = 0;
			while (i < n){
				if (nums[i] == nums[j]) i++;
				else{
					j++;
					nums[j] = nums[i];
					i++;
				}
			}
			return j + 1;
		}
	}

	//Remove Duplicates from Sorted Array II
	int removeDuplicates2(vector<int>& nums){
		int n = nums.size();
		if (n == 0) return 0;
		int occur = 1;
		int index = 0;
		for (int i = 1; i < n; i++){
			if (nums[i] == nums[index]){
				if (occur == 2) continue;
				occur++;
			}
			else occur = 1;
			nums[++index] = nums[i];
		}

		return index + 1;
	}
};

void main(int argc, char *argv[]){
	//vector<int> nums = { 1, 1, 2 };
	//vector<int> nums = { 1, 1, 2, 3, 4, 4, 5, 6, 6 };
	//vector<int> nums = { 1 };
	vector<int> nums = { 1, 1, 1, 2 };
	vector<int> nums2 = { 1, 1, 1, 2 };
	//vector<int> nums = { -3, -3, -2, -1, -1, 0, 0, 0, 0, 0 };
	//vector<int> nums(0);
	Solution s;
	int length = s.removeDuplicates1(nums);
	cout << "Remove duplicates I, elements are allowed to appear only once" << endl;
	cout << "The length of the original array is: " << nums.size() << endl;
	cout << "The length of the trimmed array is: " << length << endl;
	cout << endl << "Remove duplicates II, elements are allowed to appear at most twice" << endl;
	cout << "The length of the original array is: " << nums2.size() << endl;
	cout << "The length of the trimmed array is: " << s.removeDuplicates2(nums2) << endl;
	system("pause");
}