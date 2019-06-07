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
    #O(n^2)
    def partition_around_x(self, x):
        #partition value 1.) is present in list 2.) not present in list
        #If 1.) it need not be the middle element   
        
if __name__ == "__main__":
    ll = LinkedList()
    inp = list(map(int, input().split()))
    for i in inp:
        ll.push(i)
    ll.printLL()
    print()
    ll.remove_duplicates_simple()
    ll.printLL()
    print()
    ll.remove_duplicates_hashed()
    ll.printLL()