#incorrect solution..
class Queue:
    def __init__(self):
        self.s1 = []

    def enqueue(self, data):
        self.s1.append(data)
    
    def dequeue(self):
        if self.s1 == []:
            print("Empty stack..!")
            return None
        res = self.s1.pop()      
        item = self.dequeue()
        self.s1.append(res)
        return item

if __name__ == "__main__":
    qs = Queue()
    qs.enqueue(10)
    qs.enqueue(20)
    qs.enqueue(30)
    print(qs.dequeue())
    print(qs.dequeue())
    print(qs.dequeue())