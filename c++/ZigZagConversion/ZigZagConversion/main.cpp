/*
*	ZigZag Conversion
*	Last Modified: 7/6/2015
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
	string convert(string s, int numRows){
		if (s.length() == 0) return "";
		if (numRows <= 1) return s;
		int n = s.length();
		string res;

		for (int i = 0; i < numRows; i++){
			for (int j = 0, index = i; index < n; j++, index = (2 * numRows - 2)*j + i){
				res.append(1, s[index]);
				if (i == 0 || i == numRows - 1) continue;
				if (index + (numRows - i - 1) * 2 < n) res.append(1, s[index + (numRows - i - 1) * 2]);
			}
		}
		return res;
	}
};

void main(int argc, char* argv[]){
	string str = "PAYPALISHIRING";
	int n = 4;
	Solution s;
	cout << "The ZigZag conversion for " << str << " with " << n << " rows is: " << s.convert(str, n) << endl;
	system("pause");
}