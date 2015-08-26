/*
*	Bitwise AND of Numbers Range
*	Last Modified: 6/18/2015
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
	int rangeBitwiseAnd(int m, int n){
		int range = n - m;
		if (range == 0) return m;
		else{
			while (n > m){
				n = n&n - 1;
			}
			return m&n;
		}
	}
};

void main(int argc, char *argv[]){
	int m = 5;
	int n = 7;
	Solution s;
	int result = s.rangeBitwiseAnd(m, n);
	cout << "The bitwise AND result of numbers in " << m << "~" << n << " is: " << result << endl;
	system("pause");
}