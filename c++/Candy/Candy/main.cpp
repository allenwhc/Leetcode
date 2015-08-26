/*
*	Candy
*	Last Modified: 6/17/2015
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int candy(vector<int>& ratings){
		int n = ratings.size();
		if (n == 0) return 0;
		else if (n == 1) return 1;
		else{	
			vector<int> candies(n);
			for (int i = 0; i < n; i++)
				candies[i] = 1;		//Initializes all candies at 1
			//Scans from left to right, if child i's rating is greater than that of child i-1, candy[i] = candy[i-1] +1
			for (int i = 1; i < n; i++){
				if (ratings[i] > ratings[i - 1])
					candies[i] = candies[i - 1] + 1;
			}

			//Scans from right to left, if child i's rating is greater than that of child i-1, and candy[i] <= candy[i-1], candy[i]=candy[i+1]+1
			for (int i = n - 2; i >= 0; i--){
				if (ratings[i]>ratings[i + 1] && candies[i] <= candies[i + 1])
					candies[i] = candies[i + 1] + 1;
			}
			int sum = 0;
			for (int i = 0; i < n; i++)
				sum += candies[i];
			return sum;
		}
	}
};

void main(int argc, char *argv[]){
	vector<int> ratings = { 2, 3, 1, 4, 2, 3, 5, 6, 2 };
	Solution s;
	int minimum = s.candy(ratings);
	cout << "The minimum number of candies is: " << minimum << endl;
	system("pause");
}