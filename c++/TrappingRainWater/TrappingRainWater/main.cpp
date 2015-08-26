/*
*	Trapping Rain Water
*	Last Modified: 7/15/2015
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int trap(vector<int>& height){
		int n = height.size();
		if (n == 0) return 0;
		int water = height[0];
		vector<int> maxLeft(n), maxRight(n);

		//Scan from left to right, find left max value for each point
		maxLeft[0] = 0;
		for (int i = 1; i < n; i++){
			maxLeft[i] = water;
			water = max(water, height[i]);
		}
		water = height[n - 1];

		//Scan from right to left, find right max value for each point
		maxRight[n - 1] = 0;
		for (int i = n - 2; i >= 0; i--){
			maxRight[i] = water;
			water = max(water, height[i]);
		}
/*
		for (int x : maxLeft) cout << x << " ";
		cout << endl;
		for (int y : maxRight) cout << y << " ";*/

		//Scan again, sum up the difference between left max and right max value
		int x = 0;
		int trap = 0;
		for (int i = 0; i < n; i++){
			x = min(maxLeft[i], maxRight[i]) - height[i];
			if (x>0) trap += x;
		}

		return trap;
	}
};

void main(int argc, char *argv[]){
	vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	Solution s;
	cout << "The amount of water that the map is capable to contain is: " << s.trap(height) << endl;
	system("pause");
}