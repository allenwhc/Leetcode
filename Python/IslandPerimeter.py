import itertools
class Solution(object):
	def islandPerimeter(self, grid):
		"""
		:type grid: List[List[int]]
		:rtype: int
		"""
		# if not grid or not grid[0]: return 0
		# d,res,n,m = {},0,len(grid),len(grid[0])
		# for i,j in itertools.product(range(n),range(m)):
		# 	if grid[i][j] == 1:
		# 		count = 0
		# 		for I,J in ((i-1,j),(i+1,j),(i,j-1),(i,j+1)):
		# 			if 0<=I<n and 0<=J<m and grid[I][J] == 1:
		# 				count += 1
		# 		if (4 - count) not in d:
		# 			d[4 - count] = 1
		# 		else:
		# 			d[4 - count] += 1
		# return sum(x[0] * x[1] for x in d.items())

		print map(list, zip(*grid))
		print grid
		print grid + map(list, zip(*grid))

grid = [[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]
print Solution().islandPerimeter(grid)