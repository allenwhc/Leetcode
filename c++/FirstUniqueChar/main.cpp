#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s){
	unordered_map<char, int> mp;
	for(int i=0; i<s.size(); i++) mp[s[i]]=i;
	for(int i=0; i<s.size(); i++){
		if(s.find_first_of(s[i]) == mp[s[i]]) return mp[s[i]];
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	string s = "loveleetcode";
	cout << firstUniqChar(s) << endl;
	return 0;
}