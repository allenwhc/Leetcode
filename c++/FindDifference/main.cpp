#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char findTheDifference(string s, string t){
	if(s.size() >= t.size()) return '\0';
	vector<int> T(26,0);
	for(char c:s) T[c-'a']++;
	for(char c:t) T[c-'a']--;
	return find(T.begin(), T.end(), -1) - T.begin() + 'a';
}

int main(int argc, char const *argv[])
{
	string s = "abcd";
	string t = "bcaed";
	cout << findTheDifference(s,t) << endl;
	return 0;
}