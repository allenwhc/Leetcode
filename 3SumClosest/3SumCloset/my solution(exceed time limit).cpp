/*
*	3 Sum Closest
*	Last Modified: 6/5/2015
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution{
public:
	int threeSumClosest(vector<int>& nums, int target){
		int n = nums.size();
		int k = 3;
		if (n == 0)
			return 0;
		else if (n == 1)
			return nums.back();
		else if (n > 1 && n <= 3)
		{
			int sum = 0;
			for (int i = 0; i < n; i++)
				sum += nums[i];
			return sum;
		}
		else
		{
			vector<vector<int>> getCombination;
			getCombination = combination(n, k, nums);
			int rows = getCombination.size();
			int cols = getCombination[0].size();
			vector<int> sum(rows);
			vector<int> difference(rows);
			map<int, int> mp;
			for (int i = 0; i < rows; i++)
			{
				int sumRow = 0;
				for (int j = 0; j < cols; j++)
				{
					sumRow += getCombination[i][j];
				}
				sum[i] = sumRow;
			}
			cout << "The combination of the sum is: " << endl;
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
					cout << getCombination[i][j] << ", ";
				cout <<"sum: "<< sum[i] << endl;
			}
			for (int i = 0; i < rows; i++)
			{
				difference[i] = abs(sum[i] - target);
				mp[difference[i]] = i;
			}
			sort(difference.begin(), difference.end());
			return sum[mp[difference[0]]];
		}
	}
private:
	vector<vector<int>> combination(int n, int k, vector<int>& nums){
		vector<vector<int>> result;
		vector<int> solution(k);
		vector<bool> v(n);
		fill(v.begin() + n - k, v.end(), true);
		do
		{
			solution.erase(solution.begin(), solution.end());
			for (int i = 0; i < n; i++)
			{
				if (v[i])
					solution.push_back(nums[i]);
			}
			result.push_back(solution);
		} while (next_permutation(v.begin(),v.end()));
		return result;
	}
};

void main(){
	vector<int> nums = { 13, 2, 0, -14, -20, 19, 8, -5, -13, -3, 20, 15, 20, 5, 13, 14, -17, -7, 12, -6, 0, 20, -19, -1, -15, -2, 8, -2, -9, 13, 0, -3, -18, -9, -9, -19, 17, -14, -19, -4, -16, 2, 0, 9, 5, -7, -4, 20, 18, 9, 0, 12, -1, 10, -17, -11, 16, -13, -14, -3, 0, 2, -18, 2, 8, 20, -15, 3, -13, -12, -2, -19, 11, 11, -10, 1, 1, -10, -2, 12, 0, 17, -19, -7, 8, -19, -17, 5, -5, -10, 8, 0, -12, 4, 19, 2, 0, 12, 14, -9, 15, 7, 0, -16, -5, 16, -12, 0, 2, -16, 14, 18, 12, 13, 5, 0, 5, 6 };
	int target = -59;
	Solution s;
	int closestSolution = s.threeSumClosest(nums, target);
	cout << "The target sum is: " << target << endl;
	cout << "The closest solution is: " << closestSolution << endl;
	system("pause");
}