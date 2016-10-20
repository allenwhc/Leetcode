class Solution(object):
	def numWays(self, n, k):
		if n<=0 or (k==1 and n>=3):
			return 0
		total = k
		diff = last = 0
		for _ in range(2,n+1):
			temp = total	#save previous total ways
			total *= k	#total ways if no constraints
			total -= last - diff #constraint is 
			diff = last - diff	#update difference
			last = temp	#update number of ways of last post
		return total

print Solution().numWays(6,3)