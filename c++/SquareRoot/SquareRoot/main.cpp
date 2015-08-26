/*
*	Square Root
*	Last Modified: 6/2/2015
*/

#include <iostream>
#include <math.h>
using namespace std;

class Solution{
public:
	int mySqrt(int x){
		double diff = 0.000001;
		double accurateSqrt = sqrt(x);
		if (x <= 0)
			return 0;
		else{
			double guess = 1;
			double quotient = x / guess;
			double average = (guess + quotient) / 2;
			do
			{
				guess = average;
				quotient = x / guess;
				average = (guess + quotient) / 2;
			} while (abs((guess + quotient) / 2 - accurateSqrt) > diff);
			return (guess + quotient) / 2;
		}
	}
};

void main(int argc, char* argv[]){
	int squareRoot;
	int x;
	cout << "Input a number: ";
	cin >> x;
	Solution s;
	squareRoot = s.mySqrt(x);
	cout << "The closest integer to the square root of " << x << " is " << squareRoot << endl;
	system("pause");
}

