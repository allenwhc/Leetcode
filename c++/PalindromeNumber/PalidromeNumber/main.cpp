/*
*	Palindrome Number
*	Last Modified: 6/8/2015
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	bool isPalindrome(int x){
		if (x > INT_MAX)
			return false;
		else if (x < 0)
			return false;
		int div = 1;
		while (x / div >= 10)
			div *= 10;
		while (x>0)
		{
			int quotient = x / div;
			int remainder = x % 10;
			if (quotient != remainder) 
				return false;
			x = x%div / 10;
			div /= 100;
		}
		return true;
	}
};

void main(int argc, char *argv[]){
	int x;
	Solution s;
	cout << "Input an integer: ";
	cin >> x;
	bool palindrome = s.isPalindrome(x);
	if (palindrome)
		cout << x << " is a palindrome number!" << endl;
	else
		cout << x << " is not a palindrome number!" << endl;
	system("pause");
}