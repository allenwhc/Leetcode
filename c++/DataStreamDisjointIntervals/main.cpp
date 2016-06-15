#include <iostream>
#include <vector>
using namespace std;

struct Interval{
	int start,end;
	Interval():start(0),end(0){}
	Interval(int s, int e):start(s), end(e){}
};

class SummaryRanges {
	vector<Interval> intervals;
	int binarySearch(vector<Interval> &intervals, int target, int s, int e){
		if (s >= e) return -1;
		if (e - s == 1 && intervals[s].start < target) return s;  
		int mid = (s + e) / 2;
		if (intervals[mid].start == target) return mid;
		else if (intervals[mid].start < target) 
			return binarySearch(intervals, target, mid, e);
		else 
			return binarySearch(intervals, target, s, mid);
	}
public:
	/** Initialize your data structure here. */
	SummaryRanges() {
		
	}
	
	void addNum(int val) {
		int index = binarySearch(intervals, val, 0, intervals.size());
		//cout << index << endl;
		//value contained in [start, end]
		if (index != -1 && intervals[index].end >= val) return;

		if (index != intervals.size() - 1 && val == intervals[index + 1].start - 1) 
			intervals[index + 1].start = val;		// If val = intervals[next interval].start - 1, substitute start of next interval by val
		else if (index != -1 && val == intervals[index].end + 1)
			intervals[index].end = val;		//If val = intervals[curr interval].end + 1, substitute end of current interval by val
		else
			intervals.insert(intervals.begin() + index + 1, Interval(val, val));	//Otherwise, insert a new interval

		//Merge overlapped intervals
		if (index != -1 && intervals[index].end == intervals[index + 1].start - 1){
			intervals[index].end = intervals[index + 1].end;
			intervals.erase(intervals.begin() + index + 1);
		}
		return;
	}
	
	vector<Interval> getIntervals() {
		return intervals;
	}
};

void printRange(vector<Interval> intervals){
	for (auto it = intervals.begin(); it != intervals.end(); it++)
		cout << "[" << it->start << ", " << it->end << "], ";
	cout << endl;
}

int main(int argc, char const *argv[])
{
	SummaryRanges sr;
	sr.addNum(1);
	printRange(sr.getIntervals());
	sr.addNum(3);
	printRange(sr.getIntervals());
	sr.addNum(7);
	printRange(sr.getIntervals());
	sr.addNum(2);
	printRange(sr.getIntervals());
	sr.addNum(6);
	printRange(sr.getIntervals());
	return 0;
}