#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
class Solution{
	vector<string> digits = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	priority_queue<string, vector<string>, greater<string>> temp;
	string res;
	map<char,int> dict;
	void deleteItem(int index, char c, int count){
		// cout << index << "," << c << endl;
		// for(auto it = dict.begin(); it!=dict.end(); ++it)
		// 	cout << it->first <<"," <<it->second << " ";
		// cout << endl;
		for(int i=0; i<digits[index].size(); ++i){
			dict[digits[index][i]] -= count;
			if(dict[digits[index][i]] == 0) dict.erase(dict.find(digits[index][i]));
		}
		for(int i=0; i<count; i++)
			temp.push(to_string(index));
	}
public:
	string originalDigits(string s){
		if(s.empty()) return res;
		for(char c: s) dict[c]++;
		
		//Check if s contains 'z' -> zero
		if(dict.find('z')!=dict.end())
			deleteItem(0, 'z', dict['z']);

		//Check if s contains 'w' -> two
		if(dict.find('w') != dict.end())
			deleteItem(2, 'w', dict['w']);

		//Check if s contains 'u' -> four
		if(dict.find('u') != dict.end())
			deleteItem(4, 'u', dict['u']);

		//Check if s contains 'x' -> six
		if(dict.find('x') != dict.end())
			deleteItem(6, 'x', dict['x']);

		//Check if s contains 'g' -> eight
		if(dict.find('g') != dict.end())
			deleteItem(8, 'g', dict['g']);

		//Check if s contains 'o' -> one (zero and two already excluded)
		if(dict.find('o') != dict.end())
			deleteItem(1, 'o', dict['o']);

		//Check if s contains 'r' -> three (zero and four already excluded)
		if(dict.find('r') != dict.end())
			deleteItem(3, 'r', dict['r']);

		//Check if s contains 'f' ->five (four already excluded)
		if(dict.find('f') != dict.end())
			deleteItem(5, 'f', dict['f']);

		//Check if s contains 'v' -> seven (five already excluded)
		if(dict.find('v') != dict.end())
			deleteItem(7, 'v', dict['v']);

		if(dict.find('i') != dict.end())
			deleteItem(9, 'i', dict['i']);
		
		while(!temp.empty()){
			res += temp.top();
			temp.pop();
		}
		return res;
	}
};



int main(int argc, char const *argv[])
{
	string s = "fviefuro";
	Solution sol;
	cout << sol.originalDigits(s) << endl;
	return 0;
}