class Solution(object):
	def maxSlidingWindow(self, nums, k):
		if not nums or not k: return []
		dq,res = [],[]
		i = 0
		for i in range(k):
			while dq and nums[i]>nums[dq[-1]]:
				dq.pop()
			dq.append(i)

		for i in range(k, len(nums)):
			res.append(nums[dq[0]])
			while dq and nums[i]>nums[dq[-1]]:
				dq.pop()
			while dq and i - dq[0]>=k:
				dq.pop(0)
			dq.append(i)

		return res + [nums[dq[0]]]

nums = [1,3,-1,-3,5,3,6,7]
k = 3
print Solution().maxSlidingWindow(nums,k)