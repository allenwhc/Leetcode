/*
*	Palindrome Partitioning I & II
*	Last Modified: 7/6/2015
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
	//Palindrome Partitioning I, return all possible palindrome partitioning of s
	vector<vector<string>> partition(string s){
		vector<vector<string>> res;
		vector<string> palindrome;
		DFS(s, 0, res, palindrome);
		return res;
	} 

	void DFS(string& s, int step, vector<vector<string>>& res, vector<string>& palindrome){
		if (step == s.size()){
			res.push_back(palindrome);
			return;
		}
		for (int i = step; i < s.size(); i++){
			if (isPalindrome(s,step,i)){
				palindrome.push_back(s.substr(step, i - step + 1));
				DFS(s, i + 1, res, palindrome);
				palindrome.pop_back();
			}
		}
	}

	//Palindrome Partitioning II, return the minimum cuts needed for a palindrome partitioning
	int minCut(string s){
		if (s.length() == 0) return 0;
		int n = s.length();
		vector<int> cut(n);
		vector<vector<bool>> isPalin(n, vector<bool>(n, false));

		for (int i = 0; i < n; i++){
			cut[i] = i;	//Maximum cuts
			for (int j = 0; j <= i; j++){
				if (s[i] == s[j] && (i - j < 2 || isPalin[j + 1][i - 1])){
					isPalin[j][i] = true;
					if (j>0) cut[i] = min(cut[i], cut[j - 1] + 1);	//If needs cut, get smaller cut 
					else cut[i] = 0;
				}
			}
		}
		return cut[n - 1];
	}


private:
	bool isPalindrome(string& s, int start, int end){
		while (start < end){
			if (s[start] != s[end]) return false;
			start++;
			end--;
		}
		return true;
	}
};

void main(int argc, char* argv[]){
	string str = "aaabbabb";
	Solution s;
	cout << "The input string is: " << str << endl;
	cout << "The minimum cuts needed for a palindrome partitioning is: " << s.minCut(str) << endl;
	vector<vector<string>> res = s.partition(str);
	cout << "All possible palindrome partitionings are: " << endl;
	cout << "[" << endl;
	for (int i = 0; i < res.size(); i++){
		cout << "[";
		for (int j = 0; j < res[i].size(); j++){
			cout << res[i][j];
			if (j != res[i].size() - 1) cout << ",";
		}
		cout << "]";
		if (i != res.size() - 1) cout << ",";
		cout << endl;
	}
	cout << "]" << endl;
	system("pause");
}