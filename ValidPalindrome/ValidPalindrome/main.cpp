/*
*	Valid Palindrome
*	Last Modified: 7/7/2015
*/

#include <string>
#include <ctype.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
	bool isPalindrome(string s){
		int n = s.length();
		if (n == 0) return true;
		vector<char> str;
		char c;
		int j = 0;
		while (s[j]){
			s[j] = tolower(s[j]);
			j++;
		}
		for (int i = 0; i < n; i++){
			if (s[i] >= 'a' && s[i] <= 'z') str.push_back(s[i]);
			if (s[i] >= '0' && s[i] <= '9') str.push_back(s[i]);
		}
		int start = 0;
		int end = str.size() - 1;
		while (start < end){
			if (str[start] != str[end]) return false;
			start++;
			end--;
		}
		return true;
	}
};

void main(int argc, char* argv[]){
	string s1 = "A man, a plan, a canal: Panama";
	string s2 = " apG0i4maAs::sA0m4i0Gp0";
	Solution s;
	if (s.isPalindrome(s1) && s.isPalindrome(s2)) cout << "'" << s1 << "' and '" << s2 << "' are both palindrome." << endl;
	if (s.isPalindrome(s1) && !s.isPalindrome(s2)) cout << "'" << s1 << "' is palindrome, while '" << s2 << "' is not." << endl;
	if (!s.isPalindrome(s1) && s.isPalindrome(s2)) cout << "'" << s2 << "' is palindrome, while '" << s1 << "' is not." << endl;
	if (!s.isPalindrome(s1) && !s.isPalindrome(s2)) cout << "Neither '" << s1 << "' nor '" << s2 << "' is palindrome." << endl;
	system("pause");
}