/*
*	Substring with Concatenation of All Words
*	Last Modified: 7/8/2015
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
	vector<int> findSubstring(string s, vector<string>& words){
		vector<int> res;
		int m = words.size();
		int n = words[0].length();
		if (m == 0) return res;
		map<string, int> mp;
		for (int i = 0; i < m; i++)
		{
			mp[words[i]]++;
		}
		int i = 0;
		while (i + m*n <= s.length()){
			map<string, int> mp2;
			int j = 0;
			while (j < m){
				string str = s.substr(i + j * n, n);
				if (mp.find(str) != mp.end()){
					mp2[str]++;
					if (mp2[str] > mp[str]) break;	//Checks if the same word happens more than once
				}
				else break;
				j++;
			}
			if (j == m) res.push_back(i);
			i++;
		}
		return res;
	}
};

void main(int argc, char* argv[]){
	string str = "barfoothefoobarman";
	vector<string> words = { "foo", "bar" };
	Solution s;
	cout << "The starting index of ";
	for (int i = 0; i < words.size(); i++) cout << words[i] << " ";
	cout << "in '" << str << "' are: ";
	for (int i = 0; i < s.findSubstring(str, words).size(); i++) cout << s.findSubstring(str, words)[i] << " ";
	cout << endl;
	system("pause");
}