/*
*	Evaluate Reverse Polish Notation
*	Last Modified: 7/27/2015
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
private:
	bool isPositive;
public:

	int evalRPN(vector<string>& tokens) {
		int n = tokens.size();
		if (n == 0) return 0;
		stack<int> stk;		//Stack to store all the numbers
		for (int i = 0; i < n; i++){
			string str = tokens[i];		//Get the token
			//Determine if the current token is a number
			//If it is a number, push it into the stack
			if (isNumber(str)){
				int num = stringToInt(str);
				stk.push(num);
			}
			//If it is an operator
			else if ((str == "+") || (str == "-") || (str == "*") || str == "/"){
				if (stk.size() < 2) return 0;	//If the stack has less than 2 numbers
				//Pop top 2 numbers in the stack
				int a = stk.top();
				stk.pop();
				int b = stk.top();
				stk.pop();

				//Switch the operator
				switch (str.back())
				{
				case '+':
					stk.push(b + a);
					break;
				case '-':
					stk.push(b - a);
					break;
				case '*':
					stk.push(b * a);
					break;
				case '/':
					if (a == 0) return 0;
					stk.push(b / a);
					break;
				default:
					break;
				}
			}

		}
		if (!stk.empty()){
			int res = stk.top();
			while (!stk.empty())
				stk.pop();
			return res;
		}
		return 0;
	}

	bool isNumber(string &s){
		isPositive = true;
		if (s.length() == 0) return false;
		//cout << s[0] << endl;
		if (s[0] == '-'){
			if (s.length() == 1) return false;	//operator '-', not a number
			else{
				isPositive = false;
				for (int i = 1; i < s.length(); i++){
					if (!isdigit(s[i])) return false;
				}
				return true;
			}
		}
		else if (s[0]>='0' && s[0]<='9'){
			for (int i = 0; i < s.length(); i++){
				if (!isdigit(s[i])) return false;
			}
			return true;
		}
		return false;
	}

	int stringToInt(string &s){
		if (s.length() == 0) return 0;
		int num = 0;
		if (isPositive){
			for (int i = 0; i < s.length(); i++){
				num = num * 10 + s[i] - '0';
			}
		}
		else{
			for (int i = 1; i < s.length(); i++){
				num = num * 10 + s[i] - '0';
			}
			num = -num;
		}
		return num;
	}
};

void main(int argc, char *argv[]){
	vector<string> tokens1 = { "3", "-4", "+"};
	vector<string> tokens2 = { "4", "13", "5", "/", "+" };
	Solution sol;
	int res1 = sol.evalRPN(tokens1);
	int res2 = sol.evalRPN(tokens2);
	cout << "The result of ";
	for (string ss : tokens1)
		cout << "'" << ss << "', ";
	cout << "is: " << res1 << endl;
	cout << "The result of ";
	for (string ss : tokens2)
		cout << "'" << ss << "', ";
	cout << "is: " << res2 << endl;
	system("pause");
}