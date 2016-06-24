#include <iostream>
using namespace std;

class Solution{
public:
	int reverse(int x);
};

int Solution::reverse(int x)
{
	int negative = x<0?-1:1;
    x = abs(x);
    int num = 0;
    while(x){
        int digit = x%10;
        int temp = num*10+digit;
        if((num == INT_MAX/10 && digit>=8) || temp/10 != num) return 0;
        num = temp;
        x /= 10;
    }
    return negative*num;
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