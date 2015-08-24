/*
*	Gray Code
*	Last Modified: 6/2/2015
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution{
public:
	vector<int> grayCode(int n){
		vector<int> gray;
		gray.push_back(0);
		for (int i = 0; i < n; i++)
		{
			int mostSignificantBit = 1 << i;
			int len = gray.size();
			for (int j = len - 1; j >= 0; j--)
			{
				gray.push_back(mostSignificantBit + gray[j]);
			}
		}
		return gray;
	}
};

void main(int argc, char*argv[]){
	int n;
	cout << "Please input a non-negative integer: ";
	cin >> n;
	vector<int> code;
	Solution s;
	code = s.grayCode(n);
	cout << "The Gray Code for a " << n << "-bit systems is: " << endl;
	for (int i = 0; i < code.size(); i++)
		cout << code[i] << endl;
	system("pause");
}