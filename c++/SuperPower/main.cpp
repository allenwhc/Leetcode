#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define mod 1337

int powerMod(int a, int e){
	a %= mod;
	int res = 1;
	for(int i=0; i<e; ++i){
		res = (res * a) % mod;
	}
	return res;
}

int superPow(int a, vector<int> &b){
	if(!a) return 0;
	if(b.empty() || a==1) return 1;
	int last_digit = b.back();
	b.pop_back();
	return powerMod(superPow(a, b), 10) * powerMod(a, last_digit) % mod;
}

int main(int argc, char const *argv[])
{
	int a = 3;
	vector<int> b = {3,0,6,8,1,5,7};
	cout << superPow(a, b) << endl;
	return 0;
}