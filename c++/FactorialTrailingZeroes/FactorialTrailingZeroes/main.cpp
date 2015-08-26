/*
*	Factorial Trailing Zeroes
*	Last Modified: 7/1/2015
*/

#include <iostream>
using namespace std;

class Solution{
public:
	int trailingZeroes(int n){
		if (n < 0) return -1;
		int fac = 5;
		int answer = 0;
		while (n >= fac){
			answer += n / fac;
			n /= 5;
		}
		return answer;
	}
};

void main(int argc, char* argv[]){
	int n;
	Solution s;
	cout << "Input an integer: ";
	cin >> n;
	int num = s.trailingZeroes(n);
	cout << "The number of trailing zeroes in " << n << "! is: " << num << endl;
	system("pause");
}