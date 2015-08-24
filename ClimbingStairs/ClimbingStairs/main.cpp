/*
*	Climbing Stairs
*	Last Modified: 6/24/2015
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int climbStairs(int n){
		if (n <= 2) return n;
		else{
			vector<int> ways(n);
			ways[0] = 1;
			ways[1] = 2;
			for (int i = 2; i < n; i++)
				ways[i] = ways[i - 1] + ways[i - 2];
			return ways[n - 1];
		}
	}
};

void main(int argc, char* argv[]){
	int n = 10;
	Solution s;
	int ways = s.climbStairs(n);
	cout << "There are " << ways << " ways to climb up to a " << n << "-step stairs" << endl;
	system("pause");
}