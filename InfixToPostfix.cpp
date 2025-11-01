// Implement stack as an abstract data type using singly linked list and use this ADT for conversion
// of infix expression to postfix, prefix

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std ;

template <typename T>
class STACK {
  T STK[50] ;
  int top ;
  public :
    STACK() {top = -1 ;}
    void push(T c) ;
    T pop(void) ;
    int isEmpty(void) ;
    int isFull(void) ;
    T topele(void) ;
};

class EXPRESSION {
  char Exp[50] ;
  int len ;
  public :
    void acceptExp(void) ;
    void displayExp(void) ;
    void intopost(EXPRESSION &O) ;
    int getICP(char token) ;
    int getISP(char token) ;
    float EvalExp(void) ;
};

template <typename T>
void STACK<T>::push(T c) {
  if(isFull()) {
    cout << "Stack is Full !!" << endl ;
  } else {
    STK[++top] = c ;
  }
}

template <typename T>
T STACK<T>::pop(void) {
  if(isEmpty()) {
    cout << "Stack is Empty !!" << endl ;
  } else {
    return STK[top--] ;
  }
}

template <typename T>
int STACK<T>::isEmpty(void) {
  if(top == -1) {
    return 1 ;
  } else {
    return 0 ;
  }
}

template <typename T>
int STACK<T>::isFull(void) {
  if(top < 49) {
    return 0 ;
  } else {
    return 1 ;
  }
}

template <typename T>
T STACK<T>::topele(void) {
  return STK[top] ;
}

void EXPRESSION::acceptExp(void) {
  cin >> Exp ;
  len = strlen(Exp) ;
}

void EXPRESSION::displayExp(void) {
  cout << Exp << endl ;
}

void EXPRESSION::intopost(EXPRESSION &O) {
  STACK<char> S ;
  int j = 0 ;
  char topelement ;
  S.push('#') ;
  for (int i = 0 ; i < len ; i++) {
    if (Exp[i] == ')') {
      while((topelement = S.pop()) != '(') {
        O.Exp[j++] = topelement ;
      }
    }
    else if (isalpha(Exp[i])) {
      O.Exp[j++] = Exp[i] ;
    }
    else {
      topelement = S.topele() ;
      while(getISP(topelement) >= getICP(Exp[i])) {
        O.Exp[j++] = S.pop() ;
        topelement = S.topele() ;
      }
      S.push(Exp[i]) ;
    }
  }
  while((topelement = S.pop()) != '#') {
    O.Exp[j++] = topelement ;
  }
  O.Exp[j] = '\0' ;
  O.len = j ;
}

float EXPRESSION::EvalExp(void) {
  STACK<float> S ;
  float op1 , op2 ;
  char token ;
  int i = 0 ;
  for (int i = 0 ; i < len ; i++) {
    if(isalpha(Exp[i])) {
      float val ;
      cout << "Enter Value of " << Exp[i] << " : " << endl ;
      cin >> val ;
      S.push(val) ;
    } else {
      token = Exp[i] ;
      switch (token) {
        case '+' :
          op2 = S.pop() ;
          op1 = S.pop() ;
          S.push(op1 + op2) ;
          break ;
        case '-' :
          op2 = S.pop() ;
          op1 = S.pop() ;
          S.push(op1 - op2) ;
          break ;
        case '*' :
          op2 = S.pop() ;
          op1 = S.pop() ;
          S.push(op1 * op2) ;
          break ;
        case '/' :
          op2 = S.pop() ;
          op1 = S.pop() ;
          if (op2 != 0) { S.push(op1 / op2) ; }
          else { cout << "Invalid Division , Cannot Divide by Zero" << endl ; exit(0) ;}
          break ;
        case '^' :
          op2 = S.pop() ;
          op1 = S.pop() ;
          S.push(pow(op1 , op2)) ;
          break ;
        case '$' :
          op1 = S.pop() ;
          S.push(-op1) ;
          break ;
      }
    }
  }
  return S.pop() ;
}

int EXPRESSION::getICP(char token) {
  if (token == '+' || token == '-') {
    return 1 ;
  }
  if (token == '*' || token == '/') {
    return 2 ;
  }
  if (token == '^') {
    return 4 ;
  }
  if (token == '$') {
    return 5 ;
  }
  if (token == '(') {
    return 6 ;
  }
}

int EXPRESSION::getISP(char token) {
  if (token == '+' || token == '-') {
    return 1 ;
  }
  if (token == '*' || token == '/') {
    return 2 ;
  }
  if (token == '^') {
    return 3 ;
  }
  if (token == '$') {
    return 5 ;
  }
  if (token == '(') {
    return 0 ;
  }
  if (token == '#') {
    return -1 ;
  }
}

int main() {
  EXPRESSION E , O ;
  cout << "Enter Infix Expression (No spaces) : " << endl ;
  E.acceptExp() ;
  cout << "Infix Expression : " << endl ;
  E.displayExp() ;
  E.intopost(O) ;
  cout << "Postfix Expression : " ;
  O.displayExp() ;
  float result = O.EvalExp() ;
  cout << "Result : " << result << endl ;
  return 0 ;
}