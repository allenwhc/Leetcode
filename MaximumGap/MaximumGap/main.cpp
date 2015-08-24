/*
*	Maximum Gap
*	Last Modified: 6/11/2015
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
	int maximumGap(vector<int>& nums){
		int n = nums.size();
		if (n <= 1) return 0;
		//Traverses the array, and finds the maximum and the minimum element
		int maxVal = INT_MIN;
		int minVal = INT_MAX;
		for (int i = 0; i < n; i++){
			maxVal = max(maxVal, nums[i]);
			minVal = min(minVal, nums[i]);
		}
		int bucketSize = (maxVal - minVal) / (n - 1) + 1;
		int numOfBucket = (maxVal - minVal) / bucketSize + 1;
		cout << "Bucket Size: " << bucketSize << ", Number of Buckets: " << numOfBucket << endl;
		//Allocates elements into different bucket
		vector<vector<int>> bucket(numOfBucket);
		for (int i = 0; i < n; i++){
			int index = (nums[i] - minVal) / bucketSize;
			if (bucket[index].empty()){
				bucket[index].reserve(2);
				bucket[index].push_back(nums[i]);
				bucket[index].push_back(nums[i]);
			}
			else{
				if (nums[i] < bucket[index][0]) bucket[index][0] = nums[i];
				if (nums[i] > bucket[index][1]) bucket[index][1] = nums[i];
			}
		}
		cout << "The bucket is shown below: " << endl;
		for (int i = 0; i < bucket.size(); i++){
			for (int j = 0; j < bucket[i].size(); j++)
				cout << bucket[i][j] << " ";
			cout << endl;
		}
		//Calculates the maximum gap
		int gap = 0;
		int previous = 0;
		for (int i = 0; i < numOfBucket; i++){
			if (bucket[i].empty()) continue;
			gap = max(gap, abs(bucket[i][0] - bucket[previous][1]));
			previous = i;
		}
		return gap;
	}
};

void main(int argc, char *argv[]){
	vector<int> nums = { 4, 1, 5, 2, 6, 10, 7, 14, 3, 20 };
	Solution s;
	int gap = s.maximumGap(nums);
	cout << "The maximum gap between two successive elements in sorted form is: " << gap << endl;
	system("pause");
}