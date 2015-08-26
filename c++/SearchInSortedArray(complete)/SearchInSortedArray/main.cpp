/*
*	Search in A Sorted Array
*	Last Modified: 6/10/2015
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

class Solution{
public: 
	int search(vector<int>& nums, int target){
		int n = nums.size();
		if (n == 0) return -1;
		else if (n == 1){
			if (nums.back() == target) return 0;
			else return -1;
		}
		else{
			srand(time(NULL));
			int pivot = rand() % n;
			cout << "The pivot is: " << pivot << endl;
			vector<int> rotatedArray(n);
			if (pivot != 0){
				for (int i = 0; i < n - pivot; i++)
					rotatedArray[i] = nums[i + pivot];
				for (int i = n - pivot; i < n; i++)
					rotatedArray[i] = nums[i - n + pivot];
			}
			else{
				for (int i = 0; i < n; i++)
					rotatedArray[i] = nums[i];
			}
			cout << "The rotated array is: ";
			for (int i = 0; i < n; i++)
				cout << rotatedArray[i] << " ";
			cout << endl;
			if (target > rotatedArray[n - 1 - pivot]) return -1;
			else{
				if (pivot == 0)
					return findIndex(rotatedArray, 0, n - 1, target, pivot);
				else{
					if (target <= rotatedArray[n - 1]) return findIndex(rotatedArray, n - pivot, n - 1, target, pivot);
					else return findIndex(rotatedArray, 0, n - 1 - pivot, target, pivot);
				}
			}
		}
	}
private:
	int findIndex(vector<int> &nums, int start, int end, int target, int pivot){
		int middle = 0;
		while (start <= end){
			middle = start + (end - start) / 2;
			if (target == nums[middle]) return middle;
			else if (target < nums[middle]) end = middle - 1;
			else start = middle + 1;
		}
		return -1;
	}
};

void main(int argc, char *argv[]){
	vector<int> nums = { 1, 3 };
	int target = 1;
	Solution s;
	int index = s.search(nums, target);
	cout << "The index of " << target << " in the given array is: " << index << endl;
	system("pause");
}