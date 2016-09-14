#include <vector>
#include <iostream>
using namespace std;

bool validUtf8(vector<int>& data){
	int m = data.size();
	if(m==0) return false;
	int r=0;
	while(r<m){
		int expectedLength = 0;
		if((data[r] & 0b10000000) == 0b00000000) expectedLength = 1;
		else if((data[r] & 0b11100000) == 0b11000000) expectedLength = 2;
		else if((data[r] & 0b11110000) == 0b11100000) expectedLength = 3;
		else if((data[r] & 0b11111000) == 0b11110000) expectedLength = 4;
		else return false;
		if(expectedLength > m - r) return false;
		for(int i=r+1; i<r+expectedLength && i<m; i++){
			if((data[i] & 0b11000000) != 0b10000000) return false;
		}
		r += expectedLength;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	vector<int> data = {197,130,1};
	cout << validUtf8(data) << endl;
	return 0;
}