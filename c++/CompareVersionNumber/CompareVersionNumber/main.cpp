/*
*	Compare Version Numbers
*	Last Modified: 7/20/2015
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution { 
public:
	int compareVersion(string version1, string version2) {
		int len1 = version1.length();
		int len2 = version2.length();
		int num1, num2, i = 0, j = 0;
		for (; i < len1 || j < len2; i++, j++){
			num1 = 0;
			while (i < len1 && version1[i] != '.'){
				num1 = num1 * 10 + version1[i] - '0';
				i++;
			}
			num2 = 0;
			while (j < len2 && version2[j] != '.'){
				num2 = num2 * 10 + version2[j] - '0';
				j++;
			}
			if (num1 < num2) return -1;
			else if (num1 > num2) return 1;
		}
		return 0;
	}
};

void main(int argc, char *argv[]){
	vector<string> str1 = { "01.3", "0.4", "31.1", "10.52" };
	vector<string> str2 = { "1.2", "0.42", "31.02", "9.522" };
	vector<int> res(str1.size());
	Solution s;
	for (int i = 0; i < str1.size(); i++)
		res[i] = s.compareVersion(str1[i], str2[i]);
	for (int i = 0; i < str1.size(); i++){
		if (res[i] == 1) cout << "v" << str1[i] << "is later than v" << str2[i] << "." << endl;
		else if (res[i] == -1) cout << "v" << str1[i] << "is earlier than v" << str2[i] << "." << endl;
		else cout << "Same version or invalid comparison." << endl;
	}
	system("pause");
}