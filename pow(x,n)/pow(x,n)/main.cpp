/*
*	Power Function
*	Last Modified: 5/29/2015
*/
#include<iostream>
using namespace std;

class Solution{
public:
	double myPow(double x, int n){
		if (n == 0) return 1;
		if (n == 2) return x * x;
		if (n % 2 == 0) return myPow(myPow(x, n / 2), 2);
		else if (n > 0)	return x * myPow(myPow(x, n / 2), 2);
		else return 1 / x * myPow(myPow(x, n / 2), 2);
	}
};

void main(int argc, char* argv[]){
	double x;
	int n;
	Solution s;
	double result;
	cout << "Input the base: ";
	cin >> x;
	cout << "Input the power: ";
	cin >> n;
	result = s.myPow(x, n);
	cout << x << " to the power of " << n << " is: " << result << endl;
	system("pause");
}