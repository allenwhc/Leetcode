#include <iostream>
#include <limits.h>
#include <vector>
#include <set>
using namespace std;
/*
*	Dynamic programming solution
*	Time complexity: O(mn^2logm), m -- row, n -- col
*	Extra space: O(n)
*/

int maxOneClosest(vector<int> &nums, int k){
	int max_sum = INT_MIN;

	int sum = 0;
	set<int> cum_sum;
	cum_sum.insert(0);
	for(int i=0; i<nums.size(); i++){
		sum += nums[i];
		auto it = cum_sum.upper_bound(sum - k - 1);
		if(it != cum_sum.end()) max_sum = max(sum - *it, max_sum);
		cum_sum.insert(sum);
	}
	return max_sum;
}

int maxSumSubmatrix(vector<vector<int>> &matrix, int k){
	if(matrix.empty()) return 0;
	int m = matrix.size(), n = matrix[0].size();
	int max_sum = INT_MIN;
	int left = 0, right = 0, up = 0, down = 0;
	for(int l=0; l<n; l++){
		vector<int> col(m, 0);
		for(int r=l; r<n; r++){
			for(int i=0; i<m; i++) col[i] += matrix[i][r];	//Add current column to col[]
 			int curr_max_sum = maxOneClosest(col, k);
 			max_sum = max(max_sum, curr_max_sum);
		}
	}
	return max_sum;
}

int main(int argc, char const *argv[])
{
	vector<vector<int>> matrix = {{5,-4,-3,4},{-3,-4,4,5},{5,1,5,-4}};
	int k = 8;
	cout << maxSumSubmatrix(matrix, k) << endl;
	return 0;
}