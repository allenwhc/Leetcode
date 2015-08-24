/*
*	House Robber I & II
*	Last Modified: 6/21/2015
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution{
public: 
	//All houses lined up on a street
	int rob1(vector<int>& nums){
		int n = nums.size();
		if (n == 0) return 0;
		else if (n == 1) return nums.back();
		else if (n == 2) return max(nums[0], nums[1]);
		else{
			vector<int> money(n);
			money[0] = nums[0];
			money[1] = max(nums[0], nums[1]);
			for (int i = 2; i < n; i++){
				money[i] = max(money[i - 1], money[i - 2] + nums[i]);
			}
			return money[n - 1];
		}
	}

	//All houses on a circle
	int rob2(vector<int>&  nums){
		int n = nums.size();
		if (n == 0) return 0;
		else if (n == 1) return nums.back();
		else if (n == 2) return max(nums[0], nums[1]);
		else{
			vector<int> moneyFirst(n + 1);	//Includes the first element, but not the last element
			vector<int> moneyLast(n + 1);	//Includes the last element, but not the first element
			
			//The robbing list includes the first house
			moneyFirst[0] = 0; 
			moneyFirst[1] = nums[0];
			for (int i = 2; i < n; i++)
				moneyFirst[i] = max(moneyFirst[i - 2] + nums[i - 1], moneyFirst[i - 1]);

			//The robbling list includes the last house
			moneyLast[0] = 0;
			moneyLast[1] = nums[1];
			for (int i = 2; i < n; i++)
				moneyLast[i] = max(moneyLast[i - 2] + nums[i], moneyLast[i - 1]);

			return max(moneyFirst[n - 1], moneyLast[n - 1]);
		}
	}
};

void main(int argc, char *argv[]){
	vector<int> nums = { 4, 2, 5, 1, 7, 10, 4, 1, 3, 7 };
	Solution s;
	int maxMoney1 = s.rob1(nums);
	cout << "The maximum amount of money one can rob on a straight street is: " << maxMoney1 << endl;
	int maxMoney2 = s.rob2(nums);
	cout << "The maximum amount of money one can rob on a circular street is: " << maxMoney2 << endl;
	system("pause");
}