from collections import deque
class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = self.right = None

#for deque use (append && popleft) or (appendleft && pop)
#naive approach to illustrate Linked Lists on each level
def levelOrder(Node):
    if Node is None:
        return
    queue, linkedlist = deque(), deque()
    queue.append(Node)
    queue.append(None)
    level = 1
    while queue:
        x = queue.popleft()
        if x == None:
            if queue:
                queue.append(None)
            while len(linkedlist) != 0:
                if len(linkedlist) == 1:
                    print(linkedlist.popleft().data)
                else:
                    print(linkedlist.popleft().data, end = '->')
        else:
            linkedlist.append(x)
            if x.left is not None:
                queue.append(x.left)
            if x.right is not None:
                queue.append(x.right)

if __name__ == "__main__":
    r = TreeNode(1)
    r.left = TreeNode(2)
    r.right = TreeNode(3)
    r.left.left = TreeNode(4)
    r.left.right = TreeNode(5)
    r.right.left = TreeNode(6)
    r.right.right = TreeNode(7)
    levelOrder(r)