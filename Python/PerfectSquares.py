import math
class Solution(object):
	def numSquares(self, n):
		dp = [i for i in range(n+1)]
		sqrt = int(n**(1/2.0))
		for i in range(2, sqrt+1):
			for j in range(n+1):
				if j>=i*i:
					dp[j] = min(dp[j], dp[j-i*i]+1)
		return dp[-1]

n = 7217
print Solution().numSquares(n)