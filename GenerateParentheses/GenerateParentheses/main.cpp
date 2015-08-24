/*
*	Generate Parentheses
*	Last Modified: 6/24/2015
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
	vector<string> generateParenthesis(int n){
		vector<string> parentheses;
		if (n <= 0) return parentheses;
		string s;
		pairParentheses(parentheses, s, 0, n, 0, 0);
		return parentheses;
 	}

	void pairParentheses(vector<string>& parenthese, string& s, int depth, int n, int leftNum, int rightNum){
		//If reaches the last char of the string, pushes back the solution
		if (depth == 2 * n){
			parenthese.push_back(s);
			return;
		}

		//If # of left parenthesis is less than n, then adds new left parenthesis
		if (leftNum < n){
			s.push_back('(');
			pairParentheses(parenthese, s, depth + 1, n, leftNum + 1, rightNum);
			s.resize(s.size() - 1);
		}

		//If # of right parenthesis is less the # of left parenthesis, then adds new right parenthesis
		if (leftNum > rightNum){
			s.push_back(')');
			pairParentheses(parenthese, s, depth + 1, n, leftNum, rightNum + 1);
			s.resize(s.size() - 1);
		}
	}
};

void main(int argc, char *argv[]){
	int n;
	cout << "Input the number of well-formed parentheses: ";
	cin >> n;
	Solution s;
	vector<string> result = s.generateParenthesis(n);
	cout << "The solution is: " << endl;
	for (int i = 0; i < result.size(); i++){
		cout << result[i];
		if (i != result.size() - 1) cout << ",";
	}
	cout << endl;
	system("pause");
}