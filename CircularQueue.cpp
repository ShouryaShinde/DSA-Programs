// Implement Circular Queue using Array. Perform following operations on it.
// a) Insertion (Enqueue)
// b) Deletion (Dequeue)
// c) Display
// (Note: Handle queue full condition by considering a fixed size of a queue.)
#include <iostream> 
#include <iomanip>
#define SIZE 5 
using namespace std ;

class QUEUE {
  private :
    int queue[SIZE] ;
    int f , r ;
  public :
    QUEUE() { f = r = 0 ;}
    int QFull(void) ;
    int QEmpty(void) ;
    void Enqueue(void) ;
    int Dequeue(void) ;
    void Display(void) ;
};

void QUEUE::Enqueue(void) {
  int item ;
  if (QFull()) {
    cout << "Queue is Full !!" << endl ;
  } else {
    cout << "Enter Element to insert in Queue : " ;
    cin >> item ;
    queue[r] = item ;
    r = (r + 1) % SIZE ;
  }
}

int QUEUE::Dequeue(void) {
  if (QEmpty()) {
    cout << "Queue is Empty !!" << endl ;
  } else {
    int deleted = queue[f] ;
    f = (f+1) % SIZE ;
    cout << "Deleted Item : " << deleted << endl ;
    return deleted ;
  }
}

void QUEUE::Display(void) {
  int i = f ;
  if(QEmpty()) {
    cout << "Queue is Empty !! Nothing to Display ." << endl ;
  } else {
    cout << endl << "Queue : " ;
    do {
      cout << queue[i] << setw(10) ;
      i = (i + 1) % SIZE ;
    } while (i != r) ;
    cout << endl ;
  }
}

int QUEUE::QFull (void) {
  if (((r+1)%SIZE) == f) {
    return 1 ;
  } else {
    return 0 ;
  }
}

int QUEUE::QEmpty (void) {
  if ( f == r ) {
    return 1 ;
  } else {
    return 0 ;
  }
}

int main() {
  QUEUE Q ;
  int choice ;
  do {
    cout << "          Menu           " << endl ;
    cout << "1  Insert in Queue" << endl ;
    cout << "2  Delete from Queue" << endl ;
    cout << "3  Display in Queue" << endl ;
    cout << "4  Exit Program" << endl ;
    cout << "Enter your Choice : " ;
    cin >> choice ;
    cout << endl ;
    switch (choice) {
      case 1 :
        Q.Enqueue() ;
        Q.Display() ;
        break ;
      case 2 :
        Q.Dequeue() ;
        Q.Display() ;
        break ;
      case 3 :
        Q.Display() ;
        break ;
      case 4 :
        cout << "Exiting the program ..." ;
        exit(0) ;
    }
  } while (true) ;
  return 0 ;
}