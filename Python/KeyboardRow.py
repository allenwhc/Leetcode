class Solution(object):
	def findWords(self, words):
		"""
		:type words: List[str]
		:rtype: List[str]
		"""
		#r_1,r_2,r_3 = ['q','w','e','r','t','y','u','i','o','p'],['a','s','d','f','g','h','j','k','l'],['z','x','c','v','b','n','m']
		r_1,r_2,r_3 = "qwertyuiop","asdfghjkl","zxcvbnm"
		res = []
		for w in words:
			first_letter = w[0]
			if first_letter.lower() in r_1 and all(l.lower() in r_1 for l in w) or \
			first_letter.lower() in r_2 and all(l.lower() in r_2 for l in w) or \
			first_letter.lower() in r_3 and all(l.lower() in r_3 for l in w):
				res.append(w)
		return res

words = ["Hello", "Alaska", "Dad", "Peace"]
print Solution().findWords(words)