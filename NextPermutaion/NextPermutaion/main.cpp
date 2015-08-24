/*
*	Next Permutaion
*	Last Modified: 7/7/2015
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	//Using inplanted function next_permutation
	void nextPermutation(vector<int>& nums){
		int n = nums.size();
		if (n <= 1) return;
		int i = 0;
		do
		{
			i++;
		} while (next_permutation(nums.begin(),nums.end()) && i<1);
	}

	//Plain approach
	void nextPermutation1(vector<int>& nums){
		int n = nums.size();
		if (n <= 1) return;
		int pnIndex = n - 1; //Initializes the index of the partition number
		while (pnIndex > 0){
			if (nums[pnIndex - 1] < nums[pnIndex]) break;
			pnIndex--;
		}
		if (pnIndex > 0){
			pnIndex--;
			int cnIndex = n - 1;	//Initializes the index of change number
			while (nums[cnIndex] <= nums[pnIndex] && cnIndex >= 0) cnIndex--; 
			int temp = nums[cnIndex];
			nums[cnIndex] = nums[pnIndex];
			nums[pnIndex] = temp;
			pnIndex++;
		}
		int end = n - 1;
		while (end > pnIndex){
			int temp = nums[pnIndex];
			nums[pnIndex] = nums[end];
			nums[end] = temp;
			end--;
			pnIndex++;
		}
	}
};

void main(int argc, char* argv[]){
	vector<int> nums = { 6, 8, 7, 4, 3, 2 };
	Solution s;
	cout << "The next permutation of: ";
	for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
	cout << "is: ";
	s.nextPermutation1(nums);
	for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
	cout << endl;
	system("pause");
}