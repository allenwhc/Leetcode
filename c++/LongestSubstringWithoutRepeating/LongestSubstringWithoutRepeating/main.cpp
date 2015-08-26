/*
*	Longest Substring Without Repeating Characters
*	Last Modified: 7/15/2015
*/
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
	int lengthOfLongestSubstring(string s){
		int n = s.length();
		if (n == 0) return 0;
		int cur_len = 1;
		int max_len = 1;
		int prev_index = -1;
		int i;
		unordered_map<char, int> visited;
		for (int i = 0; i < n; i++)
			visited[s[i]] = -1;		//Mark all characters as unvisited
		visited[s[0]] = 0;	//Mark the first character as visited
		for (int i = 1; i < n; i++){
			prev_index = visited[s[i]];

			//If the current character is not presented in the already processed substr or
			//it's not part of the current non repeating substring, increment cur_len
			if (prev_index == -1 || i - cur_len > prev_index)
				cur_len++;

			else{
				max_len = max(max_len, cur_len);
				cur_len = i - prev_index;
			}
			visited[s[i]] = i;	//Mark the character as visited
		}
		max_len = max(max_len, cur_len);
		return max_len;
	}
};

void main(int argc, char *argv[]){
	string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ a";
	cout << "The string is: " << str << endl;
	Solution s;
	int length = s.lengthOfLongestSubstring(str);
	cout << "The length of the longest non-repeating substring is: " << length << endl;
	system("pause");
}