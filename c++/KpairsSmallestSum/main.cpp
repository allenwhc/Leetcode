#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

/*
*	Heap solution
*	Time complexity: O(k*log(max(m, n)))
*	Extra space: O(mn)	
*/

struct Point{
	int i;
	int j;
	int sum;
	Point(){}
	Point(int a, int b, int s):i(a),j(b),sum(s){}
};

struct Compare{
	bool operator()(Point p1, Point p2){
		if(p1.sum != p2.sum) return p1.sum > p2.sum;
		else return p1.j > p2.j;
	}
};

vector<pair<int,int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k){
	vector<pair<int,int>> res;
	int m = nums1.size(), n = nums2.size();
	if(nums1.empty() || nums2.empty() || !k) return res;
	priority_queue<Point, vector<Point>, Compare> pq;
	set<pair<int,int>> st;
	Point min_point(0, 0, nums1[0] + nums2[0]);
	pq.push(min_point);

	for(int i=0; i<k && !pq.empty(); i++){
		min_point = pq.top();
		pq.pop();
		res.push_back(make_pair(nums1[min_point.i], nums2[min_point.j]));

		if(min_point.i < m - 1){
			Point newPoint(min_point.i + 1, min_point.j, nums1[min_point.i + 1] + nums2[min_point.j]);
			if(st.find(make_pair(newPoint.i, newPoint.j)) == st.end()){
				st.insert(make_pair(newPoint.i, newPoint.j));
				pq.push(newPoint);
			}
		}
		if(min_point.j < n - 1){
			Point newPoint(min_point.i, min_point.j + 1, nums1[min_point.i] + nums2[min_point.j + 1]);
			if(st.find(make_pair(newPoint.i, newPoint.j)) == st.end()){
				st.insert(make_pair(newPoint.i, newPoint.j));
				pq.push(newPoint);
			}
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	vector<int> nums1 = {1,1,2};
	vector<int> nums2 = {1,2,3};

	int k = 10;
	for(auto &v: kSmallestPairs(nums1,nums2,k)){
		cout << v.first << "," << v.second << endl;
	}

	return 0;
}