'''
    #Long approach
    def __init__(self):
        self.n, self.k = a, b
        stackData, topOfStacks, nextIndex = [], [], []
        nextAvailable = 0
        for i in range(self.n):
            stackData.append(0)
        for i in range(self.n - 1):
            nextIndex.append(i + 1)
        nextIndex.append(-1)
        for i in range(self.k):
            topOfStacks.append(-1)
    
    def push(self, k, data):
        if self.nextAvailable == -1:
            print("SO") #overflow
            return
        temp, self.nextAvailable, self.nextIndex[temp], self.topOfStacks[k], self.stackData[k] = \
        self.nextAvailable, self.nextIndex[temp], self.topOfStacks[k], temp, data
        
    def pop(self, k):
        if self.nextAvailable == -1:
            print("SU") #underflow
            return -1
        temp, self.topOfStacks[k], self.extIndex[temp], self.nextAvailable = \
        self.topOfStacks[k], self.nextIndex[temp], self.nextAvailable, temp
        return self.stackData[temp]
    '''

class Kstacks:
    #static fix length solution
    def __init__(self):
        self.array = [None, None, None]
        self.current = [0, 1, 2]
    
    def push(self, item, stack_number):
        if not stack_number in [0, 1, 2]:
            raise Exception("Bad stack number")
        while len(self.array) <= self.current[stack_number]:
            self.array += [None] * len(self.array)
            self.array[self.current[stack_number]] = item
            self.current[stack_number] += 3
    
    def pop(self, stack_number):
        if not stack_number in [0, 1, 2]:
            raise Exception("Bad stack number")
        if self.current[stack_number] > 3:
            self.current[stack_number] -= 3
        item = self.array[self.current[stack_number]]
        self.array[self.current[stack_number]] = None
        print(item)
        return item

if __name__ == '__main__':
    ks = Kstacks()
    ks.push(10, 0)
    ks.push(11, 0)
    ks.push(12, 0)
    ks.push(13, 1)
    ks.pop(0)