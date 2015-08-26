/*
*	Excel Sheet Column Number
*	Last Modified: 7/13/2015
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution{
public:
	int titleToNumber(string s){
		int res = 0;
		for (int i = 0; i < s.length(); i++){
			res = res * 26 + s[i] - 64;
		}
		return res;
	}
};

void main(int argc, char* argv[]){
	vector<string> titles = { "A", "AB", "ACD" };
	Solution s;
	vector<int> nums(titles.size());
	for (int i = 0; i < titles.size(); i++)
		nums[i] = s.titleToNumber(titles[i]);
	for (int i = 0; i < titles.size(); i++){
		cout << "The column number of title '" << titles[i] << "' is: " << nums[i] << endl;
	}
	system("pause");
}