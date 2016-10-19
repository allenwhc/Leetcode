#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

/*
*	DFS + backtracking solution
*	Time complexity: O(mn^2)
*	Extra space: O(n)
*/
class Solution
{
	string ans = "";
	int min_len = INT_MAX;
	//Check if abbr is a valid abbreviation of target word
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

	void dfs(vector<string>& dict, string curr, string target, int curr_len, int pos){
		if(curr_len>=min_len) return;

		//When got a temporary result
		if(pos == target.size()){
			//Check if curr is a valid abbr of any words in dict
			for(string s: dict)
				if(validWordAbbreviation(s,curr)) return;	//If not valid, return
			//If curr is valid, then update answer and min_len
			min_len = curr_len;
			ans = curr;
			return;
		}
		dfs(dict, curr+target[pos], target, curr_len+1, pos+1);	//add char at pos in target into curr
		//Try replace with numbers/length
		if(curr.empty() || !isdigit(curr.back())){
			for(int len=2; len<=target.size()-pos; len++)
				dfs(dict, curr+to_string(len), target, curr_len+1, pos+len);
		}
	}
public:
	string minAbbreviation(string target, vector<string>& dictionary){
		if(target.empty() || find(dictionary.begin(), dictionary.end(), target) != dictionary.end()) return "";
		vector<string> dict;
		for(auto s:dictionary)
			if(s.size()==target.size()) dict.push_back(s);	//Delete all words in dictionary that have different length with target
		if(dict.empty()) return to_string(target.size());	//No word has same length as target, return its length which is the minimum abbr
		dfs(dict,"",target,0,0);
		return ans;
	}
};


int main(int argc, char const *argv[])
{
	string target = "apple";
	vector<string> dictionary = {"cat","life","blade"};
	Solution sol;
	cout << "Min abbr: " << sol.minAbbreviation(target, dictionary) << endl;
	return 0;
}