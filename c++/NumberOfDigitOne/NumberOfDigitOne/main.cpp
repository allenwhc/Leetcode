/*
*	Number of Digit One
*	Last Modified: 7/12/2015
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
	int countDigitOne(int n){
		if (n <= 0) return 0;
		int res = 0;
		int num = n;
		int digit = 1;
		int cnt = 1;
		while (num){
			int mod = num % 10;
			int add = (mod == 1) ? 1 : 0;
			res += (num + 8) / 10 * cnt + add*digit;
			digit += mod*cnt;
			cnt *= 10;
			num /= 10;
		}
		return res;
	}
};

void main(int argc, char* argv[]){
	int n = 56;
	Solution s;
	cout << "There are " << s.countDigitOne(n) << " '1's in the numbers less than or equal to " << n << endl;
	system("pause");
}