class Interval(object):
	def __init__(self, s=0, e=0):
		self.start = s
		self.end = e

class Solution(object):
	def findRightInterval(self, intervals):
		n = len(intervals)
		res = [-1 for _ in range(n)]
		def binarySearch(s,e):
			if s>=e: return
			if e - s == 1:
				if intervals[e].start >= intervals[s].end: res[s] = e
				if intervals[s].start >= intervals[e].end: res[e] = s
				return
			mid = (e - s) / 2 + s
			binarySearch(s,mid)
			binarySearch(mid+1,e)
		binarySearch(0,n-1)
		return res


intervals = [Interval(3,4),Interval(2,3),Interval(1,2)]
print Solution().findRightInterval(intervals)