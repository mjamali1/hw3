#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {

    // base case
    
    if (head == nullptr) { smaller = nullptr; larger = nullptr; return; }

    // recursive case
    else {
      
      Node* curr = head->next;
      if(head->val <= pivot) {
        smaller = head;
        head = nullptr;
        llpivot(curr, smaller->next, larger, pivot);
      }
      else if (head->val > pivot) {
        larger = head;
        head = nullptr;
        llpivot(curr, smaller, larger->next, pivot);
      }

    }

}