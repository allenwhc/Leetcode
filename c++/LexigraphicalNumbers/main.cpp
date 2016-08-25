#include <iostream>
#include <vector>
using namespace std;

vector<int> lexicalOrder(int n){
	vector<int> res;
	if(n<1) return res;
	int num = 1;
	for(int i=1; i<=n; i++){
		res.push_back(num);
		if(num*10<=n) num *= 10;
		else if(num%10!=9 && num+1<=n) num += 1;
		else{
			while((num/10)%10==9) num /=10;
			num = num/10 + 1;
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int n = 100;
	for(auto &v: lexicalOrder(n)) cout << v << " ";
	return 0;
}