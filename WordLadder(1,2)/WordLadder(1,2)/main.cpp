/*
*	Word Ladder I & II
*	Last Modified: 7/27/2015
*	Hint:
	Create a wordNode structure(word, noSteps)
	Word Ladder I:
		Create a queue<WordNode> q
		q.push(beginWord,1)
		Add endWord to wordDict
		while q is not empty
			1. Get the front of the queue: topNode=q.front()
			2. Get the word in topNode, str
			3. if(str==endWord), return topNode.noSteps
			4. for each character in str
					for c from 'a' to 'z'
						save str[i]
						change str[i] to c
						create a new word: newWord
						if find newWord in wordDict
							add (newWord, noSteps+1) to queue
							delete newWord from wordDict
						change str[i] back to its original character
			5. Return 0 (no proper transformation path found)

	Word Ladder II:
		
*/

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
private:
	//Create a node class
	struct WordNode{
		string word;
		int noSteps;
		WordNode(string s, int x) :word(s), noSteps(x){}
	};
	
	unordered_map<string, vector<string>> hmap;
	vector<vector<string>> res;
	vector<string> path;
public:
	
	//Word Ladder I, find the length of shortest transformation sequence from beginWord to endWord
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
		queue<WordNode> q;
		WordNode w(beginWord, 1);
		q.push(w);
		wordDict.insert(wordDict.end(), endWord);
		while (!q.empty()){
			//Get the head of the queue
			WordNode topNode = q.front();
			q.pop();
			string str = topNode.word;

			//cout << str << endl;
			//If already find the target word return the number of steps
			if (str==endWord)
				return topNode.noSteps;

			for (int i = 0; i < str.length(); i++){
				for (char c = 'a'; c <= 'z'; c++){
					char tempC = str[i];
					//Change the ith character from 'a' to 'z', excluding itself
					if (str[i] != c)
						str[i] = c;

					string newWord = str;	//Create a new word
					//If the new word is already in the dictionay
					//Increment the step, and delete the word from the dictionary
					if (wordDict.find(newWord) != wordDict.end()){
						q.push(WordNode(newWord, topNode.noSteps + 1));
						wordDict.erase(newWord);
					}
					//Change the character back
					str[i] = tempC;
				}
			}

		}
		return 0;
	}

	//Word Ladder II, find all shortest transformation sequence(s) from start to end
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		res.clear();
		path.clear();
		hmap.clear();

		dict.insert(start);
		dict.insert(end);

		unordered_set<string> curr;
		curr.insert(start);
		unordered_set<string> next;
		path.push_back(end);

		while (true){
			//Delete the previous word in dictionary
			for (auto it = curr.begin(); it != curr.end(); it++)
				dict.erase(*it);

			//Find current level word
			for (auto it = curr.begin(); it != curr.end(); it++){
				int n = it->length();	//Length of current word
				string str = *it;
				for (int i = 0; i < n; i++){
					str = *it;
					for (char c = 'a'; c <= 'z'; c++){
						str[i] = c;
						if (dict.find(str) != dict.end()){
							next.insert(str);
							hmap[str].push_back(*it);
						}
					}
				}
			}
			if (next.empty()) return res;

			if (next.find(end) != next.end()){
				output(start, end);
				return res;
			}
			
			curr.clear();
			curr = next;
			next.clear();
		}
		return res;
	}

	void output(string &start, string end){
		if (end == start){
			reverse(path.begin(), path.end());
			res.push_back(path);
			reverse(path.begin(), path.end());
		}
		else{
			for (int i = 0; i < hmap[end].size(); i++){
				path.push_back(hmap[end][i]);
				output(start, hmap[end][i]);
				path.pop_back();
			}
		}
	}
};

void main(int argc, char *argv[]){
	string beginWord = "hit";
	string endWord = "cog";
	unordered_set<string> wordDict = { "hot", "dot", "dog", "lot", "log" };
	cout << "Begin Word= '" << beginWord << "', End Word= '" << endWord << "'" << endl;
	cout << "The word dictionary is: ";
	for (string ss : wordDict)
		cout << "'" << ss << "', ";
	Solution sol;
	cout << endl << "The minimum steps converting '" << beginWord << "' to '" << endWord << "' is: " << sol.ladderLength(beginWord, endWord, wordDict) << endl;
	unordered_set<string> wordDict1 = { "hot", "dot", "dog", "lot", "log" };
	vector<vector<string>> ladder = sol.findLadders(beginWord, endWord, wordDict1);
	cout << "The transformation paths could be: " << endl;
	for (vector<string> ss : ladder)
	{
		for (string s : ss)
			cout << "'" << s << "' ";
		cout << endl;
	}
	system("pause");
}