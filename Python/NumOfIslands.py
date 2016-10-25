import itertools
class Solution(object):
	def numIslands(self, grid):
		if not len(grid) or not len(grid[0]): return 0
		res,m,n = 0,len(grid),len(grid[0])

		# DFS solution
		# Time complexity: O(mn)
		# Extra space: O(1)
		"""def dfs(i,j):
			if i>=m or i<0 or j>=n or j<0 or grid[i][j] != '1':
				return
			grid[i][j] = '-1'
			for I,J in ((i-1,j),(i+1,j),(i,j-1),(i,j+1)):
				dfs(I,J)
		for i,j in itertools.product(range(m),range(n)):
			if grid[i][j] == '1':
				res += 1
				dfs(i,j)
		"""

		# BFS solution
		# Time complexity: O(mn)
		# Extra space: O(1)
		"""
		q = []
		def bfs(i,j):
			if len(q) == 0:
				q.append((i,j))
			while q:
				position = q.pop(0)
				x,y = position[0],position[1]
				for X,Y in ((x-1,y),(x+1,y),(x,y-1),(x,y+1)):
					if 0<=X<m and 0<=Y<n and grid[X][Y]=='1':
						grid[X][Y] = '-1'
						q.append((X,Y))
		for i,j in itertools.product(range(m),range(n)):
			if grid[i][j] == '1':
				res += 1
				bfs(i,j)
		"""

		# Union-find solution
		# Time complexity:
		# Extra space: O(N), N = m*n
		id = [i for i in range(m*n)]
		size = [1 for _ in range(m*n)]
		def find(p):
			while p!=id[p]:
				p = id[p]
			return p

		def union(p,q):
			P = find(p)
			Q = find(q)
			if P == Q: return
			if size[P] < size[Q]:
				size[Q] += size[P]
				id[P] = id[Q]
			else:
				size[P] += size[Q]
				id[Q] = id[P]
		for i,j in itertools.product(range(m),range(n)):
			if grid[i][j] == '1':
				index = i*n+j #convert 2d index to 1d
				for I,J in ((i+1,j),(i-1,j),(i,j+1),(i,j-1)):
					if 0<=I<m and 0<=J<n and grid[I][J] == '1':
						new_index = I*n+J
						union(index, new_index)
		for pos in range(m*n):
			if pos==id[pos] and grid[pos/n][pos%n] == '1':
				res+=1
		return res
#grid = [['1','1','1','1','0'],['1','1','0','1','0'],['1','1','0','0','0'],['0','0','0','0','0']]
grid = [['1','1','0','0','0'],['1','1','0','0','0'],['0','0','1','0','0'],['0','0','0','1','1']]
print Solution().numIslands(grid)