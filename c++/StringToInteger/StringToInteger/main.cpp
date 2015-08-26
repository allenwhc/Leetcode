/*
*	String to Integer
*	Last Modified: 7/24/2015
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int len = str.length();
		if (len == 0) return 0;
		int i = 0;
		bool isPositive = true;
		//1. Skip the leading spaces
		while (i < len && str[i] == ' '){
			i++;
			if (i == len - 1) return 0;
		}


		//2. Determine the sign of the number
		if (str[i] == '+' || str[i] == '-'){
			isPositive = (str[i] == '+') ? true : false;
			i++;
		}
		//3. Determine if valid conversion exists
		if (str[i] < '0' || str[i] > '9') return 0;
		else{
			vector<int> digits;
			int num = 0;
			while (i < len && str[i] >= '0' && str[i] <= '9'){
				digits.push_back(str[i] - '0');
				i++;
			}
			if (digits.size() > 10){
				if (isPositive) num = INT_MAX;
				else num = INT_MIN;
				return num;
			}
			else if (digits.size() == 10){
				for (int i = 0; i < digits.size() - 1; i++)
					num = num * 10 + digits[i];
				num = num * 10;
				if (isPositive && num == 2147483640 && digits[digits.size() - 1] > 7)
					num = INT_MAX;
				else if (!isPositive && num == 2147483640 && digits[digits.size() - 1] > 8)
					num = INT_MIN;
				else{
					num = num + digits[digits.size() - 1];
					if (!isPositive) num = -num;
				}
				return num;
			}
			else{
				for (int i = 0; i < digits.size(); i++)
					num = num * 10 + digits[i];
				if (!isPositive) num = -num;
				return num;
			}
		}

	}
};

void main(int argc, char *argv[]){
	//string str = "    -243214&*(3892uhi  asd92032d";
	string str = "2147483648";
	Solution s;
	cout << "Converting '" << str << "' to integer is: " << s.myAtoi(str) << endl;
	system("pause");
}