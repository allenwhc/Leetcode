/*
*	Minimum Size Subarray Sum
*	Last Modified: 6/15/2015
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
	//O(n)->Dynamic Programming
	int minSubArrayLen1(int s, vector<int>& nums){
		int n = nums.size();
		if (n == 0) return 0;
		int totalSum = 0;
		for (int i = 0; i < n; i++)
			totalSum += nums[i];
		if (totalSum < s) return 0;
		else{
			int length = n;
			int i = 0, j = 0;
			int sum = nums[0];	//Initializes the sum as nums[0]
			while (j < n){
				if (i == j){
					if (nums[i] >= s) return 1;
					else{
						j++;
						if (j < n) sum += nums[j];
						else return length;
					}
				}
				else{
					if (sum < s){
						j++;
						if (j < n) sum += nums[j];
						else{
							if (i = 0) return 0;
							else return length;
						}
					}
					else{
						length = min(j - i + 1, length);
						sum -= nums[i];
						i++;
					}
				}
			}
			return length;
		}
		
	}
};

void main(int argc, char *argv[]){
	vector<int> nums = { 2, 4, 1, 2, 3, 4 };
	int sum = 7;
	Solution s;
	int length = s.minSubArrayLen1(sum, nums);
	cout << "The minimum length of the subarray adding up to " << sum << " is: " << length << endl;
	system("pause");
}