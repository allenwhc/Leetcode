/*
*	Roman to Integer
*	Last Modified: 7/27/2015
*/

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int n = s.length();
		if (n == 0) return 0;
		int num = 0;
		int prev = 0;
		for (int i = n - 1; i >= 0; i--){
			int current = 0;
			char c = s[i];
			switch (c)
			{
			case 'I':
				current = 1;
				break;
			case 'V':
				current = 5;
				break;
			case 'X':
				current = 10;
				break;
			case 'L':
				current = 50;
				break;
			case 'C':
				current = 100;
				break;
			case 'D':
				current = 500;
				break;
			case 'M':
				current = 1000;
				break;
			default:
				break;
			}
			int sign = (current < prev) ? -1 : 1;
			prev = current;
			num += sign*current;
		}
		return num;
	}
};

void main(int argc, char *argv[]){
	string s = "CMLXVI";
	Solution sol;
	cout << "Convert roman number '" << s << "' to integer is: " << sol.romanToInt(s) << endl;
	system("pause");
}