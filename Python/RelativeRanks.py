class Solution(object):
	def findRelativeRanks(self, nums):
		"""
		:type nums: List[int]
		:rtype: List[str]
		"""
		sort_nums,d = sorted(nums, reverse=True),{0:"Gold Medal",1:"Silver Medal",2:"Bronze Medal"}
		order = [sort_nums.index(x) for x in nums]
		return [d[x] if x in d else str(x+1) for x in order]

nums = [10,3,8,9,4]
print Solution().findRelativeRanks(nums)