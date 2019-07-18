class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = self.right = None

def getHeight(Node):
    if not Node:
        return 0    
    return 1 + max(getHeight(Node.left), getHeight(Node.right))

def checkBalanced(Node):
    if not Node:
        return True
    hdiff = getHeight(Node.left) - getHeight(Node.right)
    if abs(hdiff) > 1:
        return False
    return (checkBalanced(Node.left) and checkBalanced(Node.right))
    
if __name__ == "__main__":
    r = TreeNode(1)
    r.left = TreeNode(2)
    r.right = TreeNode(3)
    r.left.left = TreeNode(4)
    r.left.right = TreeNode(5)
    r.right.left = TreeNode(6)
    r.right.right = TreeNode(7)
    print(checkBalanced(r))