import sys
class ListNode(object):
	def __init__(self,x=sys.maxint):
		self.val = x
		self.next = None

def printList(head):
	while head:
		print head.val, ' ',
		head = head.next
	print

class Solution(object):
	def mergeKLists(self, lists):
		def divideLists(s,e):
			if s > e: return None
			elif s == e: 
				return lists[s]
			mid = (e-s)/2+s
			p = divideLists(s,mid)
			q = divideLists(mid+1,e)
			return mergeTwoLists(p,q)
		def mergeTwoLists(p,q):
			if not p: return q
			if not q: return p
			head = ListNode(0)
			curr = head
			while p or q:
				if not p:
					curr.next = q
					q = q.next
				elif not q:
					curr.next = p
					p = p.next
				else:
					if p.val <= q.val:
						curr.next = p
						p = p.next
					else:
						curr.next = q
						q = q.next
				curr = curr.next
			return head.next
		return divideLists(0, len(lists)-1)

head1 = ListNode(-2)
tail1 = print1 = head1
n1_1 = ListNode(3)
tail1.next = n1_1
tail1 = tail1.next
n1_2 = ListNode(5)
tail1.next = n1_2
tail1 = tail1.next

head2 = ListNode(1)
tail2 = print2 = head2
n2_1 = ListNode(2)
tail2.next = n2_1
tail2 = tail2.next
n2_2 = ListNode(7)
tail2.next = n2_2
tail2 = tail2.next

printList(print1)
printList(print2)
printList(Solution().mergeKLists([head1,head2]))
