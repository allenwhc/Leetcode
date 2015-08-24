/*
*	Plus One
*	Last Modified: 6/18/2015
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	vector<int> plusOne(vector<int>& digits){
		int n = digits.size();
		int countDigits = n;
		digits[n - 1] = digits[n - 1] + 1;
		vector<int> plus;
		for (int i = n - 1; i >= 1; i--){
			if (digits[i] == 10){
				plus.push_back(0);
				digits[i - 1] = digits[i - 1] + 1;
			}
			else{
				plus.push_back(digits[i]);
			}
		}/*
		for (int i = 0; i < n; i++)
			cout << digits[i] << " ";*/
		if (digits[0] == 10){
			digits[0] = 0;
			plus.push_back(digits[0]);
			plus.push_back(1);
			countDigits = countDigits + 1;
		}
		else plus.push_back(digits[0]);
		vector<int> results(countDigits);
		for (int i = 0; i < countDigits; i++){
			results[i] = plus.back();
			plus.pop_back();
		}
		return results;
	}
};

void main(int argc, char *argv[]){
	vector<int> digits = { 9, 9, 9 };
	Solution s;
	for (int i = 0; i < digits.size(); i++)
		cout << digits[i];
	vector<int> result = s.plusOne(digits);
	cout << " + 1 = ";
	for (int i = 0; i < result.size(); i++)
		cout << result[i];
	cout << endl;
	system("pause");
}