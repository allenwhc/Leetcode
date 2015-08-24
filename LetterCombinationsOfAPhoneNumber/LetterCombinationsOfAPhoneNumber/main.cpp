/*
*	Letter Combinations of A Phone Number
*	Last Modified: 7/1/2015
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
	vector<string> letterCombinations(string digits){
		vector<string> dict = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string> combo;
		int n = digits.length();
		if (n == 0) return combo;
		string sequence(n, ' ');
		generate(digits, dict, combo, sequence, 0);
		return combo;
	}
	
	void generate(string& digits, vector<string>& dict, vector<string>& combo, string& sequence, int index){
		if (index == digits.length()){
			combo.push_back(sequence);
			return;
		}
		for (int i = 0; i < dict[digits[index] - 48].length(); i++){
			//cout << "i=" << i << ", index=" << index << endl;
			sequence[index] = dict[digits[index] - 48][i];
			generate(digits, dict, combo, sequence, index + 1);
		}
	}
};

void main(int argc, char* argv[]){
	string digits = "79";
	Solution s;
	vector<string> letter = s.letterCombinations(digits);
	cout << "The input digits is: " << digits << endl;
	cout << "The letter combinations are: " << endl;
	for (int i = 0; i < letter.size(); i++){
		cout << letter[i];
		if (i != letter.size() - 1) cout << ",";
	}
	cout << endl;
	system("pause");
}