class MovingAverage(object):

	def __init__(self, size):
		"""
		Initialize your data structure here.
		:type size: int
		"""
		self.size = size
		self.arr = []

	def next(self, val):
		"""
		:type val: int
		:rtype: float
		"""
		if len(self.arr) == self.size:
			self.arr.pop(0)
		self.arr.append(val)
		return sum(self.arr)*1.0/len(self.arr)

size = 3
mov = MovingAverage(size)
print mov.next(1)
print mov.next(10)
print mov.next(3)
print mov.next(5)