/*
*	Longest Palindromic Substring
*	Last Modified: 7/2/2015
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
	string longestPalindrome(string s){
		string res = "";
		if (s.length() == 0 || s.length() == 1) return s;
		res = addBoundary(s);	//Adds '|' to the input array
		int len = res.size();
		vector<int> P(len);
		int center = 0;	//Position of the center of palindrome currently known to include a boundary closest to the right end of res
		int rightMost = 0; //Position of the right-most boundary of this palindrome

		for (int i = 1; i < len - 1; i++){
			//cout << "center=" << center << ", RightMost=" << rightMost << endl;
			int i_mirror = 2 * center - i;
			P[i] = (rightMost>i) ? min(rightMost - i, P[i_mirror]) : 0;
			
			//Attempts to expand palindrome centered at i
			while (res[i + (1 + P[i])] == res[i - (1 + P[i])]) P[i]++;

			//If palindrome centered at i expand beyond rightMost
			//adjusts center based on expanded palindrome
			if (i + P[i] > rightMost){
				center = i;
				rightMost = i + P[i];
			}
		}

		//Finds the maximum element in P
		int maxLen = INT_MIN;
		int centerIndex = 0;
		for (int i = 1; i < len - 1; i++){
			if (P[i]>maxLen){
				centerIndex = i;
				maxLen = P[i];
			}
		}
		string ret = s.substr((centerIndex - 1 - maxLen) / 2, maxLen);
		return ret;
	}

	//Adds boundary '|' to the tail of every character in the string
	string addBoundary(string s){
		int n = s.length();
		if (n == 0) return "^$";
		string s2 = "^";
		for (int i = 0; i < n; i++){
			s2 += "|" + s.substr(i, 1);
		}
		s2 += "|$";
		return s2;
	}
};

void main(int argc, char* argv[]){
	string str = "bb";
	Solution s;
	string longest = s.longestPalindrome(str);
	cout << "The longest palindromic substring of " << str << " is: " << longest << endl;
	system("pause");
}