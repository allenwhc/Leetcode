/*
*	Add Digits
*	Last Modified: 8/16/2015
*/

#include <iostream>
using namespace std;

class Solution {
public:
	int addDigits(int num) {
		if (num < 10) return num;
		int x = floor((num - 1) / 9);
		return num - 9 * x;
	}
};

void main(){
	int num = 38;
	Solution sol;
	cout << "The result of adding digits in " << num << " is: " << sol.addDigits(num) << endl;
	system("pause");
}