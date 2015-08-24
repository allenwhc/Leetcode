/*
*	Shortest Palindrome
*	Last Modified: 7/13/2015
*/

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution{
public:
	string shortestPalindrome(string s){
		string rev_s = s;
		reverse(rev_s.begin(), rev_s.end());
		string l = s + "#" + rev_s;	
		
		vector<int> p(l.length(), 0);
		for (int i = 1; i < l.length(); i++){
			int j = p[i - 1];
			while (j>0 && l[i] != l[j]) 
				j = p[j - 1];
			if (l[i] == l[j]) j++;
			p[i] = j;
		}
		return rev_s.substr(0, s.length() - p[l.length() - 1]) + s;
	}
};

void main(int argc, char* argv[]){
	vector<string> str = { "ab", "abcd" };
	Solution s;
	vector<string> result(str.size());
	for (int i = 0; i < str.size(); i++)
		result[i] = s.shortestPalindrome(str[i]);

	for (int i = 0; i < str.size(); i++){
		cout << "The shortest palindrome formed from '" << str[i] << "' is: '" << result[i] << "'" << endl;
	}
	system("pause");
}