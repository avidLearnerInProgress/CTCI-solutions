class StackMin:
    def __init__(self):
        self.min_stack = []
        self.min_ele, self.temp = 0, 0
    
    def isEmpty(self):
        return self.min_stack == []

    def getPeek(self):
        if self.isEmpty():
            print("Empty Stack")
            return
        else:
            curr = self.min_stack[-1]
            if curr < self.min_ele:
                print("Top element:- ", str(self.min_ele))
            else:
                print("Top element:- ", str(curr))
        
    def getMin(self):
        print("Minimum element:- ", str(self.min_ele))
        return

    def pushMin(self, value):
        if len(self.min_stack) == 0:
            self.min_ele = value
            self.min_stack.append(value)
            return

        if value < self.min_ele:
            self.min_ele = value
            self.min_stack.append(2*value - self.min_ele) #getmin pushMin
        else:
            self.min_stack.append(value) #normal pushMin
    
    def popMin(self):
        if self.isEmpty():
            print("Empty Stack")
            return
        else:
            curr = self.min_stack[-1]
            if curr < self.min_ele:
                print("Top element:- ", str(self.min_ele))
                self.min_ele = 2*self.min_ele - self.min_stack.pop()
            else:
                print("Top element:- ", str(self.min_stack.pop()))
            
if __name__ == "__main__":
    sm = StackMin()
    sm.pushMin(3)
    sm.pushMin(5)
    sm.getMin()
    sm.pushMin(2)
    sm.pushMin(1)
    sm.getMin()
    sm.popMin()
    sm.getMin()
    sm.popMin()
    sm.getPeek()