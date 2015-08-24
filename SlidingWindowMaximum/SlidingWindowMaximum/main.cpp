/*
*	Sliding Window Maximum
*	Last Modified: 7/20/2015
*	Hint:
		1. Initialize a double-ended queue dq of size k
		2. for i: 0~k-1
			1) If dq is not empty, and nums[i] >= nums[dq.back()], pop the tail of dq
			2) Repeat 1) until unsatisfied
			3) Push the current index i to dq
		3.  for i: k~n-1
			1) Add nums[dq.front()] to result
			2) Check if dq.front() is out of the boundary k, 
				if dq.front()<=i-k, pop the head of dq
				repeat until dq.front()>i-k 
			3) Repeat 2 for every element in nums[]
		4. Add the last maximum nums[dq.front()] to result
*/

#include <deque>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> res;
		int n = nums.size();
		if (n == 0) return res;
		deque<int> dq(k);
		int i = 0;
		for (; i < k; i++){
			while (!dq.empty() && nums[i] >= nums[dq.back()])
				dq.pop_back();
			dq.push_back(i);
		}

		for (; i < n; i++){
			res.push_back(nums[dq.front()]);	//Add the front of the queue to result
			while (!dq.empty() && dq.front() <= i - k)
				dq.pop_front();
			while (!dq.empty() && nums[i] >= nums[dq.back()])
				dq.pop_back();
			dq.push_back(i);
		}
		res.push_back(nums[dq.front()]);
		return res;
	}
};

void main(int argc, char *argv[]){
	vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
	int k = 3;
	Solution s;
	vector<int> res = s.maxSlidingWindow(nums, k);
	cout << "The maximum for every " << k << " numbers is: ";
	for (int ii : res)
		cout << ii << " ";
	cout << endl;
	system("pause");
}