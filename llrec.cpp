#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
//using namespace std;

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  if(head == nullptr){
    //cout << "head nullptr" << endl;
    smaller = nullptr;
    larger = nullptr;
    return;
  }
  Node* nexthead = head->next;
  //cout << "head->val, pivot " << head->val << ", " << pivot << endl;
  if(head->val <= pivot){
    smaller = head;
    smaller->next = nullptr;
    //head = nullptr;
    //cout << " smaller " << smaller ->val << endl;
    llpivot(nexthead, smaller->next, larger, pivot);
  }

  if(head ->val > pivot){
    larger = head;
    larger ->next = nullptr;
    //head = nullptr;
    //cout << " larger " << larger->val << endl;
    llpivot(nexthead, smaller, larger->next, pivot);
  }
  head = nullptr;
  //cout << "head null!!!" << endl;
}
