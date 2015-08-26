/*
*	Isomorphic Strings
*	Last Modified: 7/13/2015
*/

#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution{
public:
	bool isIsomorphic(string s, string t){
		int m = s.length();
		map<char, char> mp1, mp2;
		for (int i = 0; i < m; i++){
			char cs = s[i];
			char ct = t[i];
			if (mp1.find(cs) != mp1.end()){
				if (mp1[cs] != ct) return false;
			}
			if (mp2.find(ct) != mp2.end()){
				if (mp2[ct] != cs) return false;
			}
			mp1[cs] = ct;
			mp2[ct] = cs;
		}
		return true;
	}
};

void main(int argc, char* argv[]){
	vector<string> str1 = { "egg", "foo", "paper" };
	vector<string> str2 = { "add", "bar", "title" };
	vector<bool> isomorphic(str1.size());
	Solution s;
	for (int i = 0; i < str1.size(); i++)
		isomorphic[i] = s.isIsomorphic(str1[i], str2[i]);
	for (int i = 0; i < str1.size(); i++){
		cout << "'" << str1[i] << "' and '" << str2[i] << "' are ";
		if (isomorphic[i]) cout << "isomorphic strings." << endl;
		else cout << "not isomorphic strings." << endl;
	}
	system("pause");
}