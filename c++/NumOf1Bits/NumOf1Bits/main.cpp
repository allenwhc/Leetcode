/*
*	Hamming Weight
*	Last Modified: 5/28/2015
*/

#include<iostream>
#include<bitset>
#include<stdint.h>
using namespace std;

class Solution{
public:
	int hammingWeight(uint32_t n){
		int weight = 0;
		bitset<32> sampleInteger = bitset<32>(n);
		for (int i = 0; i < 32; i++)
		{
			if (sampleInteger[i] == 1)
			{
				weight++;
			}
		}
		return weight;
	}
};

void main(int argc, char*argv[])
{
	uint32_t n;
	int weight;
	Solution s;

	cout << "Input an 32-bit unsigned integer: ";
	cin >> n;
	cout << "Binary form of the input integer is: " << bitset<32>(n) << endl;
	weight = s.hammingWeight(n);
	cout << "Hamming weight of the given integer is: " << weight << endl;
	system("pause");
}