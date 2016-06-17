#include <iostream>
#include <vector>
using namespace std;
enum T
{
	peach = 1,
	apple = 2,
};

vector<int> mergeSortedArray(vector<int> &v1, vector<int> &v2){
	vector<int> res (v1.size() + v2.size(), 0);
	int i = 0, j = 0, index = 0;
	while (i < v1.size() && j < v2.size()){
		if (v1[i] < v2[j]) res[index++] = v1[i++];
		else res[index++] = v2[j++];
	}
	while (i < v1.size()) res[index++] = v1[i++];
	while (j < v2.size()) res[index++] = v2[j++];
	return res;
}

vector<int> sortTransformedArray(vector<int> &nums, int a, int b, int c){
	vector<int> res;
	if (nums.empty()) return res;
	int f_x = 0;
	if (a != 0){
		double tp = (-b) / (2.0 * a);
		vector<int> smaller_pts, larger_pts;
		for (auto &x: nums){
			f_x = a*x*x + b*x + c;
			if (x < tp) smaller_pts.push_back(f_x);
			else larger_pts.push_back(f_x);
		}
		if (a > 0) reverse(smaller_pts.begin(), smaller_pts.end());
		else reverse(larger_pts.begin(), larger_pts.end());
		res = mergeSortedArray(smaller_pts, larger_pts);
	}
	else{
		for (auto &x: nums){
			f_x = b*x + c;
			res.push_back(f_x);
		}
		if (b < 0) reverse(res.begin(), res.end());
	}
	return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	//cout << T::peach <<"," <<T::apple << endl;
	vector<int> nums = {-4,-2,2,4};
	int a = 0, b = 3, c = 5;
	vector<int> trans_nums = sortTransformedArray(nums, a, b, c);
	for (auto &v: trans_nums) cout << v << " ";
	cout << endl;
	return 0;
}