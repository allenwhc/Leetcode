class Solution(object):
	def longestConsecutive(self, nums):
		if not len(nums): return 0
		n = len(nums)
		# Hash solution
		s = set([x for x in nums])
		res = 0
		for i in range(n):
			if nums[i]-1 not in s:	#this is a start of sequence
				j = nums[i]
				while j in s: j+=1
				res = max(res, j-nums[i])


		# id = [i for i in range(n)]	
		# sz = [1 for _ in range(n)]
		# def find(p):
		# 	while p!= id[p]:
		# 		p = id[p]
		# 	return p
		# def union(p,q):
		# 	p = find(p)
		# 	q = find(q)
		# 	if p == q: return
		# 	if sz[p] < sz[q]:
		# 		id[p] = id[q]
		# 		sz[q] += sz[p]
		# 	else:
		# 		id[q] = id[p]
		# 		sz[p] += sz[q]
		# 	return
		# for n in nums:
		# 	if (n+1) in nums:
		# 		union(n,n+1)
		# 	elif (n-1) in nums:
		# 		union(n,n-1)
		return res

nums = [100, 4, 200, 1, 3, 2]
print Solution().longestConsecutive(nums)