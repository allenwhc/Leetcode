#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
	vector<int> twoSum(vector<int>& nums, int target){
		vector<int> index;
		map<int, int> hmap;
		for (int i = 0; i < nums.size(); i++)
			hmap[nums[i]] = i;
		for (int i = 0; i < nums.size(); i++)
		{
			if (hmap.find(target - nums[i]) != hmap.end())
			{
				if (i < hmap[target - nums[i]])
				{
					index.push_back(i + 1);
					index.push_back(hmap[target - nums[i]] + 1);
					return index;
				}
				else if (i > hmap[target - nums[i]])
				{
					index.push_back(hmap[target - nums[i]] + 1);
					index.push_back(i + 1);
					return index;
				}
			}
		}
		return index;
	}
};

void main(int argc, char*argv[])
{
	vector<int> nums = { 3,3,10,6,21,1,4,11 };
	int target = 14;
	Solution s;
	vector<int> index;
	index = s.twoSum(nums, target);
	for (int i = 0; i < index.size(); i++)
		cout << "index " << i + 1 << " = " << index[i] << ",";
	system("pause");
}