class Solution(object):
	def isStrobogrammatic(self,num):
		if len(num) == 0: return False
		i,j = 0,len(num)-1
		while i<=j:
			if i==j: 
				return num[i]=='1' or num[i]=='0' or num[i]=='8'
			if num[i] in '23457' or num[j] in '23457':
				return False
			elif num[i] == '1' or num[i]=='0' or num[i]=='8': 
				if num[j] != num[i]: return False
			elif num[i]=='6' and num[j]!='9':
				return False
			elif num[i]=='9' and num[j]!='6':
				return False
			i+=1
			j-=1
		return True

num = '8698'
print Solution().isStrobogrammatic(num)