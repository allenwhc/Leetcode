#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> fizzBuzz(int n){
	vector<string> res(n,"");
	if(n == 0) return res;
	for(int i=1; i<=n; i++){
		if((i%3==0) && (i%5!=0)) res[i-1] = "Fizz";
		else if((i%5==0) && (i%3!=0)) res[i-1] = "Buzz";
		else if((i%5==0) && (i%3==0)) res[i-1] = "FizzBuzz";
		else res[i-1] = to_string(i);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int n = 15;
	for(auto x: fizzBuzz(n))
		cout << x << endl;
	return 0;
}