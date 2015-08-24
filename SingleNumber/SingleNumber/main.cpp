#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
	int singleNumber(vector<int> & nums){
		int single = 0;
		bool isSingle = false;
		sort(nums.begin(), nums.end());
		int i = 0;
		if (nums.size() == 1)
		{
			single = nums[0];
		}
		if (nums.size() > 1)
		{
			while (i < nums.size() - 1)
			{
				if (nums[i] == nums[i + 1])
				{
					i = i + 2;
				}
				else
				{
					single = nums[i];
					break;
				}
				single = nums[i];
			}
		}
		
		return single;
	}
};

void main(int argc, char* argv[]){
	vector<int> nums = { -5, 3, -5, 10, 3, 5, 5, 6, 7, 7, 10 };
	Solution s;
	int single = 0;
	single = s.singleNumber(nums);
	cout << "The single number is: " << single << endl;
	system("pause");
}