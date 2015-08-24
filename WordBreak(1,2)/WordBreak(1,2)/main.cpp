/*
*	Word Break I & II
*	Last Modified: 7/7/2015
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution{
public:
	//Word Break I, determines if s can be segmented into a space-separated sequence of one or more dictionary words
	bool isWordBreak(string s, unordered_set<string>& wordDict){
		if (s.length() == 0) return wordDict.size() == 0;
		int n = s.length();
		vector<bool> t(n + 1);
		t[0] = true;
		for (int i = 0; i < n; i++){
			if (!t[i]) continue;	//If charAt[i] doesn't match, continue
			for (string a : wordDict){
				int len = a.length();
				int end = i + len;
				if (end > n) continue; //If reaches the last character
				if (t[end]) continue;	//If matches
				if (s.substr(i, end - i) == a) t[end] = true;
			}
		}
		return t[n];
	}

	//Word Break II, Return all such possible sentences
	vector<string> wordBreak(string s, unordered_set<string>& wordDict){
		string solution;
		vector<string> res;
		int n = s.size();
		vector<bool> possible(n + 1, true);
		dfs(0, n, possible, res, solution, s, wordDict);
		return res; 
	}

	void dfs(int start, int length, vector<bool>& possible, vector<string>& res, string& solution, string& s, unordered_set<string>& wordDict){
		if (start == length){
			res.push_back(solution.substr(0, solution.size() - 1));
			return;
		} 

		for (int i = start; i < length; i++){
			string segment = s.substr(start, i - start + 1);
			if (wordDict.find(segment) != wordDict.end() && possible[i+1]){
				solution.append(segment).append(" ");	//Insert space
				int segementLen = res.size();
				dfs(i + 1, length, possible, res, solution, s, wordDict);
				if (res.size() == segementLen) possible[i + 1] = false;
				solution.resize(solution.size() - segment.size() - 1); 
			}
		}
	}
};

void main(int argc, char* argv[]){
	string str = "catsanddog";
	unordered_set<string> dict = { "cat", "cats", "sand", "and", "dog" };
	Solution s;
	if (s.isWordBreak(str, dict)) cout << "'" << str << "' can be segmented." << endl;
	else cout << "'" << str << "' can't be segmented." << endl;
	vector<string> res = s.wordBreak(str, dict);
	for (int i = 0; i < res.size(); i++){
		cout << res[i];
		if (i != res.size() - 1) cout << ",";
	}
	cout << endl;
	system("pause");
}