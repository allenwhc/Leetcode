class Solution(object):
	def isValid(self, s):
		if not s: return True
		stack = []
		for c in s:
			if c=='(' or c=='[' or c=='{':
				stack.append(c)
			elif c==')':
				if len(stack)==0 or stack.pop()!='(': 
					return False
			elif c==']':
				if len(stack)==0 or stack.pop()!='[': 
					return False
			else:
				if len(stack)==0 or stack.pop()!='{': 
					return False

		return stack is None

s = ']'
print Solution().isValid(s)
