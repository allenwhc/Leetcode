/*
*	Max Points on a Line
*	Last Modified: 7/27/2015
*	Hint:
		for each point i in the plane:
			for each point j in the plane:
				if i!=j,
					if i, j on a vertical line
						if i, j are the same
							repeat++
						else
							map.insert(int_max)
					else
						compute slope
						map.insert(slope)
			p=(map.empty)?0:1;
			for each key in the map
				p=max(p,map.count(key))
			count=max(count,p+repeat)
		return count

Output the max number
*/

#include <iostream>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	int maxPoints(vector<Point>& points) {
		int n = points.size();
		if (n == 0) return 0;
		unordered_multimap<double, int> slope;
		int count = 0;
		//For each point in the plane
		for (int i = 0; i < n; i++){
			slope.clear();
			int repeat = 1;	//Count duplicate points in the array
			for (int j = 0; j < n; j++){
				if (i != j){
					//First, determine if two points are on a vertical line
					if (points[i].x == points[j].x){
						//If two points are duplicate, repeat++
						if (points[i].y == points[j].y)
							repeat++;
						else{
							//slopei[j] = INT_MAX;
							slope.insert(make_pair(INT_MAX, j));
						}
					}
					else{
						double slopeij = ((double)points[j].y - (double)points[i].y) / ((double)points[j].x - (double)points[i].x);
						slope.insert(make_pair(slopeij, j));
					}
				}
			}

			//Find number of duplicate slopes
			int p = 1;	//Contain the point itself
			if (slope.size() == 0) p = 0;

			for (unordered_multimap<double, int>::iterator it = slope.begin(); it != slope.end(); ++it){
				p = max(p, (int) slope.count(it->first));
			}
			count = max(count, p + repeat);
		}
		return count;
	}
};

void main(int argc, char *argv[]){
	Point p1(1, 1);
	Point p2(2, 2);
	Point p3(3, 2);
	Point p4(3, 3);
	Point p5(3, 5);
	Point p6(4, 1);
	Point p7(4, 4);
	Point p8(5, 0);
	Point p9(5, 3);

	vector<Point>points = { p1, p2, p3, p4, p5, p6, p7, p8, p9 };
	Solution sol;
	cout << "The maximum number of points on a line is: " << sol.maxPoints(points) << endl;
	system("pause");
}