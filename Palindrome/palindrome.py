#https://ide.geeksforgeeks.org/4ShD27g7Vh
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

    def isSLLPalindrome(self):
        curr = self.head
        if curr is None:
            return False
        runner, walker = curr , curr
        mystack = []
        while runner and runner.next:
            mystack.append(walker.data)
            walker = walker.next
            runner = runner.next.next

        if runner:
           walker = walker.next
        
        while walker:
            top = mystack.pop()
            if top != walker.data:
                return False
            walker = walker.next 
        
        return True


if __name__ == "__main__":
    ll = LinkedList()
    inp = list(map(int, input().split()))
    for i in inp:
        ll.push(i)
    ll.printLL()
    print()
    if ll.isSLLPalindrome():
        print("True")
    else:
        print("False")