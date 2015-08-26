/*
*	Count and Say
*	Last Modified: 8/5/2015
*/

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		if (n <= 0) return "";
		string res = "1";
		
		for (int i = 1; i < n; i++){
			int count = 1;
			string str = "";
			for (int j = 0; j < res.size() - 1; j++){
				if (res[j] == res[j + 1])
					count++;
				else{
					str.push_back(char(count + '0'));
					str.push_back(res[j]);
					count = 1;
				}
			}
			str.push_back(char(count + '0'));
			str.push_back(res[res.length() - 1]); 
			res = str;
		}
		return res;
	}
};

void main(){
	int n = 20;
	Solution sol;
	cout << "The expression for the " << n << "th sequence is: " << sol.countAndSay(n) << endl;
	system("pause");
}