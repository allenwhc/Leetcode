/*
*	Valid Number
*	Last Modified: 7/16/2015
*	Hint:
		Start from i=0;
		1)Skip the first i spaces
		2)Skip the first plus-minus sign
		3)If '.' exists, check the # of numeric characters and decimal points
			If more than 1 '.' exists, false
			If less than 1 numeric characters exist, false
		4)If exponential 'e' exists, check the # of numeric characters
			If less than 1 numeric characters exist, false
		5)Skip the last trailing spaces
		6)If the string ends with '\0', true;
		  else, false
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		int len = s.length();
		if (len == 0) return false;

		int i = 0;
		while (i < len && s[i] == ' ') i++;		//Skip the front spaces

		if (s[i] == '+' || s[i] == '-') i++;	//Skip the first sign
		int noNums = 0, noPts = 0;
		while (s[i] == '.' || (s[i] <= '9' && s[i] >= '0') && i < len){
			if (s[i] == '.') noPts++;
			else noNums++;
			i++;
		}

		if (noNums < 1) return false;	//If no numeric digits exist, return false
		if (noPts > 1) return false;	//If the string has more than one decimal points return false

		noNums = 0;
		if (s[i] == 'e'){
			i++;
			if (s[i] == '+' || s[i] == '-') i++;
			//Check if the exponetial part is valid
			while (s[i] <= '9' && s[i] >= '0'){
				noNums++;
				i++;
			}
			if (noNums < 1) return false;	//If the back of e has no numeric characters, return false
		}

		while (s[i] == ' ') i++;	//Skip the trailing spaces
		if (s[i] != '\0') return false;	//If the last digit is not 0, return false
		else return true;
	}
};


void main(int argc, char *argv[]){
	vector<string> str = { "   +.42e2      ", "4e+-10", "abc", "1 a", "2e10" };
	Solution s;
	vector<bool> isValid(str.size()); 
	for (int i = 0; i < isValid.size(); i++)
		isValid[i] = s.isNumber(str[i]);
	for (int i = 0; i < isValid.size(); i++){
		if (isValid[i]) cout << str[i] << " is a numeric string" << endl;
		else cout << str[i] << " is not a numeric string" << endl;
	}
	system("pause");
}