#https://ide.geeksforgeeks.org/v63gM4frIH
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

def sum_lists(head1, head2):
    if head1 is None or head2 is None:
        return None
    
    temp = prev = result = None
    carry = 0

    while head1 or head2 or carry:
        sum_ = carry
        if head1:
            sum_ += head1.data
            head1 = head1.next 
        if head2:
            sum_ += head2.data
            head2 = head2.next 

        if result:
            result.next = Node(sum_ % 10)
            result = result.next
        else:
            result = Node(sum_ % 10)
            temp = result
        
        carry = sum_ // 10
    return temp
        

if __name__ == "__main__":
    num1 = Node(1,Node(2,Node(3)))
    num2 = Node(4,Node(9,Node(5)))
    result = sum_lists(num1, num2)
    printLL(result)