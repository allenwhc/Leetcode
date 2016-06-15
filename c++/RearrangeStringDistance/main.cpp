#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Compare
{
	bool operator()(pair<char,int> &p1, pair<char, int> &p2){return p1.second == p2.second ? p1.first - 'a' > p2.first - 'a': p1.second < p2.second;}
};

class Solution{
public:
	string rearrangeString(string str, int k){
	    if (k == 0) return str;
		unordered_map<char, int> mp;
		priority_queue<pair<char, int>, vector<pair<char,int>>, Compare> heap;
		string res;
		int n = str.length();

		for (auto &s: str) mp[s]++;
		for (auto it = mp.begin(); it != mp.end(); it++)
			heap.push(make_pair(it->first, it->second));
		
		while (!heap.empty()){
			vector<pair<char,int>> temp;
			int size = min(k, n);
			for (int i=0; i<size; i++){
				if (heap.empty()) return "";
				auto letter = heap.top();
				heap.pop();
				res.push_back(letter.first);
				if (--letter.second > 0) temp.push_back(letter);
				n--;
			}
			for (auto &t:temp) heap.push(t);
		}
		return res;
	}
};


int main(int argc, char const *argv[])
{
	string str = "aaabbbbccccc";
	int k = 3;
	Solution s;
	cout << str << " --- rearranged by " << k << " --- " << s.rearrangeString(str, k) << endl;
	return 0;
}
