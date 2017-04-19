class Solution(object):
	def nextGreaterElements(self, nums):
		"""
		:type nums: List[int]
		:rtype: List[int]
		"""
		if not nums: return []
		stack,res = [i for i in range(len(nums)-1, -1, -1)],[-1]*len(nums)
		for i in range(len(nums)-1,-1,-1):
			curr = nums[i]
			if stack: 
				index = stack.pop()
				#print i, curr
				while curr >= nums[index]:
					print index
					if not stack: break
					index = stack.pop()
				if nums[i] < nums[index]:
					res[i] = nums[index]
					stack.append(index)
			stack.append(i)
		return res
nums = [1,3,2,4,5,1,6,2]
print Solution().nextGreaterElements(nums)