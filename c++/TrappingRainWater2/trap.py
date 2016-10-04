
def bfs(heightMap,i,j,m,n,visited):
	if i<0 or i>=m or j<0 or j>=n: return
	if not visited[i][j]:
		visited[i][j] = True
		if 

def trapRainWater(heightMap):
	if not len(heightMap) or not len(heightMap[0]): return 0
	return

if __name__ == '__main__':
	heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
	print trapRainWater(heightMap)