/*
*	Best Time to Buy and Sell Stock I, II & III
*	Last Modified: 6/9/2015
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
	//Only allowed to buy or sell stock once at a time
	int maxProfit(vector<int>& prices){
		int n = prices.size();
		if (n <= 1)
			return 0;
		else{
			int max = 0;
			int difference = 0;
			int minPrice = INT_MAX;
			for (int i = 0; i < n; i++){
				if (prices[i] < minPrice)
					minPrice = prices[i];
				difference = prices[i] - minPrice;
				if (difference > max)
					max = difference;
			}
			return max;
		}
	}

	//Allowed to buy or sell stock multiple times
	int maxProfitMultiple(vector<int>& prices){
		int n = prices.size();
		if (n <= 1)
			return 0;
		else{
			int sum = 0;
			int difference = 0;
			int i = 0;
			while (i < n - 1)
			{
				if (prices[i] < prices[i + 1]){
					difference = prices[i + 1] - prices[i];
					if (difference > 0)
						sum += difference;
				}
				i++;
			}
			return sum;
		}
	}

	//Limited by two transactions with no multiple operations at a time
	int maxProfitTwoTransactions(vector<int>& prices){
		int n = prices.size();
		if (n <= 1)
			return 0;
		else{
			vector<int> leftMaxProfit(n);
			vector<int> rightMaxProfit(n);
			int totalMaxProfit = 0;
			//Calculates maximum profit from left to right
			leftMaxProfit[0] = 0;
			int minPrice = prices[0];
			for (int i = 1; i < n; i++){
				minPrice = min(minPrice, prices[i]);
				leftMaxProfit[i] = max(leftMaxProfit[i - 1], prices[i] - minPrice);
			}

			//Calculates maxmimum profit from right to left
			rightMaxProfit[n - 1] = 0;
			int maxPrice = prices[n - 1];
			for (int i = n - 2; i >= 0; i--){
				maxPrice = max(maxPrice, prices[i]);
				rightMaxProfit[i] = max(rightMaxProfit[i + 1], maxPrice - prices[i]);
			}
			
			//Calculates the total maximum profit by adding left and right maximum profit
			for (int i = 0; i < n; i++)
				totalMaxProfit = max(totalMaxProfit, leftMaxProfit[i] + rightMaxProfit[i]);
			return totalMaxProfit;
		}
	}
};

void main(int argc, char *argv[]){
	vector<int> nums = { 10, 115, 5, 6, 7, 100, 35, 20, 84, 16 };
	vector<int> prices = { 6, 1, 3, 2, 4, 7 };
	Solution s;
	int max1 = s.maxProfit(nums);
	int max2 = s.maxProfitMultiple(nums);
	int max3 = s.maxProfitTwoTransactions(prices);
	cout << "The maxmimum profit is (only one operation at a time): " << max1 << endl;
	cout << "The maxmimum profit is (multiple operations at a time): " << max2 << endl;
	cout << "The maxmimum profit is (limited by 2 transactions and no multiple operations): " << max3 << endl;
	system("pause");
}