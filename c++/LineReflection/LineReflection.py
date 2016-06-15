def isReflected(points):
	points.sort()
	return points == sorted([points[0][0]+points[-1][0] -x, y] for x,y in points)

if __name__ == '__main__':
	points = [[0,0],[0,-1]]
	print isReflected(points)