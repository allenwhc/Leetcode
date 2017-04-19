class Solution(object):
	def nextGreaterElement(self, findNums, nums):
		"""
		:type findNums: List[int]
		:type nums: List[int]
		:rtype: List[int]
		"""
		stack,d = [nums[0]],{}
		for i in range(1, len(nums)):
			next_greater = nums[i]
			if stack:
				prev = stack.pop()
				while next_greater > prev:
					d[prev] = next_greater
					if not stack: break
					prev = stack.pop()
				if prev > next_greater:
					stack.append(prev)
			stack.append(next_greater)
		while stack:
			d[stack.pop()] = -1
		return [d[x] for x in findNums]

findNums = [2,4]
nums = [1,3,2,4]
print Solution().nextGreaterElement(findNums,nums)