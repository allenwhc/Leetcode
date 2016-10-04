#include <iostream>
#include <string>
using namespace std;

/*
*	Greedy solution
*	Time complexity: O(n)
*	Extra space: O(1)
*/
bool validWordAbbreviation(string word, string abbr){
	if(!word.size()) return abbr.size()==0;
	int i = 0, j = 0;
	while(i<word.size() && j<abbr.size()){
		if(!isdigit(abbr[j]) || abbr[j] == '0'){
			if(word[i] == abbr[j]){i++;j++;}
			else return false;
		}else{
			int len = 0;
			while(j<abbr.size() && isdigit(abbr[j]))
				len = len*10 + (abbr[j++] - '0');
			if(i+len > word.size()) return false;
			i += len;
		}
	}
	return i==word.size() && j==abbr.size();
}

int main(int argc, char const *argv[])
{
	string word = "a";
	string abbr = "01";
	cout << validWordAbbreviation(word,abbr) << endl;
	return 0;
}