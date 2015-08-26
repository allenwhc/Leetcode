/*
*	Excel Sheet Column Title
*	Last Modified: 7/23/2015
*/

#include <string>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		if (n <= 0) return "";
		string res = "";
		stack<char> letter;
		while (n > 0){
			char c = 'A' + (n - 1) % 26;
			letter.push(c);
			n = (n - 1) / 26;
		}
		while (!letter.empty()){
			res.push_back(letter.top());
			letter.pop();
		}
		return res;
	}
};

void main(int argc, char *argv[]){
	vector<int> n = { 1, 28, 546 };
	Solution s; 
	vector<string> titles(n.size());
	for (int i = 0; i < n.size(); i++)
		titles[i] = s.convertToTitle(n[i]);
	for (int i = 0; i < n.size(); i++)
		cout << n[i] << " -> " << titles[i] << endl;
	system("pause");

}