/*
*	Different Ways to Add Parentheses
*	Last Modified: 8/5/2015
*/

#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> result;

		//Convert char to int
		int val = 0;
		int idx = 0;
		for (; idx < input.length() && isdigit(input[idx]); idx++)
			val = val * 10 + input[idx] - '0';
		
		if (idx == input.length())
			return { val };
		
		//Divide and Conquer
		vector<int> left, right;
		for (int i = 0; i < input.length(); i++){
			if (!isdigit(input[i])){
				left = diffWaysToCompute(input.substr(0, i));
				right = diffWaysToCompute(input.substr(i + 1, input.length() - 1 - i));
				for (int j = 0; j < left.size(); j++){
					for (int k = 0; k < right.size(); k++){
						switch (input[i])
						{
						case '*':
							result.push_back(left[j] * right[k]);
							break;
						case '-':
							result.push_back(left[j] - right[k]);
							break;
						case '+':
							result.push_back(left[j] + right[k]);
							break;
						default:
							break;
						}
					}
				}
			}
		}
		return result;
	}
};

void main(){
	string input = "2*3-4*5";
	Solution sol; 
	cout << "The results compute '" << input << "' adding parentheses are: ";
	for (int x : sol.diffWaysToCompute(input))
		cout << x << ",";
	cout << endl;
	system("pause");
}