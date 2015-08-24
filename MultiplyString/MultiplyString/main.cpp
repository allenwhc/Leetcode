/*
*	Multiply Strings
*	Last Modified: 7/21/2015
*	Hint:
		1. Reverse two given strings
		2. Create a integer array arr[] 
			for i: 0--num1.len
				char a=num1[i]-'0'
				for j:0--num2.len
					char b=num2[j]-'0'
					arr[i+j]=a*b
		3. For i:0--len1+len2
			res.append(arr[i]%10)  ->digit
			arr[i+1]+=arr[i]/10  ->carry
		4. Reverse res, trim leading '0's
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		int len1 = num1.length();
		int len2 = num2.length();
		string res;
		if (len1 == 0 || len2 == 0) return res;

		//First, reverse string by digit
		reverseNumber(num1, 0, len1 - 1);
		reverseNumber(num2, 0, len2 - 1);

		int len = len1 + len2;
		vector<int> multiplication(len);
		for (int i = 0; i < len1; i++){
			int a = num1[i] - '0';	//Convert char to int
			for (int j = 0; j < len2; j++){
				int b = num2[j] - '0';
				multiplication[i + j] += a*b;
			}
		}

		for (int i = 0; i < len; i++){
			int digit = multiplication[i] % 10;
			int carry = multiplication[i] / 10;
			res.append(to_string(digit));
			if (i < len - 1) multiplication[i + 1] += carry;
		}
		reverseNumber(res, 0, res.length() - 1);
		while (res.length() > 0 && res[0] == '0') res.erase(res.begin());
		return (res.length() == 0) ? "0" : res;
	}

	void reverseNumber(string& s, int start, int end){
		if (start > end) return;
		while (start < end){
			char temp = s[start];
			s[start] = s[end];
			s[end] = temp;
			start++;
			end--;
		}
	}
};

void main(int argc, char* argv[]){
	string num1 = "139";
	string num2 = "241";
	Solution s;
	cout << num1 << " * " << num2 << " = " << s.multiply(num1, num2) << endl;
	system("pause");
}