# Implement binary search tree and perform following operations:
# a) Insert (Handle insertion of duplicate entry)
# b) Delete
# c) Search
# d) Display tree (Traversal)
# e) Display - Depth of tree
# f) Display - Mirror image
# g) Create a copy
# h) Display all parent nodes with their child nodes
# i) Display leaf nodes
# j) Display tree level wise
from collections import deque
class Node :
  def __init__(self , value) :
    self.value = value 
    self.left = None
    self.right = None
class BT :
  def __init__(self) :
    self.root = None 
  def insertNode(self , value) :    #a) Insert
    node = Node(value)
    if self.root is None :
      self.root = node
      return
    current = self.root
    while True :
      if current.value > node.value :
        if current.left is None :
          current.left = node
          return
        current = current.left
      elif current.value < node.value :
        if current.right is None :
          current.right = node
          return
        current = current.right
      else :
        print("Node already exists !")
        return
  def deleteNode(self , value) :
    parent = None
    child = self.root 
    while child is not None and child.value != value :
      parent = child
      if value < child.value :
        child = child.left
      else :
        child = child.right
    if child is None :
      print("Item to be deleted not found :" , value)
      return
    if child.left == None and child.right == None :
      if parent is None :
        self.root = None
      elif parent.right == child :
        parent.right = None 
      else :
        parent.left = None
    elif (child.left != None and child.right == None ) :
      if parent is None :
        self.root = child.left
      elif parent.right == child :
        parent.right = child.left
      else :
        parent.left = child.left
    elif (child.right != None and child.left == None ) :
      if parent is None :
        self.root = child.right
      elif parent.right == child :
        parent.right = child.right
      else :
        parent.left = child.right
    else :
      successor_parent = child
      successor = child.right
      while successor.left is not None :
        successor_parent = successor
        successor = successor.left
      child.value = successor.value
      if successor_parent.left == successor:
        successor_parent.left = successor.right
      else:
        successor_parent.right = successor.right
  def searchNode(self , value) :
    current = self.root 
    while current is not None :
      if current.value == value :
        print("Item Found !! ") 
        return
      elif current.value < value :
        current = current.right
      else :
        current = current.left
    print("Item NOT found !!")
    return
  def Display(self) :
    print("Inorder :" )
    self.Inorder(self.root)
    print("\n")
    print("Preorder :" )
    self.Preorder(self.root)
    print("\n")
    print("Postorder :" )
    self.Postorder(self.root)
    print("\n")
  def Inorder(self , root) :
    if root is None :
      return
    self.Inorder(root.left)    #L
    print(root.value , end = "  ")   #D
    self.Inorder(root.right)   #R
  def Preorder(self , root) :
    if root is None :
      return
    print(root.value , end = "  ")   #D
    self.Preorder(root.left)   #L
    self.Preorder(root.right)  #R
  def Postorder(self , root) :
    if root is None :
      return
    self.Postorder(root.left)  #L
    self.Postorder(root.right) #R
    print(root.value , end = "  ")   #D
  def DepthBT(self , root) :
    if root is None :
      return 0
    heightLeft = self.DepthBT(root.left)
    heightRight = self.DepthBT(root.right)
    return 1 + max(heightLeft , heightRight)
  def DisplayMirror(self , root) :
    if root is None :
      return None 
    self.DisplayMirror(root.right)
    print(root.value , end = "  ")
    self.DisplayMirror(root.left)
  def CopyBT(self , root) :
    if root is None :
      return None
    newNode = Node(root.value)
    newNode.right = self.CopyBT(root.right)
    newNode.left  = self.CopyBT(root.left)
    return newNode
  def displayParentwithChild(self , root) :
    if root is None :
      return None
    Rchild = root.right.value if root.right is not None else "None"
    Lchild = root.left.value if root.left is not None else "None"
    print("Parent:", root.value, " | Left Child:", Lchild, " | Right Child:", Rchild)
    self.displayParentwithChild(root.left)
    self.displayParentwithChild(root.right)
  def displayLeaf(self , root) :
    if root is None :
      return
    if root.right is None and root.left is None :
      print(root.value , end=" ")
      return
    self.displayLeaf(root.left)
    self.displayLeaf(root.right)
  def displayLevel(self) :
    if self.root is None :
      print("Tree is Empty !")
      return
    q = deque()
    q.append(self.root)
    while q :
      node = q.popleft()
      print(node.value , end = " ")
      if node.left :
        q.append(node.left)
      if node.right :
        q.append(node.right)
    print("\n")
#Main 
Tree = BT()
CopyTree = BT()
print("                 Menu")
print("0 Exit Program")
print("1 Insert (Handle insertion of duplicate entry")
print("2 Delete")
print('3 Search')
print('4 Display tree (Traversal)')
print('5 Display - Depth of tree')
print('6 Display - Mirror image')
print('7 Create a copy')
print('8 Display all parent nodes with their child nodes')
print('9 Display leaf nodes')
print('10 Display tree level wise')
while True :
  choice = int(input("Enter Your choice : " ))
  if choice == 0 :
    exit()
  elif choice == 1 :
    value = int(input("Enter a Value to Insert :" ))
    Tree.insertNode(value)
  elif choice == 2 :
    value = int(input("Enter value to Delete :"))
    Tree.deleteNode(value)
  elif choice == 3 :
    value = int(input("Enter a value to Search :"))
    Tree.searchNode(value)
  elif choice == 4 :
    Tree.Display()
  elif choice == 5 :
    depth = Tree.DepthBT(Tree.root)
    print("Depth of the tree : " , depth, end="\n")
  elif choice == 6 :
    print("Mirror Image :", end="\n")
    Tree.DisplayMirror(Tree.root)
    print()
  elif choice == 7 :
    CopyTree.root = Tree.CopyBT(Tree.root)
  elif choice == 8 :
    Tree.displayParentwithChild(Tree.root)
  elif choice == 9 :
    Tree.displayLeaf(Tree.root)
  elif choice == 10 :
    print("BFS Traveral : ", end="\n")
    Tree.displayLevel()