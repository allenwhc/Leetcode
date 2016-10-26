class Solution(object):
	def wordBreak(self, s, wordDict):
		sz = len(s)
		dp = [False for _ in range(sz)]
		for i in range(sz):
			for word in wordDict:
				if not cmp(word,s[i-len(word)+1:i+1]) and (i==len(word)-1 or dp[i-len(word)]):
					dp[i] = True
		return dp[-1]

s = 'leetcodeleet'
wordDict = set(['leet','code'])
print Solution().wordBreak(s,wordDict)