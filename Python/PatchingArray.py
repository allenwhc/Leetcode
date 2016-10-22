class Solution(object):
	def minPatches(self, nums, n):
		if len(nums) == 0 or n<1: 
			return 0
		res,miss_num,i = 0,1,0
		while miss_num <= n:
			if i<len(nums) and nums[i]<=miss_num:
				miss_num += nums[i]
				i += 1
			else:
				miss_num += miss_num
				res += 1
		return res

nums = [1,5,10]
n = 20
print Solution().minPatches(nums,n)