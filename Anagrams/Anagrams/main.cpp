/*
*	Anagrams
*	Last Modified: 7/21/2015
*/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> anagrams(vector<string>& strs) {
		vector<string> res;
		int n = strs.size();
		if (n <= 1) return res;
		
		unordered_map<string, int> hmap;	//Create a empty hash map

		//Sort every word, store the value of every character into an array
		//The array will be the key to identify the composition of every word
		//in the dictionary
		for (int i = 0; i < n; i++){
			string word = strs[i];
			sort(word.begin(), word.end());		//Sort every word in the word array
			if (hmap.find(word) == hmap.end()) {
				//If the word is not found in the map, add the index into the map
				hmap[word] = i;
			}
			//If the word already exists in the map, add the word to result according to
			//the key in map. Revise the key to -1 to avoid duplicate 
			else{
				if (hmap[word] >= 0){
					res.push_back(strs[hmap[word]]);
					hmap[word] = -1;
				}
				res.push_back(strs[i]);
			}
		}
		return res;
	}
};

void main(int argc, char *argv[]){
	vector<string> strs = { "last", "salt", "diary", "reap", "cook", "dairy", "apple", "pear", "stal", "pea", "ape", "meat" };
	cout << "The original words are: ";
	for (string ss : strs)
		cout << "'" << ss << "' ";
	cout << endl;
	Solution s;
	vector<string> anagramWords = s.anagrams(strs);
	cout << "The anagrams words are: ";
	for (string ss : anagramWords)
		cout << "'" << ss << "' ";
	cout << endl;
	system("pause");
}