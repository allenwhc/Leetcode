#include <iostream>
#include <vector>
using namespace std;

class Solution{
	vector<int> arr;
public:
	Solution(vector<int> &nums):arr(nums){}

	vector<int> reset(){
		return arr;
	}

	vector<int> shuffle(){

	}
};

int main(int argc, char const *argv[])
{
	vector<int> nums = {1,2,3};
	Solution sol = new Solution(nums);
	vector<int> shuffled = sol.shuffle();
	vector<int> reset = sol.reset();
	return 0;
}