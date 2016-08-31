#include <iostream>
#include <vector>
#include <limits.h>
#include <string>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth){
	int n = words.size();
	vector<string> res;
	if(!words.size()) return {};
	int i = 0, end = -1, len = 0;
	while(i<n){
		while(i<n && len + words[i].size() <= maxWidth){
			len += words[i++].size() + 1;
		}
		i--;len--;

		int avg_space = 0, tail_space = 0;
		if(i != end + 1 && i != n - 1){
			avg_space = (maxWidth - len) / (i - end - 1);
			tail_space = (maxWidth - len) % (i - end - 1);
		}
		string str = "";
		for(int j=end+1; j<i; j++){
			str.append(words[j]);
			for(int k=0; k<=avg_space; k++) str.append(" ");
			if(tail_space--) {str.append(" ");}
		}
		str.append(words[i]);
		int padLength = maxWidth - str.size();
		for(int k=0; k<padLength; k++) str.append(" ");
		res.push_back(str);
		end = i++;
		len = 0;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	vector<string> words ={""};
	//vector<string> words = {"Tushar","Roy","likes","to","code"};
	int maxWidth = 2;
	for(auto &s: fullJustify(words, maxWidth)) 
		cout << s << endl;
	return 0;
}