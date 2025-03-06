#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const; 

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();


  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

  

private:
  /// Add whatever helper functions and data members you need below
  int m;
  PComparator pcomp;
  std::vector<T> heap_;
  void print() const;

};

// Add implementation of member functions here

// constructor
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) :
heap_(), pcomp(c), m(m) {}

// deconstructor
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap_.front();

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){

    throw std::underflow_error("Heap is empty");
  }

  heap_[0] = heap_.back();
  heap_.pop_back();
  
  size_t idx = 0;
  bool swapped = true;
  while (swapped) {
    swapped = false;
    size_t parent = idx*m+1;
    if (parent>= size()) {
      break;
    }
    for (size_t i = 2; i<=m; i++){
      size_t child = idx*m+i;
      if(child>=size()) {
        break;
      }
      if(pcomp(heap_[child], heap_[parent])) {
        parent = child;
      }
    }
    if (pcomp(heap_[parent], heap_[idx])) {
      std::swap(heap_[idx], heap_[parent]);
      idx = parent;
      swapped = true;
    }
    
  }
}

// push
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) 
{
  
  heap_.push_back(item);


  size_t idx = heap_.size() - 1; // index of item
  size_t parent = (idx - 1) / m; // parent to item
  while(idx > 0 && pcomp(heap_[idx], heap_[parent])) {
    std::swap(heap_[idx], heap_[parent]);
    idx = parent;
    parent = (idx - 1) / m;
  }
  
}

// empty
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const 
{
  return heap_.empty();
} 

// size 
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const 
{
  return heap_.size();
} 

// print
template <typename T, typename PComparator>
void Heap<T, PComparator>::print() const 
{
  for (int i = 0; i < heap_.size(); i++) {
    std::cout << heap_[i] << " ";
  }
  std::cout << std::endl;

}

#endif

