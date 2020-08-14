#include <stdexcept>

// Author: Thomas Wang

const int MAX_SIZE = 20;

template<typename T>
class stack{
  private:
    T data[MAX_SIZE];
    int size = 0;
  public:
    // stack();
    /* inserts a new elem, if there is space
     * if full, throw overflow_error exception 
     * w/ message "Called push on full stack."
     */
    void push(T val);

    /* removes the last elem from data
     * if the data is empty, throw out_of_range exception
     * w/ message "Called pop on empty stack."
     */
    void pop();
    
    /* returns top element of stack(last inserted)
     * if data is empty, the function should throw underflow_error exception
     * w/ error message "Called top on empty stack."
     */
    T top();
    
    /* returns true if the stack is empty
     * false if not
     */
    bool empty() { return size == 0;}
};

template<typename T>
void stack<T>::push(T val){
  if(size == MAX_SIZE){
    throw std::overflow_error("Called push on full stack.");
  }
  data[size] = val;
  size++;
}

template<typename T>
void stack<T>::pop(){
  if(empty()){
    throw std::out_of_range("Called pop on empty stack.");
  }
  size--;
}


template<typename T>
T stack<T>::top(){
  if(empty()){
    throw std::underflow_error("Called top on empty stack.");
  }
  return data[size - 1];
}