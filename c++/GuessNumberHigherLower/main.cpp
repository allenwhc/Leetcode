#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int picked_num = 6;

int guess(int num){
	if(num < picked_num) return 1;
	else if(num > picked_num) return -1;
	else return 0;
}
class Solution{
public:
	int getMoneyAmount(int n){
		vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
		return search(dp, 1, n);
	}

	int search(vector<vector<int>> dp, int s, int e){
		if(s >= e) return 0;
		if(dp[s][e] != 0) return dp[s][e];
		cout << s <<"," << e<<endl;
		cout <<dp[s][e]<<endl;
		int res = INT_MAX;
		for(int i=s; i<=e; i++){
			int temp = max(search(dp, s, i-1), search(dp, i+1, e));
			res = min(res, temp);
		}
		dp[s][e] = res;
		return res;
	}
};


int main(int argc, char const *argv[])
{
	/* code */
	int n = 10;
	Solution sol;
	cout << "Min amount: " << sol.getMoneyAmount(n) << endl;
	return 0;
}