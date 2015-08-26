/*
*	3 Sum
*	Last Modified: 6/5/2015
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
	vector<vector<int>> threeSumClosest(vector<int>& nums){
		int n = nums.size();
		vector<vector<int>> result;
		vector<int> solution;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n - 2; i++)
		{
			if (i == 0 || nums[i] > nums[i - 1])
			{
				int sum = 0;
				int j = i + 1;
				int k = n - 1;
				while (j < k)
				{
					solution.clear();
					sum = nums[i] + nums[j] + nums[k];
					if (sum == 0)
					{
						solution.push_back(nums[i]);
						solution.push_back(nums[j]);
						solution.push_back(nums[k]);
						result.push_back(solution);
						j++;
						k--;
						while (j < k && nums[j] == nums[j - 1]) j++;
						while (j < k && nums[k] == nums[k + 1]) k--;
					}
					else
					{
						if (sum < 0)
							j++;
						else
							k--;
					}
				}
			}
			
		}
		
		return result;
	}
};

void main(){
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	vector<int> nums1 = { 12, 5, -12, 4, -11, 11, 2, 7, 2, -5, -14, -3, -3, 3, 2, -10, 9, -15, 2, 14, -3, -15, -3, -14, -1, -7, 11, -4, -11, 12, -15, -14, 2, 10, -2, -1, 6, 7, 13, -15, -13, 6, -10, -9, -14, 7, -12, 3, -1, 5, 2, 11, 6, 14, 12, -10, 14, 0, -7, 11, -10, -7, 4, -1, -12, -13, 13, 1, 9, 3, 1, 3, -5, 6, 9, -4, -2, 5, 14, 12, -5, -6, 1, 8, -15, -10, 5, -15, -2, 5, 3, 3, 13, -8, -13, 8, -5, 8, -6, 11, -12, 3, 0, -2, -6, -14, 2, 0, 6, 1, -11, 9, 2, -3, -6, 3, 3, -15, -5, -14, 5, 13, -4, -4, -10, -10, 11 };
	vector<vector<int>> result;
	Solution s;
	result = s.threeSumClosest(nums);
	cout << "The solutions are: " << endl;
	cout << "[";
	for (int i = 0; i < result.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j];
			if (j != result[i].size() - 1)
				cout << ",";
		}
		cout << "]";
		if (i != result.size() - 1)
			cout << "," << endl;
	}
	cout << "]" << endl;
	system("pause");
}