import itertools
class Solution(object):
	def gameOfLife(self, board):
		"""
			Two states: live(1), dead(0)
			Use binary representations:
				next <- present
				1. dead <- dead: 00
				2. dead <- live: 01
				3. live <- dead: 10
				4. live <- live: 11
				From present to next: board[i][j] & 1	(clear leftmost bit)
				from next to present: board[i][j] >> 1 (left shift 1)
		"""
		if not len(board) or not len(board[0]): return
		m,n = len(board),len(board[0])
		def countLiveNeighbors(i,j):
			res = 0
			for I,J in ((i-1,j),(i+1,j),(i,j-1),(i,j+1),(i-1,j-1),(i-1,j+1),(i+1,j-1),(i+1,j+1)):
				if 0<=I<m and 0<=J<n:
					res += board[I][J] & 1
			return res

		for i,j in itertools.product(range(m),range(n)):
			num_live_neighbors = countLiveNeighbors(i,j)
			if board[i][j] == 1 and 2<=num_live_neighbors<=3:
				board[i][j] = 3 # State 4, live cells stay alive
			if board[i][j] == 0 and num_live_neighbors == 3:
				board[i][j] = 2 # State 3, dead cells become alive
			#State 1 & 2 don't need any changes

		for i,j in itertools.product(range(m),range(n)):
			board[i][j] >>= 1

board = [[0,0,0,0,0],[0,0,1,0,0],[0,0,1,0,0],[0,0,1,0,0],[0,0,0,0,0]]
for b in board:
	print b
Solution().gameOfLife(board)
print
for b in board:
	print b

