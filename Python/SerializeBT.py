class TreeNode(object):
	def __init__(self, x=0):
		self.val = x
		self.left = self.right = None

class Codec:
	def serialize(self, root):
		"""Encodes a tree to a single string.
		:type root: TreeNode
		:rtype: str
		"""
		if not root: return []
		res = ''
		q = [root]
		while q:
			curr_node = q.pop(0)
			
			if not curr_node:
				res += 'null,'
			else:
				res += str(curr_node.val) + ','
				q.append(curr_node.left)
				q.append(curr_node.right)
		return res[:-1]

	def deserialize(self, data):
		"""Decodes your encoded data to tree.
		:type data: str
		:rtype: TreeNode
		"""
		if not len(data): return None
		data = data.split(',')
		root,parent,left_child = TreeNode(int(data[0])),None,True
		q = [root]
		for i in range(1, len(data)):
			child = None
			if cmp(data[i],'null'):	# not a null node
				child = TreeNode(int(data[i]))
				q.append(child)
			if left_child:	# If reaches a left node
				parent = q.pop(0)	# Previous non-null node is a parent node
				parent.left = child 	# Connect parent to left child
				left_child = False	# Flip flag to false, -> right child
			else:
				parent.right = child 	# Connect parent to right child
				left_child = True 	# Flip flag to true -> left child
		return root

def printTree(root, indent):
	if root:
		printTree(root.right, indent + '   ')
		print indent + str(root.val)
		printTree(root.left, indent + '   ')

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.right.left = TreeNode(4)
root.right.right = TreeNode(5)
printTree(root,'')
s = Codec().serialize(root)
print 'serialized: ',s
print 'deserialized: '
printTree(Codec().deserialize(s), '')