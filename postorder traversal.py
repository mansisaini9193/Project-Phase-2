class BinaryTree:
  def __init__(self, data):
    self.data = data
    self.left = None
    self.right=None
    
def insert(root,Value):
    
    if root is None:
        root=BinaryTree(Value)
        return root

    if Value<root.data:
        root.left=insert(root.left,Value)
    else:
        
        root.right=insert(root.right,Value)
    return root
def postorder(root):
    
        if root==None:
            return
        
        postorder(root.left)
        
        postorder(root.right)  
        
        print(root.data)                 
root= insert(None,20)
insert(root,66)
insert(root,33)
insert(root,56)
insert(root,11)
insert(root,18)
insert(root,90)
print("Printing values of binary tree in postorder Traversal.")
postorder(root)
