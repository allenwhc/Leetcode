#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <limits.h>
using namespace std;

/*
*	Sweep line solution
*	Time complexity: O(nlogn)
*	Extra space: O(n)
*/
class Solution{
	struct Event
	{
		int time;
		vector<int> rect;
		Event(int t, vector<int>& r):time(t), rect(r){}
	};

	struct Compare
	{
		bool operator()(Event& e1, Event& e2){
			if(e1.time != e2.time) return e1.time > e2.time;
			else return e1.rect[0] > e2.rect[0];
		}
	};

	struct SetCompare
	{
		bool operator()(vector<int> rect1, vector<int> rect2){
			return rect1[1] >= rect2[3] || rect1[3] <= rect2[1];
		}
	};
public:
	bool isRectangleCover(vector<vector<int>>& rectangles){
		priority_queue<Event, vector<Event>, Compare> pq;
		vector<int> line = {INT_MAX, INT_MIN};
		for(vector<int> &rect: rectangles){
			Event e1(rect[0], rect), e2(rect[2], rect);
			pq.push(e1);
			pq.push(e2);
			//Find boundary of vertical lines
			line[0] = min(line[0], rect[1]);
			line[1] = max(line[1], rect[3]);
		}
		set<vector<int>, SetCompare> bst;
		int y = 0;
		while(!pq.empty()){
			int time = pq.top().time;
			while(!pq.empty() && time == pq.top().time){
				Event e = pq.top();
				pq.pop();
				vector<int> rect = e.rect;
				if(time == rect[2]){
					bst.erase(rect);
					y -= rect[3]-rect[1];
				}else{
					if(bst.find(rect) != bst.end()) return false;
					bst.insert(rect);
					y += rect[3]-rect[1];
				}
			}
			if(!pq.empty() && y != line[1] - line[0]) return false;
		}
		return true;
	}
};

int main(int argc, char const *argv[])
{
	vector<vector<int>> rectangles = {{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}};
	Solution sol;
	cout << sol.isRectangleCover(rectangles) << endl;
	return 0;
}