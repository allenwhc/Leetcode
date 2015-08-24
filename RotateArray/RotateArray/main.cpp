/*
*	Rotate Array
*	Last Modified: 6/15/2015
*/

#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

class Solution{
public:
	void rotate(vector<int>& nums, int k){
		int n = nums.size();
		k=k%n;
		if (n <= 1 || k == 0 || k > n-1) return;
		else if (n == 2){
			int temp = nums[1];
			nums[1] = nums[0];
			nums[0] = temp;
		}
		else{
			vector<int> save(n);
			for (int i = 0; i < n; i++)
				save[i] = nums[i];
			for (int i = 0; i < k; i++)
				nums[i] = save[n - k + i];
			for (int i = k; i < n; i++)
				nums[i] = save[i - k];
		}
	}
};

void main(int argc, char* argv){
	//vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> nums = { 1, 2, 3 };
	int k = 2;
	//srand(time(NULL));
	//int k = rand() % nums.size();
	Solution s;
	cout << "The original array is: ";
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
	s.rotate(nums, k);
	cout << "The array rotated at " << k << " step(s) is: ";
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
	system("pause");
}