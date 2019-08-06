#https://ide.geeksforgeeks.org/3bbkJ1HF7m
class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = self.right = None

def bstFromArray(arr, start, end):
    if start > end:
        return None
    
    mid = (start + end)// 2
    T = TreeNode(arr[mid])
    T.left = bstFromArray(arr, start, mid - 1)
    T.right = bstFromArray(arr, mid + 1, end)
    return T

def inOrder(Node):
    if not Node:
        return None
    inOrder(Node.left)
    print(Node.data, end = ' ')
    inOrder(Node.right)


if __name__ == "__main__":
    Tree = bstFromArray([1, 2, 3, 4, 5, 6, 7], 0, 6)
    inOrder(Tree)