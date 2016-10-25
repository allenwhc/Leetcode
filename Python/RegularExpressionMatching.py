import itertools
class Solution(object):
	def isMatch(self, s, p):
		m,n=len(s),len(p)
		dp = [[False for _ in range(n+1)] for _ in range(m+1)]
		dp[0][0] = True
		for j in range(1, n+1):
			if p[j-1] == '*':
				dp[0][j] = dp[0][j-2]
		
		for i,j in itertools.product(range(1,m+1),range(1,n+1)):
			if s[i-1] == p[j-1] or p[j-1] == '.':
				dp[i][j] = dp[i-1][j-1]
			elif p[j-1] == '*':
				dp[i][j] = dp[i][j-2]
				if p[j-2] == '.' or p[j-2] == s[i-1]:
					dp[i][j] = dp[i][j] or dp[i-1][j-1]
			print dp
		return dp[-1][-1]

s = "aaa"
p = "ab*a"
print Solution().isMatch(s,p)
