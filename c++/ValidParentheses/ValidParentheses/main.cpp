/*
*	Valid Parentheses
*	Last Modified: 6/15/2015
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public: 
	bool isValid(string s){
		int n = s.size();
		if (n == 0) return false;
		vector<char> str;
		str.clear();
		str.push_back(s[0]);
		for (int i = 1; i < n; i++){
			if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
				str.push_back(s[i]);
				continue;
			}
			char current = str.back();
			if (s[i] == ')' && current != '(') return false;
			if (s[i] == ']' && current != '[') return false;
			if (s[i] == '}' && current != '{') return false;
			str.pop_back();
		}
		if (str.size() != 0) return false;
		return true;
	}
};

void main(int argc, char *argv[]){
	string str1 = "{([])}";
	string str2 = "()[{]}";
	string str3 = "()[";
	Solution s;
	bool b1 = s.isValid(str1);
	if (b1) cout << "Valid" << endl;
	else cout << "Not Valid" << endl;
	bool b2 = s.isValid(str2);
	if (b2) cout << "Valid" << endl;
	else cout << "Not Valid" << endl;
	bool b3 = s.isValid(str3);
	if (b3) cout << "Valid" << endl;
	else cout << "Not Valid" << endl;
	system("pause");
}