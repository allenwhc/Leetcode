#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinArrowShots(vector<pair<int,int>>& points){
	int n = points.size();
	if(!n) return 0;
	auto Compare = [](pair<int,int>& p1, pair<int,int>& p2){
		if(p1.first != p2.first) return p1.first < p2.first;
		else return p1.second < p2.second;
	};
	sort(points.begin(), points.end(), Compare);
	int res = 1;
	auto range = points[0];
	for(int i=1; i<n; ++i){
		if(points[i].first <= range.second){
			range.first = max(range.first, points[i].first);
			range.second = min(range.second, points[i].second);
		}
		else{
			range = points[i];
			++res;
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	vector<pair<int,int>> points = {{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};
	cout << findMinArrowShots(points) << endl;
	return 0;
}