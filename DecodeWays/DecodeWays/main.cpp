/*
*	Decode Ways
*	Last Modified: 7/26/2015
*/

#include <map>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		int len = s.length();
		if (len == 0) return 0;
		vector<int> noDecode(len + 1);
		noDecode[0] = 1;
		if (s[0] >= '1' && s[0] <= '9') noDecode[1] = 1;
		else return 0;
		int num = 0;
		for (int i = 1; i < len; i++){
			num = (s[i - 1] - '0') * 10 + s[i] - '0';
			//1<=s[i]<=9
			if (s[i] >= '1' && s[i] <= '9'){
				//If 10<=s[i-1]s[i]<=26
				if (num >= 10 && num <= 26)
					noDecode[i + 1] = noDecode[i] + noDecode[i - 1];
				//else
				else
					noDecode[i + 1] = noDecode[i];
			}
			//s[i]=0
			else{
				if (num >= 10 && num <= 26)
					noDecode[i + 1] = noDecode[i - 1];
				else return 0;
			}
		}

		//cout << num << endl;
		return noDecode[len];
	}
};

void main(int argc, char *argv[]){
	map<char, int> mp;
	for (int i = 0; i < 26; i++)
		mp[i + 'A'] = i + 1;
	string str = "1787897759966261825913315262377298132516969578441236833255596967132573482281598412163216914566534565";
	Solution sol;
	cout << "The number of ways decoding '" << str << "' is: " << sol.numDecodings(str);
	cout << endl;
	system("pause");
}