import heapq
class Interval(object):
	def __init__(self, s=0, e=0):
		self.start = s
		self.end = e
	

class Solution(object):
	# def merge(self, intervals):
	# 	intervals = sorted(intervals, key = lambda x: (x.start,x.end))
	# 	res = []
	# 	for i in range(len(intervals)):
	# 		if i==0:
	# 			res.append(intervals[i])
	# 		else:
	# 			prev_interval = res.pop()
	# 			if intervals[i].start > prev_interval.end:
	# 				res.append(prev_interval)
	# 				res.append(intervals[i])
	# 			else:
	# 				prev_interval.end = max(prev_interval.end, intervals[i].end)
	# 				res.append(prev_interval)
	# 	return res
	def merge(self,intervals):
		heap = []
		if len(intervals) == 0: return heap
		heapq.heappush(heap,intervals[0])
		for i in range(1, len(intervals)):
			prev_interval = heap.pop()
			if intervals[i].end < prev_interval.start:
				heapq.heappush(heap,prev_interval)
				heapq.heappush(heap,intervals[i])
			else:
				if intervals[i].start <= prev_interval.end:
					prev_interval.start = min(prev_interval.start, intervals[i].start)
					prev_interval.end = max(prev_interval.end, intervals[i].end)
				else:
					heapq.heappush(heap,intervals[i])
				heapq.heappush(heap,prev_interval)
		res = []
		while len(heap)>0:
			res.append(heapq.heappop(heap))
		return res

intervals = [Interval(1,4),Interval(0,0)]
for x in Solution().merge(intervals):
	print x.start, x.end