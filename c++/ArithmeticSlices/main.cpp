#include <iostream>
#include <vector>
using namespace std;

int numberOfArithmeticSlices(vector<int>& A){
	int n = A.size();
	if(n<=2) return 0;
	int i = 0;
	vector<int> dp(n,0);
	while(i<n-1){
		int j = i + 1;
		int diff = A[j] - A[i];
		while(j<n && A[j]-A[j-1] == diff){
			if(j-i<2) {dp[j] = dp[j-1];j++;continue;}
			dp[j] = dp[j-1] + j - i - 1;
			j++;
		}
		i = j - 1;
		//dp[i] = dp[i-1];
	}
	// for(auto x: dp)
	// 	cout << x << " ";
	// cout << endl;
	return dp[n-1];
}

int main(int argc, char const *argv[])
{
	vector<int> A = {27,2,-32,38,-21,27,-44,34,-31,-5,-2,-20,7,-31,14,5,30,-12,-23,-10,13,28,-19,21,-45,15,-33,16,47,-23,-25,-22,45,43,-4,14,-46,36,11,-21,-19,35,47,39,29,-41,-9,-34,29,-11,-43,-18,45,-5,12,0,14,-41,48,-11,10,22,-15,12,-35,42,5,-2,-8,31,-23,45,-17,25,-21,-12,-6,-2,0,-21,33,7,-35,-6,43,10,-38,-12,40,10,-9,18,-31,18,-1,31,-9,-17,2,-12,-38,-16,40,-46,26,-44,38,39,10,-4,10,-17,-24,-21,28,40,-5,-33,-23,8,-3,8,-9,-25,-38,23,-50,15,25,-30,46,12,-6,39,28,-1,-48,38,28,-44,-9,-22,13,-21,3,-10,24,-33,-13,35,18,3,-49,-45,23,19,15,0,-9,-1,-17,-39,-50,-3,33,32,-32,41,-44,-23,42,-5,-42,-10,46,-28,8,-23,38,13,30,6,46,7,-45,21,5,-28,-10,36,6,-36,33,-31,15,-41,15,11,-14,-27,-27,-22,5,-12,-34,27,-6,39,36,-13,2,-2,-41,39,-29,-1,-29,5,22,12,-16,22,13,16,-10,6,41,-29,12,-24,-3,-29,-7,31,-8,-36,2,-49,-6,-2,-48,-11,5,43,49,48,-30,18,34,-27,6,22,32,-42,-36,18,42,-33,-44,-18,-43,-12,-11,45,7,-3,-15,27,45,-2,-49,9,-18,28,-32,-35,27,8,-43,-34,-37,-21,-20,-43,30,-43,-4,11,9,7,42,-30,27,-28,27,5,18,-34,4,-21,37,41,21,28,22,-41,20,48,-38,33,26,-5,-36,39,-45,-45,-33,28,-38,33,46,-4,-4,-36,-49,-33,-30,48,-27,24,21,-12,-22,43,-6,-19,-47,-9,1,27,31,43,32,22,-44,33,-19,-14,-39,40,-7,-35,-15,-40,45,21,-37,32,6,0,35,24,9,17,-5,7,-6,18,10,9,-22,-32,15,-42,-27,38,-24,-23,42,-20,-24,16,-8,19,8,-31,-36,-41,-11,30,27,8,-19,-13,5,23,-26,26,-20,-12,35,4,-22,-22,-50,20,-25,8,21,-14,-4,45,-25,21,44,31,9,43,34,-20,-7,27,33,-49,16,-14,12,1,7,-30,-48,-48,20,-33,24,16,-16,33,8,-22,0,-31,18,-10,-10,-3,-40,42,31,-15,33,16,31,-42,-45,-18,5,-33,-17,-40,43,-13,22,-39,-44,-7,6,17,-48,-33,17,35,-48,40,12,-37,8,19,24,26,-34,47,-27,-50,10,-46,-44,9,-21,9,-13,-29,-11,-7,-16,-18,-4,28,-45,-5,-16,25,47,-7,-27,-43,48,31,-10,42,25,10,-1,24,-2,-15,-21,-33,-15,-21,0,-20,43,43,-29,16,21,45,48,-11,-15,21,33,-35,22,25,-27,28,-38,48,-35,16,14,38,8,10,25,-11,37,6,41,-11,-42,-40,-13,-13,42,32,36,15,32,44,-19,22,9,30,-2,2,45,40,-32,-16,23,23,-9,1,-35,-48,-12,42,-41,1,13,-26,35,-7,20,34,-7,17,15,6,36,-38,1,6,38,43,9,-23,16,20,10,-37,-10,48,-40,44,-4,3,17,-15,-4,15,-31,9,-9,38,-27,-4,30,10,31,-1,-18,-1,-29,4,-23,-19,10,-26,41,21,7,-26,12,-20,20,33,-34,36,-42,-46,-29,29,6,39,-42,9,27,-11,-25,-35,-35,-50,-7,12,11,26,-23,-7,19,37,27,-45,29,-49,-27,49,-21,-34,48,8,-26,20,7,29,-34,36,-16,-49,13,22,11,14,-23,41,14,40,9,37,-24,33,49,24,5,-47,45,-46,13,-30,38,-44,-40,1,19,0,-9,-17,46,37,-3,-31,-40,43,3,13,-28,44,20,-14,28,-3,40,-32,-4,49,22,-38,-14,-14,17,-39,-25,29,22,26,-9,-2,11,-17,-14,25,-16,0,14,-30,-16,-43,8,-18,-19,22,49,47,-28,36,-21,-41,-43,37,22,44,-41,21,9,-19,-8,-10,-46,27,20,4,21,12,-24,5,11,46,-31,13,-47,14,-45,-30,48,49,-21,-46,-13,43,-6,25,-41,6,45,-9,-20,-46,10,-46,41,7,-8,17,-2,-47,0,45,-3,48,-17,-19,25,-18,26,-34,21,-19,22,-7,31,41,-33,19,25,3,-3,27,-7,31,10,-18,14,31,6,30,-35,20,-12,-5,22,48,32,-10,5,29,36,45,5,-40,-44,10,-4,-33,-48,-38,-7,-31,41,13,25,-12,1,-5,-23,-45,-5,-39,6,-35,43,14,-7,-41,-46,-23,-37,-40,-23,-14,-33,8,20,-46,44,41,-8,39,-41,-11,-16,23,18,45,-35,23,43,1,24,-1,34,32,8,39,35,37,25,-37,-13,14,6,-38,-39,18,-17,-28,-12,37,-4,21,11,-33,-24,3,46,-28,-14,-1,35,10,45,-37,18,47,-48,35,22,2,-17,32,18,16,8,-9,5,-19,-31,-18,2,-21,8,43,47,-3,-1,-27,-29,-3,29,44,-16,9,0,28,29,-35,-49,48,1,35,44,-28,5,28,-27,28,0,39,44,46,23,-27,45,-46,-13,2,15,38,-37,2,34,26,28,-20,34,-46,-10,-44,3,-40,2,7,8,12,16,19,-7,-6,44,13,31,41,31,35,17,-32,17,-9,49,-13,27,17,-11,-42,32,8,-22,48,45,44,-30,-9,-20,35,-2,28,-40,33,29,5,40,9,-17,-20,-6,-10,-13,12,38,-39,-27,-18,-43,16,49,-50,-7,9,20,-19,19,41,-26,-23,39,-17,26,-6,-44,-44,11,14,-15,11,7,-9,-49,-5,48,40,-49,6,19,13,-37,-16,22,47,35,28,47,13,2,26,-4,-44,-1,46,40,-22,-45,-2,3,-37,27,25,15,-35,-20,-13,49,-18,45,-12,8,-44,26,40,45,-41,16,-45,-13,-41,38,23,-6,48,23,16,26,6,12,-15,1,-43,9,-17,18,49,43,42,28,12,-25,-45,20,30,44,47,-13,-29,-30,-28,0,37,33,40,31,-50,-19,48,-33,-42,-2,1,-36,42,-44,42,10,2,25,32,-21,35,-46,38,23,-5,28,6,37,-9,20,27,-5,33,45,-24,42,-12,-2,38,37,-17,10,-13,48,-47,-43,9,14,36,33,9,-7,23,18,13,-38,49,31,-45,30,17,9,26,-17,-38,-45,-39,-25,-39,27,38,-49,-23,21,-6,5,-49,38,30,22,-8,9,-16,-43,-21,42,30,5,-33,48,-39,-46,25,-38,-31,-50,-2,-43,34,-18,-45,-25,-32,22,43,-16,-37,-4,1,6,18,6,5,-16,-18,18,44,41,-13,9,33,4,-49,46,-8,-5,19,10,6,-19,0,47,-28,-6,-43,-12,2,42,14,-46,47,-15,47,-15,-11,29,-20,-31,39,-15,19,-9,-49,34,-18,-21,-31,29,48,-46,-36,-24,4,10,48,24,-48,22,-24,-36,-42,-38,40,32,20,15,-8,-48,-3,-38,-17,-45,34,-7,20,-40,-28,32,1,3,-43,15,12,-16,-15,-5,-29,40,26,-18,-37,-2,17,14,30,13,45,-18,22,-10,1,11,-34,-40,47,-14,42,-24,6,-16,-27,34,-2,-19,14,15,-4,48,-20,-35,-36,41,-33,9,26,-18,24,40,2,-50,41,-46,3,21,31,-13,-23,26,22,2,12,10,1,-32,-50,-49,-16,-31,-44,33,2,8,38,-40,-4,-18,2,38,-33,-13,43,-34,-48,-31,-50,-20,-18,-8,16,-48,32,-3,31,47,22,47,-16,43,49,37,37,-18,27,-5,6,47,36,-49,-24,-37,-5,-34,-50,-12,-50,-3,28,-13,-49,-16,-40,-45,5,-44,-35,-3,-15,10,23,11,-26,16,1,12,38,-4,-30,30,-39,-31,-21,-7,-16,-30,27,-25,-2,-25,47,37,24,-38,45,-30,49,5,-38,-20,-34,0,-6,26,20,-41,17,40,46,-15,24,0,41,39,5,-7,-14,-25,-43,-29,-27,47,-41,25,-38,42,25,-24,28,-45,48,-29,-24,21,-14,18,-28,10,22,28,-3,-10,41,20,-2,29,25,-45,27,19,-28,-36,-43,8,-36,24,31,25,17,38,-2,-21,-14,19,6,-47,-4,15,23,-9,13,42,-39,48,-16,-45,-14,-36,5,-40,18,-31,-50,-4,-45,-31,-25,49,28,41,-32,3,-46,11,-37,4,23,42,0,-35,-45,37,-35,-36,15,6,-42,-30,25,-9,44,32,-32,-6,1,38,47,0,-5,38,-24,48,30,-34,34,9,-26,13,-26,-17,-32,48,-41,-25,12,42,33,-33,42,16,40,49,24,3,-49,-35,36,46,-47,40,14,-23,-25,-49,-48,-32,-48,7,6,-43,-20,40,-20,-21,14,-29,34,-30,4,-45,-48,32,4,-32,-28,-22,-17,-31,39,22,24,42,-49,26,-11,25,26,46,-11,37,-39,28,12,-17,14,-4,-7,-32,-41,2,-38,42,-40,-50,-17,3,-33,28,3,-16,19,-27,34,16,2,-12,7,-43,-10,32,46,-36,24,2,-30,-10,-49,15,10,6,41,14,2,39,1,-47,44,47,-16,23,-23,47,-38,16,39,34,34,21,44,-5,-2,16,24,44,8,-16,-41,33,-30,26,49,-2,-39,22,16,-39,30,45,-29,15,-7,29,-35,40,-37,42,-34,-22,-39,-26,-20,-45,-6,-37,-39,24,-50,-27,-44,49,-7,37,-6,1,31,-43,-41,-17,18,20,-31,28,-35,34,29,-26,13,-49,-35,2,28,11,46,40,2,1,14,19,30,-44,14,15,-14,42,42,-2,18,-35,29,-5,11,-1,34,-39,39,-11,41,-3,42,3,-33,47,-38,22,39,-48,38,-28,43,-26,26,-33,-45,14,49,-20,11,47,-37,-16,-3,38,28,36,-20,-31,14,33,15,-20,-3,-2,36,44,0,31,-46,-42,4,3,26,-43,-3,-41,-50,-41,44,-20,3,-17,17,-44,-32,-13,15,41,-26,-34,9,-12,23,15,3,-20,25,7,-48,-23,8,18,21,-49,7,22,39,34,5,-40,-15,-38,24,-15,-18,47,-21,-19,31,-37,-43,27,7,13,-7,-43,-1,-41,44,1,23,20,-12,-41,-20,-15,-40,10,-15,-37,3,0,-48,-40,-11,-22,-27,18,-1,5,42,-13,-47,-37,-42,-25,-3,4,12,-22,39,-40,-29,-23,2,-17,38,1,-31,9,6,17,22,-34,-23,2,-24,30,6,47,-29,-50,-36,31,21,7,-47,45,40,-24,-31,-19,23,37,34,-19,-13,-8,44,17,-42,2,-19,-22,-12,-30,-8,-24,-29,16,21,8,44,32,-11,-22,-7,23,-10,-44,44,-43,12,13,-49,5,-26,1,-35,23,-2,46,-30,18,41,22,22,-25,0,47,16,-27,-43,6,-12,41,-42,31,-36,-34,1,-45,8,-19,8,-30,31,-34,20,28,-4,-1,-21,36,-7,-37,15,-5,20,-38,-32,-25,-36,-39,-46,0,-48,-39,-46,32,-28,-38,28,10,-22,40,-22,-44,-28,45,-38,26,-6,-35,39,-8,0,-3,37,18,30,16,-40,-22,-41,-48,-3,48,-50,-43,42,48,2,-39,35,-8,-20,24,-32,-33,12,-50,8,-27,31,-47,-29,9,-21,11,22,36,31,1,-38,-49,-10,-18,-34,39,18,5,37,44,5,46,-37,18,20,0,-46,-19,-39,42,-23,-16,40,4,35,-28,-18,-29,36,17,-26,-50,7,47,-34,25,20,-33,-44,-30,35,-10,35,36,-27,49,36,-47,-11,-22,-23,-46,23,-14,10,36,41,-46,-7,-19,14,-42,3,-11,13,21,-49,-29,-49,18,-41,27,34,11,40,-13,-50,-22,9,14,16,-38,18,-31,35,32,26,36,-30,23,26,26,-26,30,-46,-29,14,-46,28,16,47,-44,22,15,-47,16,45,-13,-46,19,44,36,38,-49,-18,25,33,45,-20,19,34,29,43,-32,-37,4,8,27,-37,14,16,35,32,-32,-14,-11,32,2,-16,6,43,-50,41,-48,-35,43,46,-47,-34,-40,-50,39,37,38,0,7,43,32,7,30,0,18,-22,-35,13,16,-43,-27,13,23,-36,43,38,-14,-14,40,34,-46,-30,31,-49,-21,-7,41,36,-7,6,36,35,31,36,16,-22,-23,4,28,22,-6,-41,40,-11,17,35,12,41,0,-24,13,48,19,22,-7,25,14,-9,-9,-45,19,4,-42,16,21,-35,-6,-44,43,-28,45,-7,-30,49,-14,-25,39,0,47,-24,1,-8,-38,-24,-18,-28,-4,-29,-5,-26,-29,-49,-13,24,-17,-28,1,42,-16,-38,-32,-47,6,-36,13,3,-11,-26,13,49,40,-39,13,-41,44,31,15,-48,10,-9,-31,19,36,12,6,-14,-27,-27,26,-10,-22,-28,23,-11,33,30,-13,24,19,-21,-35,13,20,8,-45,43,-8,14,-5,27,-46,3,-13,-11,-50,21,-15,36,-26,17,-38,-29,-44,29,5,-40,-33,19,-26,31,-39,35,28,20,40,-15,-3,-47,-30,-22,2,20,3,49,41,-22,36,5,27,-1,49,-43,15,-27,33,-16,-31,-6,-48,-34,-22,9,17,45,-49,-10,32,39,33,-4,-18,44,-8,43,-31,-43,-4,30,3,-48,-48,-24,27,-30,9,-12,36,-26,16,-27,-42,27,-17,41,-17,-39,-41,2,18,-49,49,-46,-23,31,-40,-12,-22,-35,24,30,-14,-38,36,-33,14,9,9,10,15,5,11,34,22,-43,15,-40,-15,14,26,-15,-45,-39,7,-14,1,-31,18,28,-5,20,-46,15,-16,-25,-31,-17,-8,29,-25,-30,-14,19,-9,36,4,37,24,40,-45,-39,-22,-46,37,33,-26,21,-5,-29,10,-36,22,25,38,45,24,-31,39,-43,33,-38,48,-8,-23,-31,-5,33,3,-34,-17,-32,-24,-43,34,23,-20,-27,-30,-47,8,17,-27,-45,26,32,19,-48,-18,45,16,-41,-6,7,-25,-16,-25,-15,42,-14,42,11,-25,-15,-27,-33,-46,48,42,-43,-42,6,-14,3,13,-34,30,12,-31,19,40,-15,-4,32,27,36,-37,-46,46,6,6,-13,24,-9,42,1,43,5,42,-42,-14,-12,-35,-38,-30,44,8,33,0,26,30,-19,-27,-23,-13,-12,-25,-4,4,-32,41,24,40,-46,-17,-11,45,-14,-17,-7,28,5,-15,17,-11,46,-8,-24,42,9,27,-24,7,0,-42,18,-41,-1,-28,-27,-44,14,45,48,-32,37,-29,-17,-43,-6,24,-27,-24,-42,4,-19,5,-33,23,-15,-18,-7,2,-9,-19,34,-22,17,35,-16,-20,-48,30,21,-29,34,14,-34,-6,15,15,26,-12,-31,23,28,2,19,9,-46,-26,0,-28,46,24,-7,40,25,13,-1,17,-13,32,-25,4,-35,-26,2,37,-19,21,-31,0,-24,42,-1,-49,46,-28,7,-40,20,2,-38,41,33,22,-33,32,-40,11,39,-43,24,-43,-26,-15,-31,-9,-4,-3,42,33,38,9,-1,-9,-3,16,-8,-27,29,33,-34,22,-43,-18,48,-45,18,-6,14,33,21,-19,9,9,-2,-9,38,-15,-8,6,38,-23,-40,-38,-28,38,-25,-10,14,-31,38,-27,-26,-19,-1,38,34,-2,11,10,20,-4,13,-38,19,-13,45,43,33,-41,-4,34,-8,22,42,-4,-2,-6,-15,45,-9,-1,34,-48,-16,-2,0,-15,41,-26,6,-37,23,-6,29,-27,-4,35,10,-40,-27,27,4,47,3,23,-36,-22,48,11,-46,0,-13,0,-39,-8,22,8,2,23,-43,-49,-44,-8,-11,-35,44,-34,46,28,-45,28,-15,37,-26,-26,-10,37,-6,28,-5,-8,15,-48,41,-30,-36,31,-28,-27,-22,13,-17,-8,40,25,-11,24,0,-45,46,38,-43,-37,0,6,38,22,-36,-48,-28,-30,-43,11,-19,-46,-10,33,-22,4,-47,-48,-24,5,-10,-34,38,-32,37,1,-30,27,28,22,-12,30,-8,-49,-32,-46,43,-16,-40,10,-24,-14,19,28,25,12,45,-44,-50,42,-21,15,25,-38,8,1,10,46,-8,-17,-28,22,28,4,-21,-14,-25,42,-21,-10,17,10,23,47,-11,-45,45,7,27,-1,11,-6,-39,13,-18,9,38,23,12,10,18,-38,-10,-14,2,0,11,-12,-27,35,39,-34,11,32,-45,9,-32,47,-13,38,42,-18,49,-16,-12,37,-29,49,-2,-16,-46,41,-22,8,-18,-47,36,1,-33,1,-31,39,-42,26,-2,-14,33,-35,-5,40,-15,-43,-41,11,-33,-11,19,-34,-9,-7,-23,-2,33,6,-12,16,26,39,-42,10,-23,-26,-18,7,14,-10,-30,14,18,15,-20,-36,18,-45,-31,35,-14,2,37,-37,-40,3,30,-6,-48,-37,-46,-26,-20,23,-30,-15,40,27,5,-40,-30,18,-28,49,24,-44,26,2,-23,11,-11,28,29,-33,19,-45,-43,-27,23,-21,26,5,-18,34,-28,-10,8,35,-35,-5,-37,-26,39,-12,-34,-22,28,-12,25,26,42,28,47,26,-4,-29,-36,-37,-37,5,-9,-6,-26,46,-50,46,-14,49,-17,13,44,26,6,-7,-25,10,-39,-12,-10,1,22,4,-34,-7,26,-46,-38,-16,9,22,25,13,-45,-31,-15,-29,41,19,-32,42,14,10,-23,25,-39,-43,6,12,23,-19,-40,43,-11,-42,28,-11,-11,-2,9,-12,-13,6,10,5,1,-1,-21,-42,12,9,-18,48,-10,1,-31,-17,1,-23,-27,-13,37,30,39,-13,28,38,37,46,48,-49,-44,-4,-47,-5,-12,36,-49,37,-44,43,33,-30,-7,-33,-8,49,44,-3,-47,-21,46,-48,-35,6,-33,38,14,31,3,-30,37,0,-2,-24,-45,39,-48,-47,40,33,-20,-44,-9,32,38,-2,33,-2,0,-15,-10,-10,37,-40,36,-49,-50,36,-25,16,13,-49,-34,-23,-17,15,-50,-14,-6,-37,-31,-41,-8,-16,-50,-39,39,-47,-40,46,25,24,41,45,-8,6,-18,26,-9,3,23,-45,26,-44,31,-24,20,35,32,-43,22,6,-4,-31,-14,36,-11,-8,-3,-26,13,-16,-44,-28,0,-6,-31,-16,-23,-19,-4,-31,-24,34,2,-5,19,42,26,-12,24,-38,-11,-45,-34,21,-16,-32,48,-37,-1,12,35,-32,-50,12,46,-41,-10,-28,-33,-41,41,-10,11,18,-9,-13,-23,-5,39,-3,27,-11,21,-3,2,-18,10,-1,44,-17,29,34,43,-5,7,0,-27,7,7,-25,12,39,2,-31,2,6,36,20,31,-3,43,-1,41,9,-49,-44,-40,-29,10,-25,30,-10,-17,30,-37,-8,-24,-3,46,7,-25,-20,32,15,21,38,47,-26,17,-49,29,-13,37,-36,13,7,-3,10,7,47,30,-23,26,-14,-25,-21,9,-43,-35,-26,-41,37,6,46,9,-28,34,-4,30,-40,-12,-21,44,5,37,-7,28,-10,21,-16,-28,26,43,-34,-4,-42,-18,-7,-10,30,-8,45,-2,-16,-47,1,30,46,-19,36,-19,14,47,-40,37,44,49,-4,-9,-43,37,-2,29,-19,5,-19,-33,-5,31,-46,-8,-13,-35,42,-32,-36,13,11,8,-6,-45,32,-40,-30,25,43,18,-37,-39,41,-26,-38,49,40,49,-28,24,21,45,16,35,-6,-41,27,29,-11,-39,36,24,32,-5,-18,47,2,16,2,-14,-37,39,9,-10,17,49,12,-2,24,-20,10,-13,-12,44,-17,-36,-14,0,-40,0,-19,20,14,27,37,-42,45,-3,39,17,36,4,38,19,-1,22,-23,43,41,7,-5,-22,43,-2,9,-18,-4,1,-38,-8,9,19,27,14,-7,34,24,-17,-34,-13,36,12,49,-13,-15,23,48,-10,-3,47,-44,41,23,-4,-47,-43,47,48,35,-31,38,46,-35,-27,14,-40,-31,-22,47,-40,36,-44,-49,-22,15,38,5,-8,-21,-18,25,10,15,-10,-45,35,21,-50,17,-17,-29,13,43,-25,47,-20,46,-19,30,-49,26,17,21,-11,46,-7,-30,44,20,46,0,16,19,-24,10,-23,-31,38,-11,1,-29,-46,33,-35,-38,45,32,26,-6,-27,-36,33,44,-42,-27,-17,-19,-43,26,-8,37,-36,-15,0,-5,-36,49,-41,-35,49,5,-28,-16,17,23,-17,-46,-27,-17,36,24,-44,-32,-13,46,-39,-39,36,-29,45,39,-47,25,-18,-20,41,-21,32,34,35,36,-44,-2,47,9,24,-12,26,-26,-44,38,-42,0,-13,40,-12,-14,39,29,25,46,-27,38,-20,48,48,-8,0,30,-22,3,42,45,-10,-34,-11,-5,47,-33,-3,48,-10,7,47,15,-47,26,-38,0,10,-9,9,46,-2,47,14,40,12,-8,-39,-7,-10,17,25,12,-19,-42,-32,36,-15,40,13,32,-19,45,14,31,0,-40,-17,-38,16,-6,38,-38,-50,2,31,-33,3,-47,38,35,31,-20,-34,41,-39,14,41,-32,1,23,47,46,-47,13,-33,6,-11,-25,34,-3,25,21,-44,23,-36,45,16,14,27,-20,2,-19,-26,-26,37,-11,-45,24,39,-24,42,44,14,-7,46,-27,44,15,-7,-32,-20,1,-12,43,9,44,19,20,25,13,40,-2,-46,-32,30,-44,38,-26,33,-45,31,-9,43,-23,34,-7,17,-28,17,-34,6,-20,-18,-46,47,21,-37,23,42,-36,-8,-1,-42,-48,-24,2,2,-36,-24,17,-26,-20,-25,3,32,19,23,-21,-32,-19,-18,4,-26,7,-19,-17,-33,32,-48,-35,7,-28,32,21,-6,-7,44,-49,39,-25,-49,14,0,-23,-2,-5,12,-26,-8,6,-7,16,25,-41,35,-25,-22,28,26,-36,19,-11,-24,47,12,5,34,-22,19,19,-48,-14,-28,19,-29,25,-43,-23,-38,2,-28,-1,-25,14,0,9,1,47,-10,11,25,-29,-25,-28,9,18,27,-50,-42,22,34,31,-7,20,-47,25,-4,26,-6,38,-44,-36,-1,-27,-46,42,-5,-25,6,0,-20,-45,-19,-15,-38,42,11,49,16,43,33,23,26,-25,28,-30,32,21,32,-36,-45,48,48,-18,18,47,-11,-7,-46,9,-26,-26,13,-17,-49,32,39,36,-25,26,-11,-46,-19,31,-35,-39,13,-9,-9,39,40,-18,7,46,-43,-18,-44,-13,-37,36,29,-47,-17,46,43,-16,7,11,41,10,-18,-21,28,19,33,20,6,-8,44,-47,27,-23,43,-33,24,-40,-42,15,37,41,-36,36,22,1,47,15,-20,30,49,24,-41,10,-23,41,-49,49,31,-28,-48,-3,32,-30,46,18,-22,-49,34,-12,37,-34,-22,-23,26,-47,42,-32,-48,0,-10,42,3,8,26,25,-10,-24,-14,6,-36,-40,30,47,-20,16,-36,30,10,29,-14,34,0,-19,-35,38,7,-15,-24,44,10,8,-45,42,21,-28,-26,44,-3,-2,6,-42,-9,12,-5,-38,-5,-50,-37,-50,-9,19,-28,24,-24,-1,-25,-42,29,27,19,-31,-22,-50,-39,32,-17,-3,-18,-27,28,48,-23,26,22,38,-47,-47,38,49,6,4,-37,0,-12,44,23,33,-17,-41,7,33,-47,-18,-37,47,-18,15,15,29,-31,37,1,-23,-29,19,-10,-26,-30,-6,-31,49,27,44,4,-11,34,-34,29,-15,-28,-30,-37,2,-10,43,-18,33,1,41,-26,40,5,-12,-24,-2,-14,-42,44,-11,-39,16,15,-28,43,35,-33,25,-6,3,-2,2,-33,-49,38,-18,11,36,41,-13,-33,-50,47,-13,1,-24,-34,-42,-18,4,-32,15,35,-4,-7,-45,13,35,-24,-9,-22,-45,12,42,24,6,-7,13,7,-5,10,39,47,-8,-19,26,-27,10,-13,37,44,-27,-14,-30,-19,0,-42,-14,1,-34,3,-13,-7,-3,29,-38,-6,-25,-6,21,-17,-13,15,-33,-17,-6,-34,-32,30,43,-25,-29,-30,-45,34,32,41,-43,-28,17,-46,-36,36,29,-40,-7,14,40,-21,-23,-7,41,-15,3,-37,34,-1,20,39,-17,-36,29,-1,-2,-31,-13,-33,-30,-46,-26,-29,12,36,41,35,19,-21,-4,-19,-22,-34,39,-22,22,-6,19,48,-41,3,-44,24,19,-36,-22,39,22,22,-33,5,31,14,-29,24,12,-8,-18,-4,26,37,-42,29,-2,36,31,-3,33,27,-46,-21,17,-19,11,23,25,-17,43,35,-42,-44,7,-25,-33,49,-24,13,4,-9,23,-46,-31,44,33,29,-32,-1,-16,19,-13,37,-41,-39,6,-38,-43,48,29,24,4,-8,41,-1,44,16,-48,32,2,42,-7,31,-37,-12,29,11,13,-33,14,-38,-34,-11,-48,26,-14,-48,-37,-27,20,41,-13,-39,29,-37,-6,-34,47,11,24,-23,28,23,10,31,-25,40,-47,-6,-41,20,-4,32,-1,-24,-47,13,-42,43,-22,14,18,-25,24,35,12,7,36,48,-11,-43,-15,37,18,49,-2,-48,19,28,-44,24,32,-5,-38,10,0,-24,36,23,-46,32,-24,35,-11,31,-1,-20,-35,33,-3,46,-29,15,22,-35,-30,35,-48,-24,-24,-19,-12,12,47,-40,1,-30,5,-33,2,-37,-35,31,-8,5,25,29,-24,-37,25,-10,-19,-8,12,47,-19,2,22,38,-30,-30,29,-37,-40,-5,-4,-26,-21,27,17,-4,32,-45,25,21,14,16,7,-44,-44,49,-47,-17,-26,-44,-24,-19,29,-4,32,23,-5,-40,19,-1,42,-14,-39,5,27,-37,30,-17,1,4,-35,-16,-40,6,-32,-28,-48,38,47,42,15,-28,-25,-33,22,-28,-29,30,31,1,46,-47,34,-41,-8,5,-12,-43,-25,3,0,-8,-42,-47,-32,14,26,-16,-42,8,35,10,-26,-34,-9,31,15,-25,-35,-31,-35,-27,-16,-50,-43,-18,8,43,1,42,29,-26,-12,-41,-27,22,-15,-25,-34,-22,35,-50,-16,47,2,-2,31,-13,-36,46,7,-17,-24,26,4,41,27,-42,35,40,9,-47,25,20,-16,-43,-34,-28,-47,-35,8,22,-12,45,33,45,35,5,11,12,-36,-1,10,25,-38,-29,-11,39,-5,-45,45,-18,-43,9,-3,-7,-26,-12,-11,8,-37,2,33,-15};
	//vector<int> A = {3,-1,-5,-9};
	cout << numberOfArithmeticSlices(A) << endl;
	return 0;
}