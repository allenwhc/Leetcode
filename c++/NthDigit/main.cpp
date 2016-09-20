#include <iostream>
#include <math.h>
using namespace std;

int findNthDigit(int n){
	if(n<=9) return n;
	long base = 9, bound = 9;
	int lower = 0, prev_base = 9;
	int i = 2;
	while(true){
		long temp = base;
		base = base*10+9;
		cout << temp << "," << bound << "," << base << endl;
		if(bound + i*(base - temp) < n){
			bound += i*(base - temp);
			i++;
		}
		else{
			lower = bound;
			prev_base = temp;
			break; 
		}
	}
	double x = (n - lower)*1.0 / i + prev_base;
	int num = ceil(x), prev_num = floor(x);
	int ith = (n - lower - (prev_num - prev_base) * i == 0)?i:n - lower - (prev_num - prev_base) * i;
	int res = 0;
	for(int j=0; j<=i-ith; j++){
		res = num%10;
		num /=10;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int n = 1000000000;
	cout << findNthDigit(n) << endl;
	return 0;
}