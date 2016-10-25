class Solution(object):
	def lengthOfLongestSubstringKDistinct(self, s, k):
		if not s or k>len(s): return 0
		l,r,res,num_distinct = 0,1,0,1
		d = {nums[0]:1}
		while r<len(nums):
			


s = "eceba"
k = 2
print Solution().lengthOfLongestSubstringKDistinct(s,k)