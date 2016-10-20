#include <iostream>
#include <vector>
#include <set>
using namespace std;

int findMaximumXOR(vector<int>& nums){
	if(nums.empty()) return 0;
	int res = 0;
	int pre_xor = 0;
	set<int> hashSet;
	for(int i=31; i>=0; i--){
		pre_xor = pre_xor | (1<<i);
		for(int n: nums) hashSet.insert(n&pre_xor);
		int temp = res | 
		for(auto it=hashSet.begin(); it!=hashSet.end(); ++it) cout<<*it<<" ";
		cout<<endl;
	}
	return res;
}


int main(int argc, char const *argv[])
{
	/* code */
	vector<int> nums = {3,10,5,25,2,8};
	cout << findMaximumXOR(nums) << endl;
	return 0;
}