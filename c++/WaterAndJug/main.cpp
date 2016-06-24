#include <iostream>
using namespace std;

int gcd(int a, int b){
	int x;
	while(b){
		x = a%b;
		a = b;
		b = x;
	}
	return a;
}

bool canMeasureWater(int x, int y, int z){
	if(z>x && z>y) return false;
	return z % gcd(x,y) == 0;
}

int main(int argc, char const *argv[])
{
	int x=8,y=5,z=1;
	cout<<canMeasureWater(x,y,z)<<endl;
	return 0;
}