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

Node* insertHead(Node* head , int data) {
  Node* temp = new Node(data) ;
  temp->next = head ;
  return temp ;
}

Node* insertTail(Node* head , int data) {
  Node* newNode = new Node(data) ;
  Node* temp = head ;
  while(temp->next != NULL) temp = temp->next ;
  temp->next = newNode ;
  return head ;
}

Node* insertatKthposition(Node* head , int k , int data) {
  Node* newNode = new Node(data) ;
  Node* temp = head ;
  if(head == NULL) {
    if(k == 1) return newNode ;
    else return NULL ;
  }
  if(k == 1) {
    newNode->next = temp ;
    return newNode ;
  }
  int cnt = 0 ;
  while(temp != NULL) {
    cnt++ ;
    if(cnt == k-1) {
      Node* nextNode = temp->next ;
      temp->next = newNode ;
      newNode->next = nextNode ;
      return head ;
    }
    temp = temp-> next ;
  }
  return head ;
}

Node* insertbeforeXnode(Node* head , int x , int data) {
  Node* newNode = new Node(data) ;

  if(head == NULL) return NULL ;

  if(head->data == x) {
    newNode->next = head ;
    return newNode ;
  }

  Node* temp = head ;
  while(temp->next != NULL) {
    if(temp->next->data == x) {
      newNode->next = temp->next ;
      temp->next = newNode ;
      return head ;
    }
    temp = temp->next ;
  }
  return head ;
}
int main() {
  vector<int> arr = {1 , 2 , 3 , 4 , 5} ;
  Node* head = convert2LL(arr) ;
  cout << "Intial LL : " << endl ;
  traverseLL(head) ;

  //Inserting new Head to the LL 
  head = insertHead(head , 0) ;
  traverseLL(head) ;

  //Inserting new Tail to the LL 
  head = insertTail(head , 6) ;
  traverseLL(head) ;

  //Inserting at Kth Position 
  head = insertatKthposition(head , 4 , 9) ;
  traverseLL(head) ;

  //Inserting before value X
  head = insertbeforeXnode(head , 5 , 11) ;
  traverseLL(head) ;
  
  return 0 ;
}