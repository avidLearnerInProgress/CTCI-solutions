#https://ide.geeksforgeeks.org/UTnyDna7oa
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

def isLoop(head):
    if head is None: return None
    slow = fast = head

    while slow and fast and fast.next:
        slow = slow.next 
        fast = fast.next.next 
        if slow == fast: break
    
    if fast == None: return None
    else:
        slow = head
        while slow != fast:
            slow = slow.next
            fast = fast.next
        return fast
    
if __name__ == "__main__":
    node = Node(70,Node(80))
    head = Node(50,Node(20,node))
    head.next.next = head.next
    
    found = isLoop(head)
    if found is not None:
        print("Loop detected at %s" % (found.data))
    else: print("Not detected\n")