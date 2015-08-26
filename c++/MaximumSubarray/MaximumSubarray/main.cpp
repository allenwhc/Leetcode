/*
*	Maximum Subarray
*	Last Modified: 6/18/2015
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
	//O(n) approach using 1-D dynamic array
	int maxSubArray1(vector<int>& nums){
		int n = nums.size();
		int sum = 0;
		int maximum = INT_MIN;
		for (int i = 0; i < n; i++){
			sum = sum + nums[i];
			maximum = max(sum, maximum);
			sum = max(sum, 0);
		}
		return maximum;
	}

	//Divide and conquer approach
	int maxSubArray2(vector<int>& nums){
		int n = nums.size();
		int maximum = INT_MIN;
		return maxArray(nums, 0, n - 1, maximum);
	}
private:
	int maxArray(vector<int>& nums, int start, int end, int maximum){
		if (start > end) return INT_MIN;
		int middle = (start + end) / 2;
		int leftMax = maxArray(nums, start, middle - 1, maximum);
		int rightMax = maxArray(nums, middle + 1, end, maximum);
		maximum = max(maximum, leftMax);
		maximum = max(maximum, rightMax);
		int sum = 0, middleLeftMax = 0;
		for (int i = middle - 1; i >= start; i--){
			sum = sum + nums[i];
			middleLeftMax = max(sum, middleLeftMax);
		}
		sum = 0; int middleRightMax = 0;
		for (int i = middle + 1; i < end; i++){
			sum = sum + nums[i];
			middleRightMax = max(sum, middleRightMax);
		}
		maximum = max(maximum, middleLeftMax + middleRightMax + nums[middle]);
		return maximum;
	}
};

void main(int argc, char *argv[]){
	vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	Solution s;
	//int maximum = s.maxSubArray1(nums);	//O(n) approach
	int maximum = s.maxSubArray2(nums); //O(logn) approach
	cout << "The maximum sm of that subarray is: " << maximum << endl;
	system("pause");
}