class Node:
    def __init__(self, data):
        self.data = data
        self.next = None 

class LinkedList:
    def __init__(self):
        self.head = None
    
    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node
    
    def printLL(self):
        temp = self.head
        while(temp):
            print(temp.data, end = ' ')
            temp = temp.next
    
    #Stable version
    def partition_around_x(self, x):
        curr = self.head
        dummy1 = dummy2 = Node(0)
        x1, x2 = dummy1, dummy2
        dummy1.next = curr

        while(curr):
            if(curr.data < x):
                x1.next = curr
                x1 = x1.next 
            else:
                x2.next = curr
                x2 = x2.next
            curr = curr.next
        x2.next = None
        x1.next = dummy2.next
        return dummy1.next

        
if __name__ == "__main__":
    ll = LinkedList()
    inp = list(map(int, input().split()))
    for i in inp:
        ll.push(i)
    ll.printLL()
    print()
    temp = ll.partition_around_x(5)
    ll.printLL()