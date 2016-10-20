class Solution(object):
	def isPowerOfTwo(self,n):
		if n<=0: return False
		return bin(n)[2:].count('1')==1

nums = [190,128,75,98,64,28,512,1035]
for n in nums:
	print Solution().isPowerOfTwo(n), 
