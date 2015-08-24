/*
*	Merge & Insert Intervals
*	Last Modified: 6/30/2015
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Interval
{
	int start;
	int end;
	Interval() :start(0), end(0){}
	Interval(int s, int e) :start(s), end(e){}
};

class Solution{
public:
	//Merging Intervals
	vector<Interval> merge(vector<Interval>& intervals){
		vector<Interval> res;
		int n = intervals.size();
		if (n <= 1) return intervals;
		sort(intervals.begin(), intervals.end(), compare);
		res.push_back(intervals[0]);
		for (int i = 1; i < n; i++){
			if (intervals[i].start <= res.back().end){
				Interval it;
				it.start = res.back().start;
				it.end = max(res.back().end, intervals[i].end);
				res.pop_back();
				res.push_back(it);
			}
			else res.push_back(intervals[i]);
		}
		return res;
	}

	static bool compare(Interval &i1, Interval& i2){
		return (i1.start < i2.start);
	}

	//Inserting and Merging Intervals
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval){
		int n = intervals.size();
		vector<Interval> res;
		if (n == 0){
			res.push_back(newInterval);
			return res;
		}
		int i = 0;
		while (i < n && intervals[i].end < newInterval.start){
			res.push_back(intervals[i]);
			i++;
		}
		while (i < n && intervals[i].start <= newInterval.end){
			newInterval.start = min(newInterval.start, intervals[i].start);
			newInterval.end = max(newInterval.end, intervals[i].end);
			i++;
		}
		res.push_back(newInterval);
		while (i<n && intervals[i].start > newInterval.end){
			res.push_back(intervals[i]);
			i++;
		}
		return res;
	}
};

void main(int argc, char *argv[]){
	Interval i1, i2, i3, i4, i5;	//Test data for Merge Interval
	//Initializes i
	i1.start = 1;
	i1.end = 4;
	i2.start = 3;
	i2.end = 5;
	i3.start = 6;
	i3.end = 9;
	i4.start = 8;
	i4.end = 11;
	i5.start = 12;
	i5.end = 16;
	vector<Interval> interval1;
	interval1.push_back(i1);
	interval1.push_back(i2);
	interval1.push_back(i3);
	interval1.push_back(i4);
	interval1.push_back(i5);
	Solution s;
	vector<Interval> res = s.merge(interval1);
	cout << "Merging Intervals: " << endl;
	cout << "The collection of intervals is: ";
	for (int i = 0; i < interval1.size(); i++){
		cout << "[";
		cout << interval1[i].start << "," << interval1[i].end;
		cout << "] ";
		if (i != interval1.size() - 1) cout << ",";
	}
	cout << endl;
	cout << "The merging result is: ";
	for (int i = 0; i < res.size(); i++){
		cout << "[";
		cout << res[i].start << "," << res[i].end;
		cout << "]";
		if (i != res.size() - 1) cout << ",";
	}
	cout << endl;

	cout << endl << "Insert and merge Intervals: " << endl;
	Interval l1, l2, l3, l4, l5;	//Test data for insert interval
	//Initializes l
	l1.start = 1;
	l1.end = 2;
	l2.start = 3;
	l2.end = 5;
	l3.start = 6;
	l3.end = 7;
	l4.start = 8;
	l4.end = 10;
	l5.start = 12;
	l5.end = 16;
	vector<Interval> interval2;
	interval2.push_back(l1);
	interval2.push_back(l2);
	interval2.push_back(l3);
	interval2.push_back(l4);
	interval2.push_back(l5);
	Interval newInterval;
	newInterval.start = 4;
	newInterval.end = 9;
	vector<Interval> resInsert = s.insert(interval2, newInterval);
	cout << "A set of non-overlapping intervals is: ";
	for (int i = 0; i < interval2.size(); i++){
		cout << "[";
		cout << interval2[i].start << "," << interval2[i].end;
		cout << "] ";
		if (i != interval2.size() - 1) cout << ",";
	}
	cout << ", and the new inserting interval is: ";
	cout << "[" << newInterval.start << "," << newInterval.end << "]" << endl;
	cout << "The inserting and merging result is: ";
	for (int i = 0; i < resInsert.size(); i++){
		cout << "[";
		cout << resInsert[i].start << "," << resInsert[i].end;
		cout << "]";
		if (i != resInsert.size() - 1) cout << ",";
	}
	cout << endl;

	
	system("pause");
}