#include <iostream>
using namespace std;

int countReplacement(long n){
	//cout << n << endl;
	if(n<=3) return n-1;
	if(!(n%2)) return countReplacement(n/2) + 1;
	else return (((n-1)/2)%2==0?countReplacement(n-1):countReplacement(n+1)) + 1;
}

int integerReplacement(int n){
	return countReplacement((long)n);
}

int main(int argc, char const *argv[])
{
	/* code */
	int n = INT_MAX;
	cout << integerReplacement(n) << endl;
	return 0;
}