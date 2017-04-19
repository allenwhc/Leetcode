
class Solution(object):
	def findAnagrams(self, s, p):
		m,n,count_s,count_p,res = len(s),len(p),[0 for _ in range(26)],[0 for _ in range(26)],[]
		if m < n or m == 0: return res
		for i in range(n):
			count_s[ord(s[i]) - ord('a')] += 1
			count_p[ord(p[i]) - ord('a')] += 1
		for i in range(n,m):
			if not cmp(count_s, count_p):
				res.append(i - n)
			count_s[ord(s[i]) - ord('a')] += 1	# Add current character into count_s
			count_s[ord(s[i-n]) - ord('a')] -= 1 # Remove first character in last matching anagram
		if not cmp(count_s, count_p):
			res.append(m - n)
		return res
s = "cbaebabacd"
p = "abc"
print Solution().findAnagrams(s,p)