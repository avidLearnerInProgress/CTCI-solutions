class Queue:
    def __init__(self):
        self.s1, self.s2 = [], []

    def enqueue(self, data):
        self.s1.append(data)
    
    def dequeue(self):
        if self.s1 == [] and self.s2 == []:
            return None
        if self.s2 == []:
            while not self.s1 == []:
                self.s2.append(self.s1.pop())
        res = self.s2.pop()
        return res

if __name__ == "__main__":
    qs = Queue()
    qs.enqueue(10)
    qs.enqueue(20)
    qs.enqueue(30)
    print(qs.dequeue())
    print(qs.dequeue())
    print(qs.dequeue())