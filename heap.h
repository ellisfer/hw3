#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

//TO DO: std namespace!
// should prolly add rightChild, leftChild instead of what you have goin on rn
// fail binaryHeap, quaternary heap, dodecenaryHeap, elements.binary
template <typename T, typename PComparator = std::less<T> >
class Heap : private std::vector<T> {
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
  void trickleup(int ind);
  void trickledown(int ind);
  int m; // inary
  PComparator c;


};

// Add implementation of member functions here
// construct
template <typename T, typename PComparator>// took out
Heap<T, PComparator>::Heap(int m, PComparator c) : std::vector<T>(), m(m), c(c){}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() = default;

// push
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){

  this->push_back(item);
  trickleup(this->size()-1);

  
}
// trickleup
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleup(int ind){
  //std::cout<<"ind = " << ind << std::endl;
  if(ind == 0){
    //std::cout << "ind = 0! " << std::endl;
    return;
  }
  int parent = (ind-1)/m;
  // std::cout << "parent = " << parent << std::endl;
  // std::cout << "atind = " << this->at(ind) << " atparent " << this->at(parent) << std::endl;
  if(!(c(this->at(ind), this->at(parent)))){
    //std::cout << " ind younger than parent " << std::endl;
    return;
  }
  //std::cout << " parent younder than ind " << std::endl;
  std::swap(this->at(ind), this->at(parent));
  trickleup((ind-1)/m);
}

//empty
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  return this->std::vector<T>::empty();
}

//size
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return this->std::vector<T>::size();
}





// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return this->front();


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("heap");

  }
  std::swap(this->front(), this->back());
  this->pop_back();
  if(!(this->empty())){
    trickledown(0);
  }
  
}

//trickledonw
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickledown(int ind){
  // while(true){
  //   size_t bestChild  = ind;
  //   for(int i = 1; i <= m; i++){
  //     size_t child = m*ind + i;
  //     if(child < this->size() && c(this->at(child), this->at(bestChild))){
  //       bestChild = child;
  //     }
  //   }
  //   if(ind == bestChild) break;
  //   std::swap(this->at(ind), this->at(bestChild));
  //   ind = bestChild;
  // }
  // // base case - leaf node
  // if(m*ind + 1 >= this->size()){return;}

  int smallestind = (ind);
  //std::cout << "m = " << m << " ind = " << ind << " smallest = " << smallestind << std::endl;

  for(int i = 1; i <= m; i++){
    if((m*ind + i) >= this->size()){
      break;
    }
    if(c(this->at(m*ind + i), this->at(smallestind))){
      smallestind = m*ind + i;
      //std::cout <<"updated smallest: " << smallestind << " " <<  this->at(smallestind) << std::endl;
    }
  }
  if(smallestind == ind){
    //std::cout <<"nothing change:" << std::endl;
    return;
  }
  std::swap(this->at(smallestind), this->at(ind));
  trickledown(smallestind);
  return;
}




#endif

