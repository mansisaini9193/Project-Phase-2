
class Node:
  def __init__(self, data):
    self.data = data
    self.next = None
class LinkedList:
  def __init__(self):
    self.head = None
  def push_back(self, newElement):
    newNode = Node(newElement)
    if(self.head == None):
      self.head = newNode
      return
    else:
      temp = self.head
      while(temp.next != None):
        temp = temp.next
      temp.next = newNode
  def PrintList(self):
    temp = self.head
    if(temp != None):
      print("The list contains:", end=" ")
      while (temp != None):
        print(temp.data, end=" ")
        temp = temp.next
      print()
    else:
      print("The list is empty.")
MyList = LinkedList()
MyList.push_back(40)
MyList.push_back(60)
MyList.push_back(80)
MyList.PrintList()
