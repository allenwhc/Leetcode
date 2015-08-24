/*
*	Text Justification
*	Last Modified: 7/17/2015
*	Hint: Greedy approach
		1. In each line, count the number of words being placed
		2. If there is only one word in that line, or already reach the last word,
		then no spaces will be added to the left or in between. 
		Else, set avgSpace=(L-len)/(i-end-1), leftSpace=(L-len)%(i-end-1)
		3. Construct a new string:
			1) Add a word to the string
			2) Add spaces (avgSpaces) after the word
			3) Add left spaces of the next word
			4) Repeat 1)-3) until reach the last word
			5) Add the last word
			6) Add trailing spaces to the string
		4. Add the string to the result vector
		5. Clear the current length, and start a new line (Repeat 1-4)
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> res;
		int n = words.size();
		if (n == 0) return res;
		vector<int> level;
		int len = 0, end = -1;
		int i = 0;
		while (i < n){
			while (i < n && len + words[i].length() <= maxWidth){
				len += words[i].length() + 1;
				i++;
			}
			i--;
			len--;	//Delete the space at the last position
			string str = "";
			int avgSpace = 0;
			int leftSpace = 0;

			//If only one word in the line, or reach the last word
			if (i == end + 1 || i == n - 1){
				avgSpace = 0;	//No in-between spaces
				leftSpace = 0;	//No left spaces
			}
			else{
				avgSpace = (maxWidth - len) / (i - end - 1);
				leftSpace = (maxWidth - len) % (i - end - 1);
			}

			for (int j = end + 1; j < i; j++){
				str.append(words[j]);	//Add the 1...i-1 words
				for (int k = 0; k < avgSpace + 1; k++)
					str.append(" ");	//Add spaces between words
				if (leftSpace != 0){
					str.append(" ");	//Add space at the end of the line
					leftSpace--;
				}
			}

			str.append(words[i]);	//Add the last word in the line
			int padLast = maxWidth - str.length();	//Get the spcae after the last word
			for (int t = 0; t < padLast; t++)
				str.append(" ");	//Add trailing spaces
			res.push_back(str);	//Add to result
			end = i++;	//Start	a new line
			len = 0;	//Clear len
		}
		return res;
	}
};

void main(int argc, char *argv[]){
	vector<string> word = { "Michael", "Jordan", "is", "no", "doubt", "the", "greatest", "player", "of", "all", "time", "in", "NBA" };
	cout << "The original string array is: " << endl;
	for (int i = 0; i < word.size(); i++){
		cout << word[i];
		if (i != word.size() - 1) cout << " ";
		else cout << ".";
	}
	cout << endl;
	int maxWidth = 16;
	Solution s;
	vector<string> res = s.fullJustify(word, maxWidth);
	cout << "The jusitified string array is:" << endl;
	for (int i = 0; i < res.size(); i++){
		cout << res[i];
		cout << endl;
	}
	system("pause");
}