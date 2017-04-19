class Interval:
	def __init__(self, s=0, e=0):
		self.start = s
		self.end = e

class Solution:
	def eraseOverlapIntervals(self, intervals):
		if not len(intervals): return 0
		

intervals = [Interval(1,2),Interval(1,2),Interval(1,2)]
print Solution().eraseOverlapIntervals(intervals)