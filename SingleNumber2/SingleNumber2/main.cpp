/*
*	Single Number II
*	Last Modified: 6/19/2015
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int singleNumber(vector<int> &nums){
		int n = nums.size();
		int x = 0, y = 0;
		for (int i = 0; i < n; i++){
			x ^= ~y&nums[i];
			y ^= ~x&nums[i];
		}
		return x;
	}
};

void main(int argc, char *argv[]){
	vector<int> nums = { 2, 1, 1, 2, 1, 3, 2 };
	Solution s;
	int single = s.singleNumber(nums);
	cout << "The single number is: " << single << endl;
	system("pause");
}