/*
*	Reverse Words in a String
*	Last Modified: 7/20/2015
*/

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		istringstream iss(s);
		string words = "";
		vector<string> getWords;
		string save = "";
		while (getline(iss, words, ' ')){
			if (!words.empty())
				getWords.push_back(words);
		}
		while (!getWords.empty()){
			save += getWords.back() + " ";
			getWords.pop_back();
		}
		s = save;
		s = s.substr(0, s.length() - 1);
	}
};

void main(int argc, char* argv[]){
	string str = "   time  all    of      greatest the   ";
	//string str = "hello world!";
	string ss = str;
	Solution s;
	s.reverseWords(str);
	cout << "'" << ss << "' is reversed to '" << str << "'" << endl;
	system("pause");
}