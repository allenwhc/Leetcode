from collections import defaultdict
class Solution(object):
	def alienOrder(self, words):
		pred,succ = defaultdict(set),defaultdict(set)
		for pair in zip(words, words[1:]):
			for x,y in zip(*pair):
				if x != y:
					pred[y].add(x)
					succ[x].add(y)
		letters = set(''.join(words))
		done = letters - set(pred)
		res = ''
		while done:
			u = done.pop()
			res += u
			for v in succ[u]:
				pred[v].discard(u)	# remove u from predecessor list
				if not pred[v]:
					done.add(v)
		return res if set(res) == letters else ''


words = ["wrt","wrf","er","ett","rftt"]
print Solution().alienOrder(words)