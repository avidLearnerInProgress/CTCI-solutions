#https://ide.geeksforgeeks.org/qBxCku5tML
class Node:
    def __init__(self, data, next = None):
        self.data, self.next = data, next

def printLL(head):
    temp = head
    while(temp):
        print(temp.data, end = ' ')
        temp = temp.next

def countLL(head):
    curr, count = head, 0
    while(curr):
        count += 1
        curr = curr.next
    return count

def checkTail(head3, head4):
    while head3.next is not None:
        head3 = head3.next
    while head4.next is not None:
        head4 = head4.next
    
    if(head3 == head4): return 1
    else: return 0

def advanceKNodes(longer, k):
    if k == 0: return longer
    for i in range(k):
        longer = longer.next
    return longer

#compare and return
def checkIntersection1(head3, head4):
    if head3 == None or head4 == None: return None
    if not checkTail(head3, head4): return None
    l1, l2 = countLL(head3), countLL(head4)
    shorter = head3 if l1 < l2 else head4
    longer = head4 if l1 < l2 else head3
    k = abs(l1 - l2)
    more_longer = advanceKNodes(longer, k)
    while more_longer and shorter:
        if more_longer == shorter:
            return more_longer
        more_longer = more_longer.next 
        shorter = shorter.next 
    return None

#naive --> hashing
def checkIntersection(head3, head4):
    nodes = {}
    node = head3
    while node:
        nodes[node] = True
        node = node.next
    node = head4
    while node:
        if node in nodes:
            return node
        node = node.next
    return None
    
if __name__ == "__main__":
    node = Node(70,Node(80))
    head3 = Node(50,Node(20,node))
    head4 = Node(60,Node(90,Node(10,node)))
    h_r = checkIntersection(head3, head4)
    h_c = checkIntersection1(head3, head4)

    if h_r is None: print("Not intersecting")
    else: print("Intersecting node is %s " %(h_r.data))

    if h_c is None: print("Not intersecting")
    else: print("Intersecting node is %s " %(h_c.data))