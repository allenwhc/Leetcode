#include <iostream>
#include <vector>
using namespace std;

struct CompareX{
	bool operator()(pair<int,int> p1, pair<int,int> p2){
		return p1.first < p2.first;
	}
};

bool isReflected(vector<pair<int, int>> &points){
	if (points.empty()) return true;
	sort(points.begin(), points.end());
	// for (auto it = points.begin(); it!=points.end(); it++) cout<<it->first<<" "<<it->second <<endl;
	vector<pair<int, int>> reversePoints;
	for (auto it = points.begin(); it!=points.end(); it++){
		reversePoints.push_back(make_pair(points[0].first + points.back().first - it->first, it->second));
	}
	sort(reversePoints.begin(), reversePoints.end());
	return equal(points.begin(), points.end(), reversePoints.begin());
}

int main(int argc, char const *argv[])
{
	vector<pair<int, int>> points = {{1,2},{2,4},{1,4},{2,2}};
	cout << isReflected(points) << endl;
	return 0;
}