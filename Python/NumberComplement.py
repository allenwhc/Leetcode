class Solution(object):
	def findComplement(self, num):
		"""
		:type num: int
		:rtype: int
		"""
		return int(bin((1<<(len(bin(num))-2))-1),2) ^ num

num = 100
print Solution().findComplement(num)