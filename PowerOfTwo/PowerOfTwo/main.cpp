/*
*	Power of Two
*	Last Modified: 7/6/2015
*/

#include <iostream>
using namespace std;

class Solution{
public:
	bool isPowerOfTwo(int n){
		if (n <= 0) return false;
		else if (n == 1) return true;
		else{
			while (n != 1){
				if (n % 2 != 0) return false;
				n /= 2;
			}
			return true;
		}
	}
};

void main(int argc, char* argv[]){
	int n = 16;
	Solution s;
	bool isTwo = s.isPowerOfTwo(n);
	cout << n;
	if (isTwo) cout << " is a power of two." << endl;
	else cout << " is not a power of two." << endl;
	system("pause");
}