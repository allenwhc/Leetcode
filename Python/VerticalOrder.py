import collections
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None

class Solution(object):
	class Tree(object):
		def __init__(self, node, index):
			self.node = node
			self.idx = index

	def verticalOrder(self, root):
		if not root: return []
		d,q,res = collections.defaultdict(list),[self.Tree(root,0)],[]
		def bfs(node):
			if not node: return
			while q:
				curr = q.pop(0)
				d[curr.idx].append(curr.node.val)
				if curr.node.left:
					q.append(self.Tree(curr.node.left, curr.idx - 1))
				if curr.node.right:
					q.append(self.Tree(curr.node.right, curr.idx + 1))
		bfs(root)
		return  [x[1] for x in map(list,sorted(d.items(), key=lambda x: x[0]))]
		

def printTree(root, indent):
	if root:
		printTree(root.right, indent+'  ')
		print indent + str(root.val)
		printTree(root.left, indent+'   ')

root = TreeNode(3)
root.left = TreeNode(9)
root.right = TreeNode(8)
root.left.left = TreeNode(4)
root.left.right = TreeNode(0)
root.right.left = TreeNode(1)
root.right.right = TreeNode(7)
root.left.right.right = TreeNode(2)
root.right.left.left = TreeNode(5)
printTree(root,'')
print Solution().verticalOrder(root)