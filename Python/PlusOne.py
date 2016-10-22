class Solution(object):
	def plusOne(self, digits):
		if len(digits) == 0: return []
		if digits[-1] != 9:
			return digits[:-1]+[digits[-1]+1]
		elif all(x==9 for x in digits):
			return [1]+[0]*len(digits)
		else:
			i = len(digits) - 1
			while digits[i]==9:
				i-=1
			return digits[:i]+[digits[i]+1]+[0]*(len(digits)-i-1)
digits = [1,9,9,9,9]
print Solution().plusOne(digits)