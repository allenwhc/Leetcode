/*
*	Length of Last Word
*	Last Modified: 6/29/2015
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
	int lengthOfLastWord(string s){
		int n = s.length();
		if (n == 0) return 0;
		int count = 0;
		int start = n - 1;
		for (int i = n - 1; i >= 0; i--){
			if (s[i] == ' '){
				start--;
			}
			else break;
		}
		for (int i = start; i >= 0; i--){
			if (s[i] != ' '){
				count++;
			}
			else break;
		}
		return count;
	}
};

void main(int argc, char* argv[]){
	string str = " a";
	Solution s;
	int len = s.lengthOfLastWord(str);
	cout << "The length of last word in the string is: " << len << endl;
	system("pause");
}