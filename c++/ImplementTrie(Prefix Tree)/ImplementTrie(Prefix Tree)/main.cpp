/*
*	Implement Trie (Prefix Tree)
*	Last Modified: 7/9/2015
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class TrieNode{
public:
	TrieNode(){
		value = 0;
		for (int i = 0; i < 26; i++)
			children[i] = NULL;
	}
	int value;
	TrieNode *children[26];
};

class Trie{
public:
	Trie(){
		root = new TrieNode();
		count = 0;
	}

	//Inserts a word into the trie
	void insert(string word){
		TrieNode *p = root;
		int len = word.length();
		for (int i = 0; i < len; i++){
			int val = word[i] - 'a';
			if (p->children[val] == NULL) p->children[val] = new TrieNode();
			p = p->children[val];
		}
		count++;
		p->value = count;
	}

	//Return if the word is in the trie
	bool search(string word){
		TrieNode *p = root;
		int len = word.length();
		for (int i = 0; i < len; i++){
			int val = word[i] - 'a';
			if (p->children[val]) p = p->children[val];
			else return false;
		}
		if (p->value != 0) return true;
		else return false;
	}

	//Return if there is any word in the trie
	//that starts with the given prefix
	bool startsWith(string prefix){
		TrieNode *p = root;
		int len = prefix.length();
		for (int i = 0; i < len; i++){
			int val = prefix[i] - 'a';
			if (p->children[val]) p = p->children[val];
			else return false;
		}
		return true;
	}

private:
	TrieNode *root;
	int count;
};

void main(int argc, char *argv[]){
	Trie pTree;
	vector<string>  insertWord = {"stony", "brook", "university", "eletrical", "and", "computer", "engineering", "department"};
	string searchWord = "univ";
	string searchPrefix = "ele";
	for (int i = 0; i < insertWord.size(); i++)
		pTree.insert(insertWord[i]);
	cout << searchWord;
	if (pTree.search(searchWord)) cout << " is a word in ";
	else cout << " is not a word in ";
	for (int i = 0; i < insertWord.size(); i++){
		cout << insertWord[i];
		if (i != insertWord.size() - 1) cout << ",";
	}
	cout << endl;
	cout << searchPrefix;
	if (pTree.startsWith(searchPrefix)) cout << " is a prefix in ";
	else cout << " is not a prefix in ";
	for (int i = 0; i < insertWord.size(); i++){
		cout << insertWord[i];
		if (i != insertWord.size() - 1) cout << ",";
	}
	cout << endl;
	system("pause");
}