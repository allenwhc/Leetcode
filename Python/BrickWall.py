import itertools
class Solution(object):
	def leastBricks(self, wall):
		"""
		:type wall: List[List[int]]
		:rtype: int
		"""
		n = len(wall)
		d = {}
		for layer in wall:
			accu = 0
			for i in range(len(layer) - 1):
				accu += layer[i]
				if accu in d: d[accu] += 1
				else: d[accu] = 1
		return n - max(d.values()) if len(d) else n

#wall = [[1,1,1,2,1],[1,2,2,1],[3,1,2],[1,1,1,1,1,1],[1,3,2],[6],[2,4],[3,1,2],[1,3,1,1]]
wall = [[1]]
print Solution().leastBricks(wall)
