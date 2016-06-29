class Solution(object):
	def isPerfectSquare(self, num):
		"""
		:type num: int
		:rtype: bool
		"""
		if not num or num == 1: return True
		low, high = 0, num/2
		while low <= high:
			mid = (low + high) / 2
			square = mid * mid
			if square == num: return True
			elif square > num: high = mid - 1
			else: low = mid + 1
		return False
		