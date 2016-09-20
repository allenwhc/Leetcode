#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class Solution{
	vector<int> n;
public:
	Solution(vector<int>& nums){
		n = nums;
	}

	int pick(int target){
		int sz = 0, idx = -1;
		for(int i=0; i<n.size(); i++){
			if(target == n[i] && rand()%(++sz) == 0) idx = i;
		}
		return idx;
	}
};

int main(int argc, char const *argv[])
{
	vector<int> nums = {1,2,3,3,3};
	Solution sol(nums);
	srand(time(NULL));
	cout << sol.pick(3) << "," << sol.pick(3) << "," << sol.pick(3) << endl;
	return 0;
}