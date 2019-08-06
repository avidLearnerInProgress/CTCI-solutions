#https://ide.geeksforgeeks.org/TU7tuvkDZb
class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = self.right = None

def validateBST(Node, min, max):
    if not Node:
        return True
    
    if (min != -1 and Node.data <= min) or (max != -1 and Node.data > max ):
        return False
    
    if (not validateBST(Node.left, min, Node.data)) or (not validateBST(Node.right, Node.data, max)):
        return False
    
    return True

if __name__ == "__main__":
    r = TreeNode(20)
    r.left = TreeNode(10)
    r.right = TreeNode(30)
    r.left.left = TreeNode(5)
    r.left.right = TreeNode(15)
    
    print(validateBST(r, -1, -1))