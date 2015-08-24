/*
*	Minimum Window Substring
*	Last Modified: 7/28/2015
*	Hint:
		Count characters in t (mapt)
		initialize left,count,minLen
		for each char in s
			if s[i] is in hmapt 
				if s[i] is in hmaps 
					if hmaps[s[i]]<hmapt[s[i]]
						count++
					hmaps[s[i]]++
				else
					hmaps[s[i]]=1
					count++
			if count equals length of t
				while s[left] isn't in hmapt or hmapt[s[left]]<hmaps[s[left]]
					if s[left] is in hmaps or hmapt[s[left]]<hmaps[s[left]]
						hmaps[s[left]]--
					left++
					update s[left]
				if current substring length is less than minLen
					get that substring
					update minLen
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		int sLen = s.length(), tLen = t.length();
		if (sLen == 0 || tLen == 0 || sLen < tLen) return "";
		string result = ""; 
		unordered_map<char, int> countCharT;
		unordered_map<char, int> countCharS;

		//Count the number of appearance for different character in t
		for (int i = 0; i < tLen; i++)
			countCharT[t[i]]++;
		
		//Scan s
		int count = 0;	//mapped character
		int left = 0;	//left side of window
		int minLen = sLen + 1;	//right side of window
		for (int i = 0; i < sLen; i++){
			char c = s[i];
			if (countCharT.find(c) != countCharT.end()){
				if (countCharS.find(c) != countCharS.end()){
					if (countCharS[c] < countCharT[c])
						count++;
					countCharS[c]++;
				}
				else{
					countCharS[c] = 1;
					count++;
				}
			}

			//If the matched substring is found
			if (count == tLen){
				char cc = s[left];
				while (countCharT.find(cc) == countCharT.end() || countCharT[cc] < countCharS[cc]){
					if (countCharS.find(cc) != countCharS.end() && countCharS[cc] > countCharT[cc]){
						countCharS[cc]--;
					}
					left++;
					cc = s[left];
				}

				if (i - left + 1 < minLen){
					result = s.substr(left, i - left + 1);
					minLen = i - left + 1;
				}
			}
		}
		return result;
	}
};

void main(int argc, char*argv[]){
	string s = "ADOBECODEBANC";
	string t = "ABC";
	Solution sol;
	cout << "The minimum string in '" << s << "' that contains '" << t << "' is: '" << sol.minWindow(s, t) << "'." << endl;
	system("pause");
}