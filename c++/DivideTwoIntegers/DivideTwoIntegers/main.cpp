/*
*	Divide Two Integers
*	Last Modified: 7/24/2015
*/

#include <iostream>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		//Handle overflows
		if (divisor == 0) return INT_MAX;
		if (divisor == -1 && dividend == INT_MIN) return INT_MAX;

		//Get absolute values
		long x = abs((long)dividend);
		long y = abs((long)divisor);

		int result = 0;
		while (y <= x){
			int count = 0;
			while (x >= (y << count))
				count++;
			result += 1 << (count - 1);
			x -= y << (count - 1);
		}

		if ((dividend > 0 && divisor < 0) || (dividend<0 && divisor > 0))
			result = -result;
		return result;
	}
};

void main(int argc, char *argv[]){
	int dividend = -1010369383;
	int divisor = -2147483647;
	Solution s;
	cout << dividend << " / " << divisor << " = " << s.divide(dividend, divisor) << endl;
	system("pause");
}