import itertools
class Solution(object):
	class UnionFind():
		def __init__(self, n):
			self.id = [i for i in range(n*n)]
			self.sz = [1 for _ in range(n*n)]
			self.count = n

		def find(self, P):
			while self.id[P] != P:
				P = self.id[P]
			return P

		def union(self, P, Q):
			P = self.find(P)
			Q = self.find(Q)
			if P == Q: return
			if self.sz[P] < self.sz[Q]:
				self.id[P] = self.id[Q]
				self.sz[Q] += self.sz[P]
			else:
				self.id[Q] = self.id[P]
				self.sz[P] += self.sz[Q]
			self.count -= 1
			return

	def findCircleNum(self, M):
		"""
		:type M: List[List[int]]
		:rtype: int
		"""
		if not len(M) or not len(M[0]): return 0
		n,res,cycles = len(M),0,set()
		uf = self.UnionFind(n)
		for i,j in itertools.product(range(n),(range(n))):
			if M[i][j] == 1 and i < j:
				uf.union(i,j)
		return uf.count

M = [[1,1,0,0,0,0,0,1,0,0,0,0,0,0,0],[1,1,0,0,0,0,0,0,0,0,0,0,0,0,0],[0,0,1,0,0,0,0,0,0,0,0,0,0,0,0],[0,0,0,1,0,1,1,0,0,0,0,0,0,0,0],[0,0,0,0,1,0,0,0,0,1,1,0,0,0,0],[0,0,0,1,0,1,0,0,0,0,1,0,0,0,0],[0,0,0,1,0,0,1,0,1,0,0,0,0,1,0],[1,0,0,0,0,0,0,1,1,0,0,0,0,0,0],[0,0,0,0,0,0,1,1,1,0,0,0,0,1,0],[0,0,0,0,1,0,0,0,0,1,0,1,0,0,1],[0,0,0,0,1,1,0,0,0,0,1,1,0,0,0],[0,0,0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,1,0,1,0,0,0,0,1,0],[0,0,0,0,0,0,0,0,0,1,0,0,0,0,1]]
print Solution().findCircleNum(M)

