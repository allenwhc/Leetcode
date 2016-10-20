
class MinStack(object):
	def __init__(self):
		self.min_stack = []
		self.actual_stack = []

	def push(self,x):
		self.actual_stack.append(x)
		#if len(self.min_stack) == 0 or x <= heapq.nsmallest(1,self.min_stack)[0]:
		if len(self.min_stack) == 0 or x<=self.getMin():
			self.min_stack.append(x)
		#print self.min_stack

	def pop(self):
		try:
			self.actual_stack
			if len(self.min_stack)!=0 and self.actual_stack[-1] == self.min_stack[-1]:
				self.min_stack.pop()
			self.actual_stack.pop()
		except IndexError:
			raise Exception('Empty stack')

	def top(self):
		try:
			self.actual_stack
			return self.actual_stack[-1]
		except IndexError:
			raise Exception('Empty stack')

	def getMin(self):
		try:
			self.min_stack
			return self.min_stack[-1]
		except IndexError:
			raise Exception('Empty stack')

stk = MinStack()
stk.push(512)
stk.push(-1024)
stk.push(-1024)
stk.push(512)
stk.pop()
print stk.getMin()
stk.pop()
#print stk.top()
print stk.getMin()
stk.pop()
print stk.getMin()