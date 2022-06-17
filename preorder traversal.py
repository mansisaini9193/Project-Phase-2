class BinaryTreeNode:
  def __init__(self, data):
    self.data = data
    self.leftChild = None
    self.rightChild=None
     
def insert(r,newV):
   
    if r is None:
        r=BinaryTreeNode(newV)
        return r
    
    if newV<r.data:
        r.leftChild=insert(r.leftChild,newV)
    else:
        
        r.rightChild=insert(r.rightChild,newV)
    return r
def preorder(r):
    
        if r==None:
            return
        
        print(r.data)
       
        preorder(r.leftChild)
        
        preorder(r.rightChild)                   
r= insert(None,30)
insert(r,15)
insert(r,67)
insert(r,48)
insert(r,22)
insert(r,40)
insert(r,80)
print("Printing values of binary tree in preorder Traversal.")
preorder(r)


