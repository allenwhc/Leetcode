class Solution(object):
	def findTheDifference(self, s, t):
		if not s: return t
		xor = ord(s[0])
		for i in range(1,len(s)): 
			xor ^= ord(s[i])
		for c in t:
			xor ^= ord(c)
		return chr(xor)

s = 'abcd'
t = 'abcde'
print Solution().findTheDifference(s,t)