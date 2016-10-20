class Solution(object):
	def validWordSquare(self, words):
		return map(None, *words) == map(None, *map(None, *words))

words = ["abcd","bnrt","crm","dt"]
print Solution().validWordSquare(words)