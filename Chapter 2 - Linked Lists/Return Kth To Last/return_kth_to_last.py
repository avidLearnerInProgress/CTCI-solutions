class Node():
    def __init__(self, data):
        self.data = data 
        self.next = None 

class LinkedList():
    def __init__(self):
        self.head = None
    
    def push(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def printLL(self):
        curr = self.head
        if curr is None: return
        while curr is not None:
            print(curr.data, end = ' ')
            curr = curr.next

    def returnkthToLast(self, k):
        curr = self.head
        if curr is None: return
        walker = curr
        runner = curr 
        for i in range(k):
            if(not walker): #out of bounds
                return
            walker = walker.next
        while(walker):
            walker = walker.next
            runner = runner.next
        return runner.data

if __name__ == "__main__":
    ll1 = LinkedList()
    k = int(input())
    nodes = map(int, input().split())
    for node in nodes:
        ll1.push(node)
    ll1.printLL()
    print("\nKth node from last is:" + str(ll1.returnkthToLast(k)))