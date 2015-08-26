/*
*	Word Search I & II
*	Last Modified: 7/22/2015
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
	//A prefix trie
	struct Trie{
		Trie *children[26];
		bool leaf;
		int index;
		Trie(){
			this->leaf = false;
			this->index = 0;
			fill_n(this->children, 26, nullptr);
		}
	};
public:
	//Word Search I, check if the word exists in the board
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		int n = board[0].size();

		bool res = false;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++)
				if (searchWord(board, word, i, j, 0))
					res = true;
		}
		return res;
	}

	bool searchWord(vector<vector<char>>& board, string& word, int row, int col, int index){
		int m = board.size();
		int n = board[0].size();

		if (row < 0 || col < 0 || row >= m || col >= n) return false;
		
		if (board[row][col] == word[index]){
			char temp = board[row][col];	//Save the character in board
			board[row][col] = '*';	//Mark the current character as '*'
			if (index == word.length() - 1) return true;
			else if (searchWord(board, word, row + 1, col, index + 1) ||
				(searchWord(board, word, row - 1, col, index + 1)) ||
				(searchWord(board, word, row, col + 1, index + 1)) ||
				(searchWord(board, word, row, col - 1, index + 1)))
				return true;
			board[row][col] = temp;
		}
		return false;
	}

	//Word Search II, find all words in the board
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> res;
		int m = board.size();
		if (m == 0) return res;
		int n = board[0].size();
		if (n == 0) return res;
		int len = words.size();
		if (len == 0) return res;

		Trie *root = buildTrie(words);
		for (int i = 0; i < m; i++)
			for (int j = 0; j<n && len>res.size(); j++)
				checkWords(board, i, j, m, n, root, words, res);
		return res;
	}

	void insertWords(Trie* root, vector<string>& words, int index){
		int pos = 0, len = words[index].length();
		while (pos < len){
			if (nullptr == root->children[words[index][pos] - 'a'])
				root->children[words[index][pos] - 'a'] = new Trie();
			root = root->children[words[index][pos++] - 'a'];
 		}
		root->leaf = true;
		root->index = index;
	}

	Trie* buildTrie(vector<string>& words){
		Trie *root = new Trie();
		int i = 0;
		for (int i = 0; i < words.size(); i++)
			insertWords(root, words, i);
		return root;
	}

	void checkWords(vector<vector<char>>& board, int i, int j, int row, int col, Trie* root, vector<string>& words, vector<string>& res){
		char temp;
		if (board[i][j] == 'X') return;	//visited before
		if (nullptr == root->children[board[i][j] - 'a']) return;	//No such prefix in the trie
		else{
			temp = board[i][j];
			//If reaches leaf 
			if (root->children[temp - 'a']->leaf){
				res.push_back(words[root->children[temp - 'a']->index]);
				root->children[temp - 'a']->leaf = false;
			}
			board[i][j] = 'X';	//Mark the current position as visited
			//Check all neighbors
			if (i>0) checkWords(board, i - 1, j, row, col, root->children[temp - 'a'], words, res);
			if (i<row - 1) checkWords(board, i + 1, j, row, col, root->children[temp - 'a'], words, res);
			if (j>0) checkWords(board, i, j - 1, row, col, root->children[temp - 'a'], words, res);
			if (j<col - 1) checkWords(board, i, j + 1, row, col, root->children[temp - 'a'], words, res);
			board[i][j] = temp;
		}
	}
};

void main(int argc, char *argv[]){
	string word = "ABCCED";
	vector<vector<char>> board = { { 'A', 'B', 'C', 'E' }, { 'S', 'F', 'C', 'S' }, { 'A', 'D', 'E', 'E' } };
	Solution s;
	bool isExist = s.exist(board, word);
	if (isExist) cout << "'" << word << "' exists in the board." << endl;
	else cout << "'" << word << "' dose not exist in the board." << endl;

	vector<vector<char>> board1 = {
		{ 'o', 'a', 'a', 'n' },
		{ 'e', 't', 'a', 'e' },
		{ 'i', 'h', 'k', 'r' },
		{ 'i', 'f', 'l', 'v' } };
	vector<string> words = { "oath", "pea", "eat", "rain" };
	vector<string> res = s.findWords(board1, words);
	cout << "The found words in the board are: ";
	for (string s : res)
		cout << "'" << s << "', ";
	cout << endl;
	system("pause");
}