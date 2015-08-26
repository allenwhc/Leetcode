/*
*	Interleaving String
*	Last Modified: 7/24/2015
*	Hint:
	To build up such a table,
		1. Set A[0][0] = true. Period.
		2. Initialize the first row. The first row means whether s1[0 .. (n1-1)] matches s3[0 .. (n1-1)], correspondingly.
		3. Similarly, initialize the first column which means whether s2[0 .. (n2-1)] matches s3[0 .. (n2-1)], correspondingly.
		4. Now we fill up the table. For A[i][j], s3[0 .. (i+j-1)] match? s1[0 .. i-1] weaving s2[0 .. j-1]
				Note that A[i-1][j] comes from s1[0 .. i-2] weaving s2[0 .. j-1]. Thus, if it is true, we need to compare s1[i-1] with s3[i+j-1].
				Similarly, A[i][j-1] comes from s1[0 .. i-1] weaving s2[0 .. j-2]. Thus, if it is true, compare s2[j-1] with s3[i+j-1].
		5.Return A[n1][n2]
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int len1 = s1.length();
		int len2 = s2.length();
		if (s3.length() != len1 + len2) return false;
		vector<vector<bool>> valid(len1 + 1, vector<bool>(len2 + 1, false));
		valid[0][0] = true;
		//Initialize the first column, which means whether s1[0...len1-1] matches s3[0...len1-1]
		for (int i = 0; i < len1; i++){
			if (s1[i] == s3[i]) valid[i + 1][0] = valid[i + 1][0] | valid[i][0];
		}

		//Initialize the first row, which means whether s2[0...len2-1] matches s3[0...len2-1]
		for (int i = 0; i < len2; i++){
			if (s2[i] == s3[i]) valid[0][i + 1] = valid[0][i + 1] | valid[0][i];
		}

		for (int i = 0; i < len1; i++){
			for (int j = 0; j < len2; j++){
				if ((valid[i][j + 1] && s1[i] == s3[i + j + 1])
					|| (valid[i + 1][j] && s2[j] == s3[i + j + 1]))
					valid[i + 1][j + 1] = true;
			}
		}

		/*for (int i = 0; i <= len1; i++){
			for (int j = 0; j <= len2; j++)
				cout << valid[i][j] << " ";
			cout << endl;
		}*/
		return valid[len1][len2];
	}
};

void main(int argc, char* argv[]){
	string s1 = "db";
	string s2 = "b";
	string s3 = "cbb";
	Solution sol;
	if (sol.isInterleave(s1, s2, s3))
		cout << "'" << s3 << "' is formed by '" << s1 << "' and '" << s2 << "'." << endl;
	else
		cout << "'" << s3 << "' is not formed by '" << s1 << "' and '" << s2 << "'." << endl;
	system("pause");
}