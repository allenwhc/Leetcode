/*
*	Ugly Number I & II
*	Last Modified: 8/19/2015
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	//Ugly Number I, Determine if a number is ugly 
	bool isUgly(int num) {
		if (num <= 0) return false;
		num = GDP(num, 2);
		num = GDP(num, 3);
		num = GDP(num, 5);
		return (num == 1) ? true : false;
	}
	//Greatest Divisible Power
	int GDP(int a, int b){
		while (a%b == 0)
			a = a / b;
		return a;
	}

	//Ugly Number II, find nth ugly number
	int nthUglyNumber(int n) {
		int po2 = 0, po3 = 0, po5 = 0;
		vector<int> ugly(n);
		ugly[0] = 1;
		for (int i = 1; i < n; i++){
			int prev = ugly[i - 1];
			while (ugly[po2] * 2 <= prev)
				po2++;
			while (ugly[po3] * 3 <= prev)
				po3++;
			while (ugly[po5] * 5 <= prev)
				po5++;
			int candidate2 = ugly[po2] * 2;
			int candidate3 = ugly[po3] * 3;
			int candidate5 = ugly[po5] * 5;
			ugly[i] = min(candidate2, min(candidate3, candidate5));
		}
		return ugly[n - 1];
	}
};

void main(){
	vector<int> nums = { 1, 5, 6, 8, 14 };
	vector<bool> ugly(nums.size());
	Solution sol;
	for (int i = 0; i < nums.size(); i++)
		ugly[i] = sol.isUgly(nums[i]);
	for (int i = 0; i<nums.size(); i++) {
		if (ugly[i]) cout << nums[i] << " is an ugly number." << endl;
		else cout << nums[i] << " is not an ugly number." << endl;
	}
	int n = 100;
	cout << "The " << n << "th ugly number is: " << sol.nthUglyNumber(n) << endl;
	system("pause");
}