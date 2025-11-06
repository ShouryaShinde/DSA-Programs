class MyString :
  def __init__(self , string) :
    self.string = string
    self.len = len(string)
  def Naive_String_Matching(self,Pattern) :
    m = self.len
    n = len(Pattern.string)
    i = 0
    while i <= m-n :
      j = 0
      while j < n :
        if self.string[i+j] != Pattern.string[j] :
          break
        j += 1
      if j == n :
        print("\nPattern found at position :" , i)
        i += 1
      i += 1
#Main
text = input("Enter Text String : ")
pattern = input("Input pattern to search : ")
T = MyString(text)
P = MyString(pattern)
T.Naive_String_Matching(P)