from collections import defaultdict

class Solution(object):
	def wordBreak(self, s, wordDict):
		d = {len(s):['']}
		def parse(i):
			if i not in d:
				d[i] = [s[i:j] + (word and ' ' + word)
						for j in range(i+1, len(s)+1)
						if s[i:j] in wordDict
						for word in parse(j)]
			return d[i]
		return parse(0)

s = 'catsanddog'
wordDict = set(["cat", "cats", "and", "sand", "dog"])
print Solution().wordBreak(s,wordDict)