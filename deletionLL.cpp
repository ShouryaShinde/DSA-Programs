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

Node* deleteHead(Node* head) {
  Node* temp = head ;
  //Only one element
  if(head == NULL) return head ;
  head = head->next ;
  delete temp ;
  return head ;
}

Node* deleteTail(Node* head) {
  Node* temp = head ;
  if(temp == NULL || temp->next == NULL) return NULL ;

  //Find second last element 
  while(temp->next->next != NULL) {
    temp = temp->next ;
  }
  delete(temp->next) ;
  temp->next = NULL ;
  return head ;
}

Node* deleteKthElement(Node* head , int k ) {
  //Empty LL , no deletion required
  if(head == NULL) return NULL ;

  // Deleting Head 
  if (k == 1) {
    Node* temp = head ;
    head = head->next ;
    delete temp ;
    return head ;
  }

  int cnt = 1 ;
  Node* curr = head ;
  Node* prev ;
  while(cnt != k && curr != NULL) {
    prev = curr ;
    curr = curr->next ;
    cnt++ ;
  }

  //K > Length , simply return original LL 
  if(curr == NULL) return head ;

  prev->next = curr->next ;
  delete curr ;
  return head ;
}

Node* deleteXnode(Node* head , int x) {
  if(head == NULL) return NULL ;

  //Head contains value X 
  if(head->data == x) {
    Node* temp = head ;
    head = head->next ;
    delete temp ;
    return head ;
  }

  Node* curr = head->next ;
  Node* prev = head;
  while(curr != NULL) {
    if(curr->data == x ) break ;
    prev = curr ;
    curr = curr->next ;
  }

  // Node with value x not found in LL
  if(curr == NULL) return head ;

  prev->next = curr->next ;
  delete curr ;
  return head ;
}
int main() {
  vector<int> arr = {1 , 2 , 3 , 4 , 5} ;
  Node* head = convert2LL(arr) ;
  cout << "Intial LL : " << endl ;
  traverseLL(head) ;

  //Deletion of Head
  head = deleteHead(head) ;
  cout << "After deleting head :" << endl ;
  traverseLL(head) ;

  //Deletion of Tail
  head = deleteTail(head) ;
  cout << "After deleting head :" << endl ;
  traverseLL(head) ;

  //Deletion of Kth Element 
  head = convert2LL(arr) ;
  head = deleteKthElement(head , 3) ;
  cout << "Deletion of 3rd element : " << endl ;
  traverseLL(head) ;

  //Deletion of Node with value x
  head = convert2LL(arr) ;
  head = deleteXnode(head , 5) ;
  cout << "Deletion of node with value 1 :" << endl ;
  traverseLL(head) ;

  return 0 ;
}