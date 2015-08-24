/*
*	Regular Expression Matching
*	Last Modified: 7/1/2015
*/

#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	bool isMatch(string s, string p){
		if (p.length() == 0) return s.length() == 0;
		else if (p.length() == 1){
			if (s.length() == 0) return false;
			if (p[0] != s[0] && p[0] != '.') return false;
			else return isMatch(s.substr(1), p.substr(1));
		}
		else{
			if (p[1] != '*'){
				if (s.length() == 0) return false;
				if (p[0] != s[0] && p[0] != '.') return false;
				else return isMatch(s.substr(1), p.substr(1));
			}
			else{
				//cout << p << endl;
				if (isMatch(s, p.substr(2))) return true;
				int i = 0;
				while (i < s.length() && (s[i] == p[0] || p[0] == '.')){
					if (isMatch(s.substr(i + 1), p.substr(2))) return true;
					i++;
				}
				return false;
			}
		}
	}
};

void main(int argc, char *argv[]){
	string s = "aab";
	string p = "c*a*b";
	Solution sol;
	bool match = sol.isMatch(s, p);
	cout << p;
	if (match) cout << " matches ";
	else cout << " does not match ";
	cout << s << endl;
	system("pause");
}