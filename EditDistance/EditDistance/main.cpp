/*
*	Edit Distance
*	Last Modified: 6/23/2015
*/

#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution{
public:
	int minDistance(string word1, string word2){
		int len1 = word1.length();
		int len2 = word2.length();
		//Declares a 2D dynamic array
		int** dp = new int*[len1 + 1];
		for (int i = 0; i < len1 + 1; i++)
			dp[i] = new int[len2 + 1];

		//Initializes the 2D array
		for (int i = 0; i < len1 + 1; i++)
			dp[i][0] = i;
		for (int i = 0; i < len2 + 1; i++)
			dp[0][i] = i;

		//Calculates the steps needed for conversion
		for (int i = 0; i < len1; i++){
			char c1 = word1[i];
			for (int j = 0; j < len2; j++){
				char c2 = word2[j];

				if (c1 == c2){ //Checks if c1=c2
					dp[i + 1][j + 1] = dp[i][j];
				}
				else{
					int replacement = dp[i][j] + 1;
					int deletion = dp[i + 1][j] + 1;
					int insertion = dp[i][j + 1] + 1;
					int minimum = min(replacement, deletion);
					minimum = min(minimum, insertion);
					dp[i + 1][j + 1] = minimum;
				}
			}
		}
		return dp[len1][len2];
	}
};

void main(int argc, char *argv[]){
	string word1 = "hello";
	string word2 = "hola";
	Solution s;
	int distance = s.minDistance(word1, word2);
	cout << "The minimum number of steps to change '" << word1 << "' to '" << word2 << "' is: " << distance << endl;
	system("pause");
}