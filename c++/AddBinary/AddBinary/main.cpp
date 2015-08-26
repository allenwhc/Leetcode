/*
*	Add Binary
*	Last Modified: 6/21/2015
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
	string addBinary(string a, string b){
		string sum;
		if (a == "" && b == "") return sum;
		if (a == "") return b;
		if (b == "") return a;
		int len = max(a.length(), b.length());
		string ar, br;
		ar.resize(len);
		br.resize(len);

		//Fills the smaller number with '0'
		if (a.length() != len){
			for (int i = 0; i < len; i++)
				br[i] = b[i];
			for (int i = 0; i < a.length(); i++)
				ar[i + len - a.length()] = a[i];
			for (int i = 0; i < len - a.length(); i++)
				ar[i] = '0';
		}
		if (b.length() != len){
			for (int i = 0; i < len; i++)
				ar[i] = a[i];
			for (int i = 0; i < b.length(); i++)
				br[i + len - b.length()] = b[i];
			for (int i = 0; i < len - b.length(); i++)
				br[i] = '0';
		}
		if (a.length() == b.length()){
			for (int i = 0; i < len; i++){
				ar[i] = a[i];
				br[i] = b[i];
			}
		}
		vector<int> a1(len), b1(len);
		int sum1 = 0;

		//Converts char to int
		for (int i = 0; i < len; i++){
			a1[i] = ar[i] - 48;
			b1[i] = br[i] - 48;
		}

		//Sums bitwise
		sum.resize(len);
		for (int i = len - 1; i >= 0; i--){
			sum1 = sum1 + a1[i] + b1[i];
			if (sum1 == 0){
				sum[i] = '0';
				sum1 = 0;
			}
			else if (sum1 == 1){
				sum[i] = '1';
				sum1 = 0;
			}
			else if (sum1 == 2){
				sum[i] = '0';
				sum1 = 1;
			}
			else{
				sum[i] = '1';
				sum1 = 1;
			}
		}

		if (sum1 == 0) return sum;
		else{
			string result;
			result.resize(len + 1);
			for (int i = 1; i < result.length(); i++)
				result[i] = sum[i - 1];
			result[0] = '1';
			return result;
		}
	}
};

void main(int argc, char *argv[]){
	string a = "0";
	string b = "0";
	Solution s;
	string sum = s.addBinary(a, b);
	cout << a << " + " << b << " = " << sum << endl;
	system("pause");
}