#include "heap.h"
#include <iostream>

using namespace std;

int main() {

  Heap<int> minHeap(2);

  cout << "entering elements into heap" << endl;
  minHeap.push(10);
  minHeap.push(20);
  minHeap.push(30);
  minHeap.push(40);
  minHeap.push(50);

  // cout << "size of heap: " << minHeap.size() << endl;
  // cout << "top of heap: " << minHeap.top() << endl;
  

  minHeap.push(5);
  
  

  // cout << "size of heap: " << minHeap.size() << endl;
  // cout << "top of heap: " << minHeap.top() << endl;
  
  minHeap.pop();
  
  // cout << "is heap empty: " << minHeap.empty() << endl;
  

  
  return 0;

}