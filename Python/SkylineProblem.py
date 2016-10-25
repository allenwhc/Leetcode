import heapq,sys
class Solution(object):
	def getSkyline(self, buildings):
		if not len(buildings): return []
		heap,res = [],[]
		buildings = sorted(buildings + [[b[1],sys.maxint,0] for b in buildings])
		edges = [(0,sys.maxint)]
		for l,r,h in buildings:
			top = edges[0][0]
			while edges[0][1] <= l:
				heapq.heappop(edges)
			if h>0:
				heapq.heappush(edges,(-h,r))
			# print edges
			# print res
			if top != edges[0][0]:
				if len(res) and res[-1][0] == l:
					res[-1][-1] = -edges[0][0]
				else:
					res.append([l, -edges[0][0]])

		return res

buildings = [[0,3,3],[1,5,3],[2,4,3],[3,7,3]]
print Solution().getSkyline(buildings)