#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> reconstructQueue(vector<pair<int,int>>& people){
	auto compare = [](pair<int,int>& p1, pair<int,int>& p2){
		if(p1.first != p2.first) return p1.first > p2.first;
		else return p1.second < p2.second;
	};
	vector<pair<int,int>> res;
	sort(people.begin(),people.end(),compare);
	for(auto &p:people) res.insert(res.begin()+p.second,p);
	return res;
}

int main(int argc, char const *argv[])
{
	vector<pair<int,int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
	for(auto& v:reconstructQueue(people)){
		cout << '[' << v.first << "," << v.second << ']' << endl;
	}
	return 0;
}