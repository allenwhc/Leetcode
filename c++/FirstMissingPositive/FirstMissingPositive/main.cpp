/*
*	First Missing Positive Number
*	Last Modified: 6/2/2015
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int firstMissingPositive(vector<int>& nums){
		int n = nums.size();
		//print(nums, n);
		int i = 0;
		while (i < n)
		{
			if (nums[i] >= 1 && nums[i] <= n && nums[i] != i + 1 && nums[i] != nums[nums[i] - 1])
			{
				swap(nums[i], nums[nums[i] - 1]);
				//print(nums, n);
			}
			else{
				i++;
				//print(nums, n);
			}
				
		}
		cout << endl;
		for (int i = 0; i < n; i++){
			if (nums[i] != i + 1)
				return i + 1;
		}
		return n + 1;
	}
private:
	void print(vector<int> &nums,int n){
		for (int i = 0; i < n; i++)
			cout << nums[i] << " ";
		cout << endl;
	}
};

void main(int argc, char* argv[]){
	vector<int> nums = { 3, 4, -1, 1, 0, -4, 2, 5,-3, 7 };
	int missing = 0;
	Solution s;
	missing = s.firstMissingPositive(nums);
	cout << "The first missing positive number in the array is: " << missing << endl;
	system("pause");
}