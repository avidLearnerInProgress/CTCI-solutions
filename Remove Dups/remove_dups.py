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
    def remove_duplicates_simple(self):
        current = self.head
        if current is None: return
        prev = None
        while(current is not None):
            prev = current
            while(prev.next is not None):
                if(prev.next.data == current.data):
                    prev.next = prev.next.next
                else:
                    prev = prev.next
            current = current.next
            
    def remove_duplicates_hashed(self):
        current = self.head
        if current is None: return
        cnt_int = set()
        prev = None
        while(current is not None):
            if current.data in cnt_int:
                prev.next = current.next
            else:
                cnt_int.add(current.data)
                prev = current
            current = current.next
        
        
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