#include <iostream>
using namespace std;

class Solution{
public:
	int reverse(int x);
};

int Solution::reverse(int x)
{
	int reverseResult = 0;
	int r = 0;
	while (x !=0)
	{
		if (reverseResult != 0 && INT_MAX / reverseResult < 10 && INT_MAX / reverseResult > -10)	//handle overflow
		{
			return 0;
		}
		r = x % 10;
		reverseResult = reverseResult * 10 + r;
		x = x / 10;
	}
	return reverseResult;
}
int main(int argc, char*argv[])
{
	int x;
	Solution c;
	cout << "Please input an integer ";
	cin >> x;
	cout << "The original integer is: " << x << endl;
	int rev = c.reverse(x);
	cout << "The reverse integer is:" << rev << endl;
	system("pause");
	return 0;
}