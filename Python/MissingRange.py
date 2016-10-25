class Solution(object):
	def findMissingRanges(self, nums, lower, upper):
		def convertToRange(lower, upper):
			if lower == upper - 1:
				return str(lower),
			else:
				return str(lower) + '->' + str(upper - 1),

		res = []
		if not nums:
			res += convertToRange(lower,upper+1) 
			return res
		if lower < nums[0]: 
			res += convertToRange(lower,nums[0])
		for i in range(0, len(nums)-1):
			if nums[i] != nums[i+1] - 1 and nums[i] != nums[i+1]:
				res += convertToRange(nums[i]+1,nums[i+1])
		if upper > nums[-1]:
			res += convertToRange(nums[-1]+1, upper+1)
		return res


nums = [1,1,1]
lower,upper = 1,1
print Solution().findMissingRanges(nums,lower,upper)