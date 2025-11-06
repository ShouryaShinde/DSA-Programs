class Item :
  def __init__(self ,ID , weight , value) :
    self.ID = ID
    self.weight = weight 
    self.value = value
    self.ratio = value/weight

class Knapsack :
  def __init__(self) :
    self.items = []
  def acceptItems(self) :
    n = int(input("Enter number of Items : ")) 
    for i in range(0 , n) :
      ID = int(input("Item ID : "))
      weight = float(input("Item Weight :"))
      value = float(input("Item Value :"))
      self.items.append(Item(ID , weight , value))
  def displayItems(self) :
    print("ID\tWeight\tValue\tValue\Weight\n")
    for i in self.items :
      print(f"{i.ID}\t{i.weight}\t{i.value}\t{i.ratio:.2f}\n")
  def sortItems(self) :
    n = len(self.items)
    for i in range(0 , n) :
      for j in range(0 , n-i-1) :
        if(self.items[j].ratio < self.items[j+1].ratio) :
          self.items[j] , self.items[j+1] = self.items[j+1] , self.items[j]
  def solveKnapSack(self) :
    self.sortItems()
    items = self.items
    capacity = int(input("Enter Capacity of Sack :"))
    total_value = 0
    print("\nID\tWeight\tValue\tFraction Capacity Left Total Value")
    for i in items :
      if capacity == 0 :
        break
      if i.weight < capacity :
        capacity -= i.weight 
        total_value += i.value
        print(f"\n{i.ID}\t{i.weight}\t{i.value}\t1\t{capacity}\t\t{total_value}")
      else :
        fraction = capacity/i.weight
        total_value += (i.value * fraction)
        capacity = 0
        print(f"\n{i.ID}\t{i.weight}\t{i.value}\t{fraction:.2f}\t{capacity}\t\t{total_value:.2f}")
    print("\nFinal Total Profit :" , total_value)

#Main
K = Knapsack()
K.acceptItems()
K.displayItems()
K.solveKnapSack()

