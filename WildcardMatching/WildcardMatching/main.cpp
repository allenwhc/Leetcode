/*
*	Wildcard Matching
*	Last Modified: 7/17/2015
*	Hint:
		1. Initialize two indices i,j for s,p respectively
		2. If s[i]=p[j], or p[j]='?', i++, j++
		3. If p[j]='*',
			1) Record the current position in s, p, save it as 'star', 'sMark'
			2) Move j to next character
				if p[j]!=s[i], i++, j remains invariable;
				else i++, j++
			3) If s reaches the end, still no match found in p, false
		4. Skip the last few '*'s
		5. Check if j reaches the end of p
			
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int i = 0, j = 0;
		int star = INT_MIN, sMark = INT_MIN;
		while (i < s.length()){
			if (j < p.length() && (s[i] == p[j] || p[j] == '?')){
				i++;
				j++;
			}
			else if (j < p.length() && p[j] == '*'){
				star = j;	//Record the position of '*'
				sMark = i;	//Record the position in s
				j++;
			}
			else if (star != INT_MIN){
				j = star + 1;
				i = ++sMark;
			}
			else return false;
		}
		while (j < p.length() && p[j] == '*') j++;
		return j == p.length();
	}
};

void main(int argc, char *argv[]){
	vector<string> str1 = { "aa", "aa", "dbcefg", "aa", "aa", "ab", "aab" };
	vector<string> str2 = { "a", "aa", "db*v", "*", "a*", "?*", "c*a*b" };
	int n = str1.size();
	Solution s;
	vector<bool> match(n, false);
	for (int i = 0; i < n; i++)
		match[i] = s.isMatch(str1[i], str2[i]);
	for (int i = 0; i < n; i++){
		if (match[i]) cout << "'" << str1[i] << "' matches '" << str2[i] << "'." << endl;
		else cout << "'" << str1[i] << "' doesn't match '" << str2[i] << "'." << endl;
	}
	system("pause");
}