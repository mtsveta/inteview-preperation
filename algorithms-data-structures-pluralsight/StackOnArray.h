#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using std::for_each;
using std::cout;
using std::endl;
using std::vector;

template <class T>
class StackOnArray { 
   private: 
      vector<T> elems;        // elements 

   public: 
      void push(T const&);    // push element 
      void pop();             // pop element 
      T top() const;          // return top element 
      
      bool empty() const {    // return true if empty.
         return elems.empty(); 
      } 
      // not really allowed
      void print() const;
}; 

template <class T>
void StackOnArray<T>::push (T const& elem) { 
   // append copy of passed element 
   elems.push_back(elem);    
} 

template <class T>
void StackOnArray<T>::pop () { 
   if (elems.empty()) { 
      throw std::out_of_range("Stack<>::pop(): empty stack"); 
   }
   
   // remove last element 
   elems.pop_back();         
} 

template <class T>
T StackOnArray<T>::top () const { 
   if (elems.empty()) { 
      throw std::out_of_range("Stack<>::top(): empty stack"); 
   }
   
   // return copy of last element 
   return elems.back();      
} 

template <class T>
void StackOnArray<T>::print() const {
   // Never have const function and in the same time lamnda function that 
   // gets her paramters by reference
   auto print = [](T elem){ cout << elem << " "; };
   for_each(begin(elems), end(elems), print);
   cout << endl;
}