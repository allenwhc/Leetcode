from collections import defaultdict
class ValidWordAbbr(object):
	def __init__(self,dictionary):
		self.dict = defaultdict(int)
		self.wordList = set(dictionary)
		for word in self.wordList:
			abbr = word if len(word)<=2 else (word[0] + str(len(word[1:-1]))+ word[-1])
			#print abbr
			self.dict[abbr] += 1
		#print self.dict

	def isUnique(self,word):
		m = len(word)
		abbr = word if m<=2 else (word[0] + str(len(word[1:-1])) + word[-1])
		return (word in self.wordList and self.dict[abbr]==1) or (word not in self.wordList and abbr not in self.dict)


dictionary = ['deer','door','cake','card','lnternationn','hello']
vwr = ValidWordAbbr(dictionary)
print vwr.isUnique('dear')
print vwr.isUnique('cart')
print vwr.isUnique('cane')
print vwr.isUnique('make')
print vwr.isUnique('hello')