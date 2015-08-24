/*
*	Valid Anagram
*	Last Modified: 8/3/2015
*/

#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.length() != t.length()) return false;
		int len = s.length();
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		if (s.compare(t) != 0) return false;
		return true;
	}
};

void main(){
	string s = "bnagram";
	string t = "nagaram";
	Solution sol;
	if (sol.isAnagram(s, t)) cout << "'" << t << "' is an anagram of '" << s << "'. " << endl;
	else cout << "'" << t << "' is not an anagram of '" << s << "'. " << endl;
	system("pause");
}