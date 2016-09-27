#include <iostream>
#include <string>
using namespace std;

string removeKdigits(string num, int k){
	if(k==num.size()) return "0";
	auto it = num.begin();
	while(k){
		if(it+1 == num.end() || *it > *(it + 1)){
			num.erase(it);
			--it;--k;
		}
		else ++it;
	}
	num.erase(0, min(num.find_first_not_of('0'), num.size()-1));
	return num;
}

int main(int argc, char const *argv[])
{
	string num = "10200";
	int k = 1;
	cout << removeKdigits(num,k) << endl;
	return 0;
}