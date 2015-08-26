#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	void sortColor(vector<int> & nums){
		int numOfColors[3] = { 0, 0, 0 };
		vector<int> sortedColors;
		for (int i = 0; i < nums.size(); i++)
		{
			switch (nums[i])
			{
			case 0:
				numOfColors[0]++;
				break;
			case 1:
				numOfColors[1]++;
				break;
			case 2:
				numOfColors[2]++;
				break;
			default:
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < numOfColors[i]; j++)
			{
				nums.push_back(i);
			}
		}
		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << " ";
		}
	}
};

void main(int argc, char*argv[]){
	vector<int> colorCode = { 1, 0 };	//'0' for red, '1' for white, and '2' for blue
	Solution s;
	s.sortColor(colorCode);
	system("pause");
}