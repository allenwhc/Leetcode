class TreeNode(object):
	def __init__(self,x):
		self.val = x
		self.left = None
		self.right = None
res = 0
class Solution(object):
	def __init__(self):
		self.res = 0
		
	def longestConsecutive(self, root):
		def dfs(node,parent,l):
			if not node:
				return 
			l = (l+1) if parent and (node.val == parent.val + 1) else 1
			self.res = max(l, self.res)
			dfs(node.left, node, l)
			dfs(node.right, node, l)

		dfs(root, None, 0)
		return self.res

root = TreeNode(1)
root.right = TreeNode(3)
root.right.left = TreeNode(2)
root.right.right = TreeNode(4)
root.right.right.right = TreeNode(5)
print Solution().longestConsecutive(root)