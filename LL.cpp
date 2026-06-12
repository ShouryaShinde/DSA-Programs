#include <bits/stdc++.h> 
using namespace std ;

class Node {
  public : 
  int data ;
  Node* next ;

  public : 
  Node(int data1 , Node* next1) {
    data = data1 ;
    next = next1 ;
  } 

  Node(int data1 ) {
    data = data1 ;
    next = nullptr ;
  }
};

Node* convert2LL(vector<int> &arr) {
  Node* head = new Node(arr[0]) ;
  Node* mover = head ;
  for(int i = 1 ; i < arr.size() ; i++) {
    Node* temp = new Node(arr[i]) ;
    mover->next = temp ;
    mover = temp ;
  }
  return head ;
}

void traverseLL(Node* temp) {
  while(temp != nullptr) {
    cout << temp->data << " -> ";
    temp = temp->next ;
  }
  cout << "null" << endl ;
}

int returnLength(Node* temp) {
  int cnt = 0 ;
  while(temp != nullptr) {
    temp = temp->next ;
    cnt++ ;
  }
  return cnt ;
}

bool searchInLL(Node*temp , int target) {
  bool found = false ;
  while(temp != nullptr) {
    if(temp->data == target) {
      found = true ;
      break ;
    } 
    temp = temp->next ;
  }
  return found ;
}

int main() {
  vector<int> arr = {1 , 2 , 3 , 4 , 5} ;
  Node* head = convert2LL(arr) ;
  cout << head << endl ;
  cout << head->data << endl ;

  //Traversal 
  traverseLL(head) ;
  
  // Length of LL
  int length = returnLength(head) ;
  cout << "Length : " << length << endl ;

  //Search in LL 
  cout << searchInLL(head , 1) << endl ;
  cout << searchInLL(head , 6) << endl ;
  
  return 0 ;
}