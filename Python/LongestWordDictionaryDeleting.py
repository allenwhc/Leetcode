class Solution(object):
	def findLongestWord(self, s, d):
		"""
		:type s: str
		:type d: List[str]
		:rtype: str
		"""
		d = sorted(d, key = lambda x: (-len(x), x))
		for t in d:
			it = iter(s)
			if all(c in it for c in t):
				return t
		return ''

s = "aewfafwafjlwajflwajflwafj"
d = ["apple","ewaf","awefawfwaf","awef","awefe","ewafeffewafewf"]
print Solution().findLongestWord(s,d)
