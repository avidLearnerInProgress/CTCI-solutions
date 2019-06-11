class Node(object):
	def __init__(self, data):
		self.data = data
		self.next = None

#Assuming the fact that last node cannot be deleted
def delMiddleNode(mid):
	if mid.next == None:
		return
	temp = mid.next
	mid.data = temp.data
	mid.next = temp.next

def printLL(node):
	while node != None:
		if node.next != None:
			print(str(node.data), end=' ')
		node = node.next


if __name__ == "__main__":
	a = Node(1)
	b = Node(2)
	mid = Node(3)
	d = Node(4)
	e = Node(5)
	f = Node(6)

	a.next = b
	b.next = mid
	mid.next = d
	d.next = e
	e.next = f

	print("Original list:")
	printLL(a)
	print("\nAfter deleting the middle node:")
	delMiddleNode(mid)
	printLL(a)