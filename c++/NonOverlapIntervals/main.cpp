#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Interval
{
	int start;
	int end;
	Interval():start(0),end(0){}
	Interval(int s, int e):start(s),end(e){}
};

int eraseOverlapIntervals(vector<Interval>& intervals){
	if(!intervals.size()) return 0;
	auto Compare = [](Interval i1, Interval i2){
		if(i1.end != i2.end) return i1.end < i2.end;
		else return i1.start > i2.start;
  	};
  	int res = 0;
  	sort(intervals.begin(), intervals.end(), Compare);
  	Interval prev = intervals[0];
  	//for(auto i: intervals) cout <<i.start<<','<<i.end<<endl;
  	for(int i=1; i<intervals.size(); ++i){
  		if(intervals[i].start < prev.end){	//Overlap
  			res++;
  		}
  		else{
  			prev = intervals[i];
  		}
  	}
  	return res;
}

int main(int argc, char const *argv[])
{
	vector<Interval> intervals = {Interval(1,2),Interval(2,3)};
	cout << eraseOverlapIntervals(intervals) << endl;
	return 0;
}