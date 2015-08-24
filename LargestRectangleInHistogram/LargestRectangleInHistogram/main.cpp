/*
*	Largest Rectangle in Histogram
*	Last Modified: 7/28/2015
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& height) {
		int n = height.size();
		stack<int> idxRect;
		if (n == 0) return 0;
		int maxArea = INT_MIN;

		int i = 0;
		while(i<n){
			if (idxRect.empty() || height[i] >= height[idxRect.top()]){
				idxRect.push(i);
				i++;
			}
			else{
				int j = idxRect.top();
				idxRect.pop();
				int width = idxRect.empty() ? i : i - idxRect.top() - 1;
				maxArea = max(maxArea, width*height[j]);
			}
		}

		//Clean up the stack
		while (!idxRect.empty()){
			int j = idxRect.top();
			idxRect.pop();
			int width = idxRect.empty() ? i : i - idxRect.top() - 1;
			int currArea = width*height[j];
			maxArea = max(maxArea, currArea);
		}

		return maxArea;
	}
};

void main(int argc, char* argv[]){
	vector<int> height = { 0, 2, 0 };
	Solution sol;
	cout << "The maximum area of the rectangle is: " << sol.largestRectangleArea(height) << endl;
	system("pause");
}