/*
*	Permutation Sequence
*	Last Modified: 7/8/2015
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
	string getPermutation(int n, int k){
		vector<int> fac(n, 1);
		vector<char> c(n, 1);

		for (int i = 1; i < n; i++)
			fac[i] = fac[i - 1] * i;
		for (int i = 0; i < n; i++)
			c[i] = i + 1 + '0';
		k = k - 1;
		string result = "";
		for (int i = n; i >= 1; i--){
			int j = k / fac[i - 1];
			k = k%fac[i - 1];
			result.push_back(c[j]);
			c.erase(c.begin() + j);
		}
		return result;
	}

};

void main(int argc, char* argv[]){
	int n = 3;
	int k = 3;
	Solution s;
	string str = s.getPermutation(n, k);
	cout << "The " << k << "th permutation of ";
	for (int i = 0; i < n; i++) cout << i + 1 << " ";
	cout << "is: " << str << endl;
	system("pause");
}