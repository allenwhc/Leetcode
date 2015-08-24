/*
*	Different Ways to Add Parentheses
*	Last Modified: 7/27/2015
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {

	}
};

void main(int argc, char* argv[]){
	string input = "2*3-4*5";
	Solution sol;
	cout << "The input string is '" << input << "' " << endl;
	vector<int> res = sol.diffWaysToCompute(input);
	cout << "All possible result if inserting parentheses in different places are: ";
	for (int t : res)
		cout << t << " ";
	cout << endl;
	system("pause");
}
