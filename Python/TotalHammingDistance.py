class Solution(object):
	def totalHammingDistance(self, nums):
		"""
		:type nums: List[int]
		:rtype: int
		"""
		s = ['{0:030b}'.format(n) for n in nums]
		t = map(list,s)
		print t
		print map(list,zip(*t))

nums = [4,14,2]
print Solution().totalHammingDistance(nums)