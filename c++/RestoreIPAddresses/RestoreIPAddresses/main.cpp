/*
*	Restore IP Addresses
*	Last Modified: 7/20/2015
*/

#include <string>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> ip;
		string fragment;
		getIPAddresses(s, ip, fragment, 0, 0);
		return ip;
	}

	void getIPAddresses(string s, vector<string>& ip, string fragment, int start, int step){
		if (start == s.length() && step == 4){
			fragment.erase(fragment.length() - 1);
			ip.push_back(fragment);
			return;
		}


	}
};

void main(int argc, char *argv[]){
	//string str = "25525511135";
	string str = "010010";
	Solution s;
	cout << "The IP addresses could be: " << endl;
	for (string ss : s.restoreIpAddresses(str))
		cout << ss << endl;
	system("pause");
}