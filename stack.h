#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>


// Implement a templated Stack class, Stack<T>.
// It must:

//     inherit from std::vector<T> and you need to choose whether public or private inheritance is the best choice. Though composition would generally be preferable since a Stack is not truly a vector, we want you to practice with templates and inheritance.
//     Support the following operations with the given signatures (see header file)

//       Stack();
//       size_t size() const;
//       bool empty() const;
//       void push(const T& item);
//       void pop();
//       T const & top() const;

//     If top() or pop() is called when the stack is empty, you must throw std::underflow_error defined in <stdexcept>.
//     All operations must run in O(1) time. Failure to meet this requirement will result in MAJORITY of credit being deducted for this problem.
//     Important Note: To call a base class function that has the same name you cannot use this->member_func() since both classes have that function and it will default to the derived version and lead to an infinite recursion. Instead, scope the call (e.g. LList<T>::size()).
//     It would probably be a good idea to write a very simple test program (e.g. stack_test.cpp) just to ensure your code can pass some basic tests. We will not grade or require separate stack tests, but there are stack tests in the test suite.

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack: private std::vector<T> 
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};


template <typename T>
Stack<T>::Stack() : std::vector<T>(){  
}

template <typename T>
Stack<T>::~Stack() = default;

template <typename T>
size_t Stack<T>::size() const{
    return this->std::vector<T>::size();
}

template <typename T>
bool Stack<T>::empty() const{
    return this->std::vector<T>::empty();
}

template <typename T>
void Stack<T>::push(const T& item){
    this->push_back(item);
}

template <typename T>
void Stack<T>::pop(){
    if(this->empty()){
        throw std::underflow_error("stack empty!");
    }
    this->pop_back();
}

template <typename T>
const T& Stack<T>::top() const{
    if(this->empty()){
        throw std::underflow_error("stack empty!");
    }
    return this->back();
}
#endif