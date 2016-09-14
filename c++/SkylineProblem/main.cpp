#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
*	Heap solution
*	Time complexity: O(nlogn)
*	Extra space: O(n)
*/
class Solution{
	struct Building{
		int start,end;
		bool left;
		Building():start(0),end(0),left(true){}
		Building(int s, int e, bool b): start(s),end(e),left(b){}
	};
public:
	vector<pair<int,int>> getSkyline(vector<vector<int>>& buildings){
		vector<pair<int,int>> res;
		vector<Building> lines;
		for(auto building: buildings){
			lines.push_back(Building(building[0],building[2],true));
			lines.push_back(Building(building[1],building[2],false));
		}
		sort(lines.begin(), lines.end(), [](const Building& b1, const Building& b2)->bool{
			if(b1.start != b2.start) return b1.start < b2.start;
			else{ 
				// if(b1.left && !b2.left) return true;
				// else if(!b1.left && b2.left) return false;
				// else if(b1.left && b2.left) return b1.end > b2.end;
				// else if(!b1.left && !b2.left) return b1.end < b2.end;
				return (b1.left? -b1.end:b1.end) <= (b2.left? -b2.end:b2.end);
			}
		});
		map<int,int> heap;
		heap[0] = 1;
		int prev_max_height = 0;

		for(Building b: lines){
			if(b.left){
				if(heap.find(b.end) != heap.end()) heap[b.end]++;
				else heap[b.end] = 1;
			}
			else{
				if(heap[b.end] == 1) heap.erase(b.end);
				else heap[b.end]--;
			}

			int curr_max_weight = heap.rbegin()->first;
			// cout << "prev: " << prev_max_height << endl;
			// cout << "curr: " << curr_max_weight << endl;

			if(prev_max_height != curr_max_weight){
				res.push_back(make_pair(b.start, curr_max_weight));
				prev_max_height = curr_max_weight;
			}
			// for(auto it=heap.begin(); it!=heap.end(); ++it) cout<<it->first<<"," <<it->second << endl;
			// cout << "res: " << endl;
			// for(auto v: res){
			// 	cout <<v.first<<","<<v.second << endl;
			// }
			// cout << endl;
		}

		// for(int i=0; i<lines.size(); i++){
		// 	cout<< lines[i].start <<","<<lines[i].end<<","<<lines[i].left << endl;
		// }
		return res;
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	vector<vector<int>> buildings = {{1,2,1},{1,2,2},{1,2,3}};
	Solution sol;
	vector<pair<int,int>> skyline = sol.getSkyline(buildings);
	for(auto it: skyline){
		cout <<it.first <<", "<< it.second << endl;
	}
	return 0;
}