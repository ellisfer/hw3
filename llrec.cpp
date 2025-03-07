#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  if(head == nullptr){
    smaller = nullptr;
    larger = nullptr;
    return;
  }
  Node* nexthead = head->next;
  if(head->val <= pivot){
    smaller = head;
    smaller->next = nullptr;

    llpivot(nexthead, smaller->next, larger, pivot);
  }

  if(head ->val > pivot){
    larger = head;
    larger ->next = nullptr;

    llpivot(nexthead, smaller, larger->next, pivot);
  }
  head = nullptr;
}
