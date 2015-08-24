/*
*	Scramble String
*	Last Modified: 7/2/2015
*/

#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	bool isScramble(string s1, string s2){
		if (s1.length() != s2.length()) return false;
		if (s1 == s2) return true;
		int size = s1.length(); 
		int v1 = 0, v2 = 0;

		//Checks if two strings has the same letter combinations
		for (int i = 0; i < size; i++){
			v1 = v1 + (s1[i] - 'a');
			v2 = v2 + (s2[i] - 'a');
		}
		if (v1 != v2) return false;	

		for (int i = 1; i < size; i++){
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) return true;
			if (isScramble(s1.substr(0, i), s2.substr(size - i)) && isScramble(s1.substr(i), s2.substr(0, size - i))) return true;
		}
		return false;
	}
};

void main(int argc, char* argv[]){
	string s1 = "abc";
	string s2 = "bca";
	string s3 = "cba";
	Solution s;
	bool isScramble1 = s.isScramble(s1, s2);
	bool isScramble2 = s.isScramble(s1, s3);
	if (isScramble1){
		if (isScramble2) cout << s2 << " and " << s3 << " are both scramble strings of " << s1 << endl;
		else cout << s2 << " is a scramble string of " << s1 << ", while " << s3 << " is not" << endl;
	}
	else{
		if (isScramble2) cout << s3 << " is a scramble string of " << s1 << ", while " << s1 << " is not" << endl;
		else cout << s2 << " and " << s3 << " are both not scramble strings of " << s1 << endl;
	}
	system("pause");
}