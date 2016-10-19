#include <iostream>
#include <string>
#include <vector>
using namespace std;

int characterReplacement(string s, int k){
	if(!k) return 0;
	int n = s.size();
	vector<int> count(26, 0);
	int maxCount = 0;
	int res = 0;
	int l = 0;
	for(int r=0; r<n; ++r){
		maxCount = max(maxCount, ++count[s[r]-'A']);
		if(r-l-maxCount>=k){
			count[s[l++]-'A']--;
		}
	}
	return n - l;
}

int main(int argc, char const *argv[])
{
	string s = "AABABBA";
	int k = 1;
	cout << characterReplacement(s, k) << endl;
	return 0;
}