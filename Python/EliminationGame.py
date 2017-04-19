class Solution(object):
	def lastRemaining(self, n):
		"""
		:type n: int
		:rtype: int
		"""
		def divideToHalves(n, isLeftToRight):
			if n <= 1: return 1
			return 2*divideToHalves(n/2, False) if isLeftToRight else 2*divideToHalves(n/2,True)-1+n%2
		return divideToHalves(n, True)

n = 35
print Solution().lastRemaining(n)