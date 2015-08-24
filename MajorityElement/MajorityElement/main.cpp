/*
*	Majority Element I & II
*	Last Modified: 7/15/2015
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

class Soluion{
public:
	//Majority element I, number appears more than n/2 times
	int majorityElement1(vector<int> &nums){
		int n = nums.size();
		if (n == 1) return nums.back();
		else{
			sort(nums.begin(), nums.end());
			int i = 0;
			while (i<n)
			{
				if (nums[i] == nums[i + n / 2])
					return nums[i];
				else
					i++;
			}
		}
	}

	//Majority element II, number appears more than n/3 times
	vector<int> majorityElement2(vector<int>& nums){
		vector<int> majority;
		int n = nums.size();
		if (n == 0) return majority;
		else if (n == 1){
			majority.push_back(nums.back());
			return majority;
		}
		else{
			int n1 = nums[0], c1 = 1, n2 = 0, c2 = 0;
			for (int i = 1; i < n; i++){
				int curNum = nums[i];
				if (curNum == n1) c1++;
				else if (curNum == n2) c2++;
				else if (c1 == 0){
						c1 = 1;
						n1 = curNum;
					}
				else if (c2 == 0){
						c2 = 1;
						n2 = curNum; 
					}
				else{
						c1--;
						c2--;
				}
			}

			c1 = 0, c2 = 0;
			for (int i = 0; i < n; i++){
				if (nums[i] == n1) c1++;
				else if (nums[i] == n2) c2++;
			}
			if (c1 > n / 3) majority.push_back(n1);
			if (c2 > n / 3) majority.push_back(n2);
			return majority;
		}
	}
};

void main(int argc, char *argv[]){
	vector<int> nums = { 4, 2, 3, 4, 4, 3, 4, 4, 1 };
	vector<int> nums1 = { 3, 2, 3 };
	Soluion s;
	int majority = s.majorityElement1(nums);
	cout << "Test array 1: ";
	for (int x : nums)
		cout << x << " ";
	cout << endl;
	cout << "The majority element appears more than " << nums.size() / 2 << " times is: " << majority << endl;
	cout << "Test array 2: ";
	for (int x : nums1)
		cout << x << " ";
	cout << endl;
	cout << "The majority elements appears more than " << nums1.size() / 3 << " times are: ";
	for (int x : s.majorityElement2(nums1))
		cout << x << " ";
	cout << endl;
	system("pause");
}