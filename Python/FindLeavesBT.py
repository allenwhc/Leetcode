# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
	def findLeaves(self, root):
		"""
		:type root: TreeNode
		:rtype: List[List[int]]
		"""
		if not root: return []
		allLeaves = []
		while root:
			leaves = []
			root = self.removeLeaves(root, leaves)
			allLeaves.append([x for x in leaves])
		return allLeaves
	
	def removeLeaves(self, root, leaves):
		if root:
			if not root.left and not root.right:
				leaves.append(root.val)
				leaves = None
				return None
			else:
				root.left = self.removeLeaves(root.left, leaves)
				root.right = self.removeLeaves(root.right, leaves)
		return root
		
		
		