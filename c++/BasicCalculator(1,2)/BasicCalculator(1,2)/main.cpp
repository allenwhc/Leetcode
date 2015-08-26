/*
*	Basic Calculator I & II
*	Last Modified: 7/14/2015
*/

#include <vector>
#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Solution{
public:
	//Basic Calculator I, implement calculator 
	int calculate1(string s){
		int len = s.length();
		if (len == 0) return 0;
		stack<int> myStack;
		bool sign = true;	//'+'->true, '-'->false
		bool prevSign = true;	//Previous sign
		int result = 0;
		for (int i = 0; i < len; i++){
			char c = s[i];
			if (c == ' ') continue; //Skip spaces
			if (c == '+') sign = true;
			else if (c == '-') sign = false;
			else if (c == '('){
				myStack.push(prevSign);
				prevSign = (sign == true) ? prevSign : !prevSign;
				sign = true;
			}
			else if (c == ')'){
				prevSign = myStack.top();
				myStack.pop();
				sign = true;
			}
			else{
				int digit = c - '0';
				while (isdigit(s[++i]))
					digit = 10 * digit + s[i] - '0';
				i--;
				result += (sign == prevSign) ? digit : 0 - digit;
			}
		}
		return result;
	}

	//Basic Calculator II, 
	int calculate2(string s){
		int sum = 0, status = 1, term = 0;
		int len = s.length(); 
		for (int i = 0; i < len; i++){
			char c = s[i];
			if (c == '+'){
				status = 1;
				sum += term;
				term = 0;
			}
			else if (c == '-'){
				status = 2;
				sum += term;
				term = 0;
			}
			else if (c == '*')
				status = 3;
			else if (c == '/')
				status = 4;
			else if (isdigit(c)){
				int num = 0;
				while (isdigit(s[i]))
				{
					num = num * 10 + s[i] - '0';
					++i;
				}
				i--;
				switch (status)
				{
				case 1:
					term = num;
					break;
				case 2:
					term = -num;
					break;
				case 3:
					term *= num;
					break;
				case 4:
					term /= num;
				default:
					break;
				}
			}
		}
		return sum + term;
	}
};

void main(int argc, char* argv[]){
	cout << "Basic Calculator I: " << endl;
	vector<string> str1 = { "1 + 1", "2-1 + 2", "(15-(4+5+2)-3)+(6+8)" };
	Solution s;
	vector<int> res1(str1.size());
	for (int i = 0; i < str1.size(); i++)
		res1[i] = s.calculate1(str1[i]);
	for (int i = 0; i < str1.size(); i++)
		cout << str1[i] << " = " << res1[i] << endl;
	cout << endl << "Basic Calulator II: " << endl;
	vector<string> str2 = { "3+2*2", "3/2", "3+5 / 2* (1 +5)- 3*6/(2 +3)" };
	vector<int> res2(str2.size());
	for (int i = 0; i < str2.size(); i++)
		res2[i] = s.calculate2(str2[i]);
	for (int i = 0; i < str2.size(); i++)
		cout << str2[i] << " = " << res2[i] << endl;
	system("pause");
}