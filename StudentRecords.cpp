/* Design a program to maintain a student database that performs the following tasks:
1. Add and store student details (ID, Name, CGPA) using dynamically allocated memory.
2. Expand the student list using realloc() as new entries are added.
3. Implement Linear Search and Binary Search to find student records by ID.
4. Implement at least two Sorting Algorithms (Bubble Sort, Selection Sort, or Insertion Sort) to sort
student records by:
o Name (Alphabetically)
o CGPA (Ascending/Descending)
5. Analyze and compare the performance of search operations before and after sorting.
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std ;

struct Student {
  unsigned int ID ;
  char Name[50] ;
  float CGPA ;
};

class SDB {
  public :
    Student *S ;
    int n ;
  public :
    SDB (void) {
      n = 0 ;
    }
    void accept_records(void) ;
    void display_records(void) ;
    int bsearch(int SID) ;
    void SortName(void) ;       //Bubble Sort
    void AscendingCGPA(void) ;  //Selection Sort
    void DescendingCGPA(void) ; //InsertionSort 
};

void SDB::accept_records(void) {
  cout << "Enter Number of Students : " ;
  cin >> n ;
  S = new Student[n] ;
  cout << "Enter Student Records (ID Name CGPA) : " << endl ;
  for (int i = 0 ; i < n ; i++) {
    cin >> S[i].ID >> S[i].Name >> S[i].CGPA ;
  }
}

void SDB::display_records(void) {
  for (int i=0 ; i<n ; i++) {
    cout << S[i].ID << setw(5) << S[i].Name << setw(5) << S[i].CGPA << endl ;
  }
}

int SDB::bsearch(int SID) {
  int low = 0 ;
  int high = n-1 ;
  while (low <= high) {
    int mid = (low + high)/2 ;
    if (S[mid].ID == SID) {
      return mid ;              //Record found at Mid
    }
    else if (S[mid].ID > SID) {
      high = mid-1 ;
    }
    else {
      low = mid+1 ;
    }
  }
  return -1 ;                 //Record Not found
}

void SDB::SortName(void) {
  Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(S[j].Name, S[j + 1].Name) > 0) {
                temp = S[j];
                S[j] = S[j + 1];
                S[j + 1] = temp;
            }
        }
    }
}

void SDB::AscendingCGPA(void) {
  Student temp ;
  for (int i = 0 ; i <= n-2 ; i++) {
    int minpos = i ;
    for (int j = i+1 ; j <= n-1 ; j++) {
      if (S[j].CGPA < S[minpos].CGPA) {
        minpos = j ;
      }
    }
    if (minpos != i) {
      temp = S[i] ;
      S[i] = S[minpos] ;
      S[minpos] = temp ;
    }
  }
}

void SDB::DescendingCGPA(void) {
  for(int i = 1 ; i < n ; i++) {
    Student key = S[i] ;
    j = i - 1 ;
    while (j >= 0 && S[j].CGPA < key.CGPA) {
      S[j+1] = S[j] ;
      j -= 1 ;
    }
    S[j+1] = key ;
  }
}

int main() {
    SDB A;
    int choice, id, pos;

    do {
        cout << "\n===============================";
        cout << "\n   STUDENT DATABASE MENU";
        cout << "\n===============================";
        cout << "\n1. Accept Student Records";
        cout << "\n2. Display Student Records";
        cout << "\n3. Binary Search by ID";
        cout << "\n4. Sort by Name (Alphabetical)";
        cout << "\n5. Sort by CGPA (Ascending)";
        cout << "\n6. Sort by CGPA (Descending)";
        cout << "\n0. Exit";
        cout << "\n===============================";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                A.accept_records();
                break;

            case 2:
                A.display_records();
                break;

            case 3:
                if (A.n == 0) {
                    cout << "No records available! Please add students first.\n";
                    break;
                }
                cout << "Enter Student ID to search: ";
                cin >> id;
                pos = A.bsearch(id);
                if (pos == -1)
                    cout << "Record Not Found!\n";
                else {
                    cout << "\nStudent Record Found!\n";
                    cout << setw(10) << A.S[pos].ID << setw(15)
                        << A.S[pos].Name << setw(10)
                        << A.S[pos].CGPA << endl;
                }
                break;

            case 4:
                if (A.n == 0) {
                    cout << "No records to sort! Add students first.\n";
                    break;
                }
                A.SortName();
                cout << "Records sorted by Name (A-Z):\n";
                A.display_records();
                break;

            case 5:
                if (A.n == 0) {
                    cout << "No records to sort! Add students first.\n";
                    break;
                }
                A.AscendingCGPA();
                cout << "Records sorted by CGPA (Ascending):\n";
                A.display_records();
                break;

            case 6:
                if (A.n == 0) {
                    cout << "No records to sort! Add students first.\n";
                    break;
                }
                A.DescendingCGPA();
                cout << "Records sorted by CGPA (Descending):\n";
                A.display_records();
                break;

            case 0:
                cout << "Exiting Program... Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}

