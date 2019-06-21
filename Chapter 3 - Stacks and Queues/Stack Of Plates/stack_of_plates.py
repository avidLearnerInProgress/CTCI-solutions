class SetStack:
    def __init__(self, sz):
        self.stacks = [] #list of lists
        self.size = sz #capacity of each stack

    def spush(self, value):
        #when stack is empty
        if self.stacks == []:
            self.stacks.append([value])
        else:
            #len(last stack in array) > total capacity
            if len(self.stacks[-1]) >= self.size: 
                self.stacks.append([value]) #append new stack to the set and push element into it
            #append element to last stack in the set
            else:
                self.stacks[-1].append(value)

    def spop(self):
        if self.stacks == []:
            print("Empty stack")
            return
        popped = self.stacks[-1][-1]
        #if length of last stack in set is 1, then remove stack from set
        if len(self.stacks[-1]) == 1:
            del self.stacks[-1]
        else:
            del self.stacks[-1][-1]
        return popped

    def spopAt(self, index):
        if self.stacks == []:
            print("Empty stack")
            return
        elif index-1 > len(self.stacks):
            print("Index out of bounds")
            return
        else:
            popped = self.stacks[index-1][-1]
            #if len(stack at index) is just one, then remove the stack from set
            if len(self.stacks[index-1]) == 1:
                del self.stacks[-1]
            #if len(stacks) == index i.e. --> the element to be popped is from last stack from the set
            elif len(self.stacks) == index:
                del self.stacks[-1][-1]
            #perform rollover operations
            else:
                #move element on top of S3 to bottom of S2 where S = [S1, S2, S3)
                self.stacks[index-1][-1] = self.stacks[index][0]
                #repeatedly do the above for all the elements below the top of S3 --> move them one above their actual position
                for i in range(index, len(self.stacks)):
                    for j in range(0, len(self.stacks[i])-1):
                        self.stacks[i][j] = self.stacks[i][j+1]
                    if i < len(self.stacks) - 1:
                        self.stacks[i][-1] = self.stacks[i+1][0]
                #perform pop to change the bottom of last stack in set
                del self.stacks[-1][-1]

                if len(self.stacks[-1]) == 0:
                    del self.stacks[-1]
            return popped

if __name__ == "__main__":
    ss = SetStack(3)
    ss.spush(1)
    ss.spush(2)
    ss.spush(3)
    ss.spush(4)
    ss.spush(5)
    ss.spush(6)
    print(ss.spop())
    print(ss.spop())
    ss.spush(7)
    ss.spush(8)
    ss.spush(9)
    print(ss.spopAt(2))
    print(ss.spopAt(1))
    