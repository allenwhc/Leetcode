/*
*	Fraction to Recurring Decimal
*	Last Modified: 7/3/2015
*	Hint: Takes 5/7 as an example,
			Numerator	Denominator		Quotient	Remainder
				5			7				0			5
				50			7				7			1
				10			7				1			3
				30			7				4			2
				20			7				2			6
				60			7				8			4
				40			7				5			5 (repeat)
		vector<int> quos=	7	1	4	2	8	5
					index=	0	1	2	3	4	5
		map<int,int> myMap=	5	1	3	2	6	4	5(stop)
							0	1	2	3	4	5	6
*/		

#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution{
public:
	string fractionToDecimal(int numerator, int denominator){
		if (numerator == 0) return "0";
		if (denominator == 0) return "";
		string result = "";
		long long num = numerator, den = denominator;
		if (den < 0){
			num = -num;
			den = -den;
		}
		if (num < 0){
			num = -num;
			result += "-";
		}
		long long quotient = num / den;
		result += to_string(quotient);	//Saves the integer part
		long long remainder = num%den;
		if (remainder == 0) return result;	//If remainder=0, meaning aliquot
		//Deal with the decimal parts
		vector<int> quos;	//Saves the quotients
		unordered_map<int, int> myMap;
		result += ".";	//Adds decimal point
		for (int i = 0; remainder&& myMap.find(remainder) == myMap.end(); i++){
			myMap[remainder] = i;	//Saves index of the current remainder
			remainder *= 10;
			quos.push_back(remainder / den);
			remainder %= den;
		}

		if (remainder){
			for (int i = 0; i < myMap[remainder]; i++)
				result += to_string(quos[i]);
			result += "(";
			for (int i = myMap[remainder]; i < quos.size(); i++)
				result += to_string(quos[i]);
			result += ")";
		}
		else{	//No repeat digits
			for (int i = 0; i < quos.size(); i++)
				result += to_string(quos[i]);
		}
		return result;
	}
};

void main(int argc, char*argv[]){
	vector<int> numerators = { -1, 2, 3, 5 };
	vector<int> denominators = { 15, 3, 8, 7 };
	vector<string> result(numerators.size(),"");
	Solution s;
	for (int i = 0; i < numerators.size(); i++)
		result[i] = s.fractionToDecimal(numerators[i], denominators[i]);
	for (int i = 0; i < numerators.size(); i++){
		cout << "The recurring decimal result of " << numerators[i] << "/" << denominators[i] << " is: " << result[i] << endl;
	}
	system("pause");
}