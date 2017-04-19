#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Interval
{
	int start;
	int end;
	Interval():start(0),end(0){}
	Interval(int s, int e):start(s),end(e){}	
};

vector<int> findRightInterval(vector<Interval>& intervals){
	vector<int> res;
	map<int,int> dict;
	for(int i=0; i<intervals.size(); i++) dict[intervals[i].start] = i;
	for(auto inter: intervals){
		auto it = dict.lower_bound(inter.end);
		if(it == dict.end()) res.push_back(-1);
		else res.push_back(it->second);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	vector<Interval> intervals = {Interval(3,4),Interval(2,3),Interval(1,2)};
	for(auto &v: findRightInterval(intervals))
		cout << v << endl;
	return 0;
}