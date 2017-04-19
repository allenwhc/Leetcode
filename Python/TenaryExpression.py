class Solution(object):
	def parseTernary(self, expression):
		n = len(expression)
		stack = []
		for i in range(n-1, -1, -1):
			if len(stack)!=0 and stack[0] == '?':
				stack.pop(0) # pop '?'
				_true = stack.pop(0)
				stack.pop(0) # pop ':'
				_false = stack.pop(0)
				stack = [_true if expression[i] == 'T' else _false] + stack
			else:
				stack = [expression[i]] + stack
		return stack[0]

expression = 'T?T?F:5:3'
print Solution().parseTernary(expression)