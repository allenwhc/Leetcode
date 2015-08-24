/*
*	Largest Number
*	Last Modified: 7/13/2015
*/

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution{
public:
	string largestNumber(vector<int>& nums){
		string result;
		sort(nums.begin(), nums.end(), [](int a, int b){ return to_string(a) + to_string(b) > to_string(b) + to_string(a); });
		for (int n : nums)
			result += to_string(n);
		if (result.front() == '0') return "0";
		else return result;
	}
};

void main(int argc, char* argv[]){
	vector<int> nums = { 3, 30, 34, 5, 9 };
	Solution s;
	cout << "The largest formed number is: " << s.largestNumber(nums) << endl;
	system("pause");
}