class Solution(object):
	def findDisappearedNumbers(self, nums):
		"""
		:type nums: List[int]
		:rtype: List[int]
		"""
		i,nums = 1,[0] + nums

		while i < len(nums):
			if nums[i] != i  and nums[i] != nums[nums[i]]:
				nums[nums[i]],nums[i] = nums[i],nums[nums[i]]
			else:
				i+=1
		return [i for i,x in enumerate(nums) if i!=x]

nums = [4,3,2,7,8,2,3,1]
print Solution().findDisappearedNumbers(nums)