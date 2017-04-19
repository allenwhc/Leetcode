class Solution(object):
	def updateBoard(self, board, click):
		q = [(click[0],click[-1])]
		while q:
			i,j,noMines = q[0][0],q[0][1],0
			neighbor = []
			if board[i][j] == 'M':
				board[i][j] = 'X'
			else:
				for I,J in ((i-1,j),(i-1,j-1),(i-1,j+1),(i,j),(i,j-1),(i,j+1),(i+1,j),(i+1,j-1),(i+1,j+1)):
					if 0<=I<len(board) and 0<=J<len(board[0]):
						if board[I][J] == 'M':
							noMines += 1	# if encounters a mine, increase mine's counter
						elif noMines == 0 and board[I][J] == 'E':
							neighbor.append((I,J))	# if adjacent cell is not a mine, add to list 
			print neighbor
			if noMines > 0:
				board[i][j] = str(noMines)	# mark number of mines in adjacent cells down at current cell
			else:
				for x,y in neighbor:
					board[x][y] = 'B'
					q.append((x,y))		# mark all 'innocent' adjacent cells and push to queue
			q.pop(0)
		return board

#board = [['E', 'E', 'E', 'E', 'E'],['E', 'E', 'M', 'E', 'E'],['E', 'E', 'E', 'E', 'E'],['E', 'E', 'E', 'E', 'E']]
board = [['E']]
click = [0,0]
print board
board = Solution().updateBoard(board,click)
print board