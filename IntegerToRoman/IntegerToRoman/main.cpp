#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	string inToRoman(int num){
		string symbols[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		int intArray[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string roman = "";
		for (int i = 0; i < 13; i++)
		{
			while (num >= intArray[i])
			{
				roman.append(symbols[i]);
				num -= intArray[i];

			}
		}
		return roman;
	}
};

void main(int argc, char *[]){
	int num;
	Solution s;
	cout << "Input an integer between 1~3999: ";
	cin >> num;
	string roman = s.inToRoman(num);
	cout << num << " in roman numerial is: " << roman << endl;
	system("pause");
}