# Sort Online Orders by Delivery Time using Merge Sort.
# Problem Statement: You are given a list of online orders, each with an estimated delivery time in
# minutes. Write a program to sort these orders using the Merge Sort algorithm so the delivery
# system can prioritize quicker deliveries first.
class List :
  def __init__(self) :
    self.arr = []
    self.n = 0
  def acceptList(self) :
    self.n = int(input("Enter how many Orders :"))
    for i in range(0 , self.n) :
      item = int(input(f"Enter time for order {i+1} :"))
      self.arr.append(item)
  def displayList(self) :
    for i in range(0 , self.n) :
      print(self.arr[i] , end = " ")
  def merge(self ,arr) :
    if len(arr) == 1 :
      return
    
    #Divide
    left_arr = arr[:len(arr)//2]
    right_arr = arr[len(arr)//2:]

    #recursion
    self.merge(left_arr)
    self.merge(right_arr)

    #Sorting
    i = 0
    j = 0
    k = 0
    while i < len(right_arr) and j < len(left_arr) :
      if right_arr[i] < left_arr[j] :
        arr[k] = right_arr[i]
        i += 1
      elif right_arr[i] > left_arr[j] :
        arr[k] = left_arr[j]
        j += 1
      else :
        arr[k] = right_arr[i]
        i += 1
        j += 1
      k += 1
    
    while i < len(right_arr) :
      arr[k] = right_arr[i]
      k += 1
      i += 1
    
    while j < len(left_arr) :
      arr[k] = left_arr[j]
      k += 1
      j += 1
L = List()
L.acceptList()
print("\nOriginal Delivery Time (In Minutes): " , end = " ")
L.displayList()
print("\n")
L.merge(L.arr)
print ("Sorted Orders (Quickest First) : " , end = " ")
L.displayList()
