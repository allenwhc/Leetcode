/*
*	Longest Valid Parentheses
*	Last Modified: 7/26/2015
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int len = s.length();
		if (len <= 1) return 0;
		int maxLen = 0;
		int last = -1;
		stack<int> stk;
		for (int i = 0; i < len; i++){
			if (s[i] == '(')
				stk.push(i);
			else{
				if (stk.empty())
					last = i;
				else{
					stk.pop();
					if (stk.empty())
						maxLen = max(maxLen, i - last);
					else
						maxLen = max(maxLen, i - stk.top());
				}
			}
		}
		return maxLen;
	}
};

void main(int argc, char* argv[]){
	vector<string> str = { "(()", ")()()", "(())()()" }; 
	Solution sol;
	vector<int> lengths(str.size());
	for (int i = 0; i < str.size(); i++)
		lengths[i] = sol.longestValidParentheses(str[i]);
	for (int i = 0; i < str.size(); i++){
		cout << "The longest valid parentheses length of '" << str[i] << "' is " << lengths[i] << endl;
	}
	system("pause");
}