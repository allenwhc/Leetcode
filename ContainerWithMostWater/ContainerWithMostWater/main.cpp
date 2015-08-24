/*
*	Container with Most Water
*	Last Modified: 6/8/2015
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
	int maxArea(vector<int>& height){
		int n = height.size();
		if (n <= 1)
			return 0;
		else
		{
			int area = 0;
			int left = 0;
			int right = n - 1;
			while (left < right)
			{
				area = max(area, min(height[left], height[right])*(right - left));
				if (height[left] < height[right])
					left++;
				else
					right--;
			}
			return area;
		}
	}
};

void main(int argc, char *argv[]){
	int area1 = 0, area2 = 0;
	Solution s;
	vector<int> height1 = { 1, 5, 6, 2, 4, 10, 6, 5, 2, 10, 3, 7, 4, 1};
	vector<int> height2 = { 5, 2, 7, 9, 1, 6, 3, 8, 4, 10 };
	area1 = s.maxArea(height1);
	area2 = s.maxArea(height2);
	cout << "The maximum volume of container1 is: " << area1 << endl;
	cout << "The maximum volume of container2 is: " << area2 << endl;
	system("pause");
}

