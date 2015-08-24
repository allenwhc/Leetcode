/*
*	Distinct Subsequences
*	Last Modified: 7/23/2015
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		int len1 = s.length();
		int len2 = t.length();
		if (len1 == 0) return 0;
		vector<vector<int>> noChars(len1 + 1, vector<int>(len2 + 1, 0));	//Indicating the number of charaters at s[i] and t[j]
		int rows = noChars.size();
		int cols = noChars[0].size();

		//Intialize the first row
		//No matter what t is, if s deletes its first character, there will be no match.
		//Hence, when i=0, the number of characters will always be 1
		for (int i = 0; i < rows; i++)
			noChars[i][0] = 1;		

		for (int i = 1; i < rows; i++){
			for (int j = 1; j < cols; j++){
				noChars[i][j] = noChars[i - 1][j];	//No matter what the current char in s is, we don't use it
				if (s[i - 1] == t[j - 1]) noChars[i][j] += noChars[i - 1][j - 1];	//If the last character matches, it means we can use all the solutions before
			}
		}
		/*for (vector<int> cc : noChars){
			for (int ccc : cc)
				cout << ccc << " ";
			cout << endl;
		}*/
		return noChars[len1][len2];
	}
};

void main(int argc, char *argv[]){
	string ss = "rabbbit";
	string tt = "rabbit";
	Solution s;
	cout << "There are " << s.numDistinct(ss, tt) << " distinct subsequences of '" << tt << "' in '" << ss << "'." << endl;
	system("pause"); 
}