#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t){
	int m=s.size(), n=t.size();
	if(n==0) return m==0;
	
}

int main(int argc, char const *argv[])
{
	/* code */
	string s = "abc", t = "ahbgdc";
	cout << isSubsequence(s,t) << endl;
	return 0;
}