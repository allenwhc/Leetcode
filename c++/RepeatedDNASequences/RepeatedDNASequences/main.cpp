/*
*	Repeated DNA Sequences
*	Last Modified: 7/16/2015
*/

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
	vector<string> findRepatedDnaSequences(string s){
		vector<string> res;
		int len = s.size();
		if (len <= 10) return res;
		unordered_map<unsigned long, int> hmap;
		int mask = 0xfffff;	//Set lower 20 bits to '1's
		int curNum = 0;
		for (int i = 0; i < 9; i++){
			char c = s[i];
			curNum = (curNum << 2) | (c - 'A' + 1) % 5;
		}
		
		for (int i = 9; i < len; i++){
			char c = s[i];
			if (hmap[curNum = (curNum << 2 | (c - 'A' + 1) % 5) & mask]++ == 1)
				res.push_back(s.substr(i - 9, 10));
		}
		return res;
	}
};

void main(int argc, char *argv[]){
	string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	cout << "The input DNA sequence is: " << str << endl;
	Solution s;
	cout << "The repeated DNA sequences are: ";
	vector<string> res = s.findRepatedDnaSequences(str); 
	for (string ss : res)
		cout << ss << " ";
	system("pause");
}