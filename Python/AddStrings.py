class Solution(object):
	def addStrings(self, num1, num2):
		"""
		:type num1: str
		:type num2: str
		:rtype: str
		"""
		if not num1: return num2
		if not num2: return num1

		i,j,res,num = len(num1)-1,len(num2)-1,'',0
		while i>=0 or j>=0:
			if i>=0:
				num += int(num1[i])
				i -= 1
			if j>=0:
				num += int(num2[j])
				j -= 1
			res += str(num%10)
			num /= 10
		if num: res += str(num%10)
		return res[::-1]

num1 = '8905'
num2 = '1457'
print Solution().addStrings(num1, num2)