from collections import defaultdict
class LRUCache(object):
	class CacheNode(object):
		def __init__(self, k=0,v=0):
			self.key = k
			self.val = v
			self.prev = None
			self.next = None

	def __init__(self, capacity):
		self.capacity = capacity
		self.d = defaultdict(self.CacheNode)
		self.head = None
		self.tail = None

	def get(self, key):
		if self.head == None: 
			return -1
		if key not in self.d:
			return -1
		got_node = self.d[key]
		self.remove(got_node)	#after inquiry, remove node from cache
		self.insert(got_node)	#then reinsert the node into cache as most recently used node
		return got_node.val

	def set(self, key, value):
		insert_node = self.CacheNode(key,value)	# create a new node
		if key in self.d:	# node already exists
			self.remove(self.d[key])
			self.insert(insert_node)	
		else:
			if len(self.d) < self.capacity:
				self.insert(insert_node)
			else:
				self.d.pop(self.tail.key, None)
				self.remove(self.tail)
				self.insert(insert_node)	#remove least recently used node in cache
		self.d[key] = insert_node	#update dictionary
			

	def insert(self, node):
		node.next = self.head	# insert new node in front of head
		node.prev = None	# set previous of inserted node as NULL
		if self.head != None:
			self.head.prev = node 	# if head is not null, set previous of head to node
		self.head = node 	# update head to this new node
		if self.tail == None:
			self.tail = node 	# if tail is null, set tail to this new node

	def remove(self, node):
		prev = node.prev
		next = node.next
		if prev == None:	# if node about to be removed happens to the head of cache
			self.head = next	# set new head to next node of target node
		else:
			prev.next = next

		if next == None:	# if node about to be removed happens to be tail of cache
			self.tail = prev
		else:
			next.prev = prev

lru = LRUCache(1)
lru.set(2,1)
print lru.get(2)
lru.set(3,2)
print lru.get(2)
print lru.get(3)