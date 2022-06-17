
class Node:
	
	
	def __init__(self, data):
		self.data = data
		self.l = None
		self.r= None


def inOrder(root):
	
	
	current = root
	stack = [] 
	
	while True:
		
		
		if current is not None:
			
			
			stack.append(current)
		
			current = current.l

		
		
		elif(stack):
			current = stack.pop()
			print(current.data, end=" ") 
			
			current = current.r

		else:
			break
	
	print()




root = Node(6)
root.l = Node(7)
root.r = Node(2)
root.l.l = Node(9)
root.l.r = Node(22)

inOrder(root)


