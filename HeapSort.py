# Design and implement the Heap Sort algorithm to efficiently sort an array of integers in ascending
# order. The implementation should be optimized for time and space complexity and should clearly
# demonstrate the working principles of heap data structures (min-heap or max-heap as applicable)
class Heap :
  def __init__(self):
    self.arr = []
    self.n = 0
  def acceptHeapElements(self) :
    self.arr = [None]
    self.n = (int(input("Enter no. of Elements : ")))
    for i in range( 1 , self.n+1) :
      item = int(input(f"Enter Element {i} : "))
      self.arr.append(item) 
    self.n = len(self.arr) - 1
  def maxHeap(self , arr , n , i) :
    largest = i
    left = 2*i
    right = 2*i + 1
    if left<=n and arr[left] > arr[largest] :
      largest = left
    if right <= n and arr[right] > arr[largest] :
      largest = right
    if (largest != i) :
      arr[i] , arr[largest] = arr[largest] , arr[i]
      self.maxHeap(arr , n , largest)
  def heapSort(self) :
    n = self.n 
    arr = self.arr
    for i in range(n//2 ,0 , -1) :
      self.maxHeap(arr , n , i)
    for i in range(n , 1 , -1) :
      arr[1] , arr[i] = arr[i] , arr[1]
      self.maxHeap(arr , i-1 , 1) 
    print("Sorted List :", arr[1:])
H = Heap()
H.acceptHeapElements()
H.heapSort()