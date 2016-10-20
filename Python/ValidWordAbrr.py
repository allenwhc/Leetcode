import itertools
class Solution(object):
	def validWordAbbreviation(self, word, abbr):
		m,n,i,j = len(word),len(abbr),0,0
		if m==0: return n==0
		while i<m and j<n:
			if word[i] == abbr[j]:
				i+=1
				j+=1
				continue
			length = 0
			if j<n and abbr[j] == '0': 
				return False
			while j<n and abbr[j].isdigit():
				length = length*10 + int(abbr[j])
				j+=1
			i+=length
			if i<m and j<n and word[i] != abbr[j]:
				return False
		return i==m and j==n

s = 'internationalization'

abbr = 'i5a11o1'
print Solution().validWordAbbreviation(s,abbr)