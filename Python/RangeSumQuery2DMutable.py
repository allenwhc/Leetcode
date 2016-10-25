import itertools
class NumMatrix(object):
	def __init__(self, matrix):
		if not len(matrix) or not len(matrix[0]): return
		self.m,self.n = len(matrix),len(matrix[0])
		self.matrix = [[0 for _ in range(self.n)]] * self.m
		self.binary_index_tree = [[0 for _ in range(self.n+1)]] * (self.m+1)
		for row,col in itertools.product(range(self.m), range(self.n)):
			print row,col,matrix[row][col]
			self.update(row, col, matrix[row][col])
			self.matrix[row][col] = matrix[row][col]
		#print self.binary_index_tree

	def update(self, row, col, val):
		diff = val - self.matrix[row][col]
		self.matrix[row][col] = val
		row+=1
		col+=1
		while row <= self.m:
			j = col
			while j <= self.n:
				self.binary_index_tree[row][j] += diff
				j += (j & -j)
			row += (row & -row)
		#print self.binary_index_tree

		#print self.binary_index_tree	

	def sumRegion(self, row1, col1, row2, col2):
		#print 'i=',row1,',j=',col1
		A = self.sumIndex(row1-1, col1-1)
		#print 'A=',A
		#print 'i=',row1-1,',j=',col2
		B = self.sumIndex(row1-1, col2)
		#print 'B=',B
		#print 'i=',row2,',j=',col1-1
		C = self.sumIndex(row2, col1-1)
		#print 'C=',C
		#print 'i=',row2,',j=',col2
		D = self.sumIndex(row2, col2)
		#print 'D=',D
		return D - B - C + A

	def sumIndex(self, row, col):
		res = 0
		row+=1
		col+=1
		while row>0:
			j = col
			while j>0:
				res += self.binary_index_tree[row][j]
				j -= (j & -j)
			row -= (row & -row)
		return res

matrix = [[3, 0, 1, 4, 2],[5, 6, 3, 2, 1],[1, 2, 0, 1, 5],[4, 1, 0, 1, 7],[1, 0, 3, 0, 5]]
numMatrix = NumMatrix(matrix)
print numMatrix.sumRegion(2,1,4,3)
numMatrix.update(3,2,2)
print numMatrix.sumRegion(2,1,4,3)