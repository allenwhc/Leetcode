/*
*	Reverse Binary Bits
*	Last Modified: 5/28/2015
*/
#include <iostream>
#include <vector>
#include <bitset>
#include <stdint.h>
using namespace std;

class Solution{
public:
	uint32_t reverseBits(uint32_t n)
	{
		uint32_t rev;
		bitset<32> temp, reverse;
		temp = bitset<32>(n);
		for (int i = 0; i < 32; i++)
		{
			reverse[i] = temp[31 - i];
		}
		rev = reverse.to_ulong();
		return rev;
	}
};

void main(int argc, char*argv[])
{
	uint32_t n;
	uint32_t rev;
	vector<int> binaryDigit;
	Solution s;
	
	cout << "Input an integer from 0 to 4294967295: ";
	cin >> n; 
	cout << "Input integer in binary is: " << bitset<32>(n) << endl;
	rev = s.reverseBits(n);
	cout << "Integer after reversed bitwise:" << rev << endl;
	cout << "After bit reversed: " << bitset<32>(rev) << endl;
	system("pause");
}