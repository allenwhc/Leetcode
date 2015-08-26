/*
*	Longest Common Prefix
*	Last Modified: 6/24/2015
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
	string longestCommonPrefix(vector<string>& strs){
		if (strs.size() == 0) return "";
		string str0 = strs[0];
		for (int i = 0; i < strs[0].length(); i++){
			char c0 = str0[i];
			for (int j = 1; j < strs.size(); j++){
				string strj = strs[j];
				char cij = strj[i];
				if (c0 != cij || i >= strs[j].length()) return strs[j].substr(0, i);
			}
		}
		return strs[0];
	}
};

void main(int argc, char argv[]){
	vector<string> strs = { "abcdef", "abcdcsa", "abcthe", "abcden" };
	Solution s;
	string common = s.longestCommonPrefix(strs);
	cout << "The longest common prefix is: " << common << endl;
	system("pause");
}