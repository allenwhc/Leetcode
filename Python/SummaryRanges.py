
class Solution(object):
	def summaryRanges(self, nums):
		if not nums: return []
		r = [(n-i,n) for i,n in enumerate(nums)]	# Check elements with same base indices
		lower,upper = dict(r[::-1]),dict(r)	# Divide range into lower and upper bound
		return [str(val) + ('->' + str(upper[key]))*(val<upper[key]) for key,val in sorted(lower.items())]

nums = [0,1,2,4,5,7,8,9]
print Solution().summaryRanges(nums)