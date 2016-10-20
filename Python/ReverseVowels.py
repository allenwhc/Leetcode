class Solution(object):
	def reverseVowels(self,s):
		if s is None: return ''
		vowels = ['a','A','e','E','i','I','o','O','u','U']
		i,j,s = 0,len(s)-1,list(s)
		while i<j:
			if s[i] not in vowels:
				i+=1
			elif s[j] not in vowels:
				j-=1
			else:
				s[i],s[j] = s[j],s[i]
				i+=1
				j-=1
		return ''.join(s)

s = 'aA'
print Solution().reverseVowels(s)