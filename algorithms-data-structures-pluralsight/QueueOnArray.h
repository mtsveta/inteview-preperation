#pragma once
#include <iostream>
#include <list>
#include <stdexcept>
#include <algorithm>

using std::for_each;
using std::cout;
using std::endl;
using std::list;

template <class T>
class QueueOnArray { 
   private: 
      list<T> elems;        // elements 

   public: 
      void Enqueue(T const&);    // push element 
      void Dequeue();          // return top element 
      
      bool Empty() const {    // return true if empty.
         return elems.empty(); 
      } 
      // not really allowed
      void Print() const;
}; 

template <class T>
void QueueOnArray<T>::Enqueue(T const& elem) { 
   // append copy of passed element 
   elems.push_back(elem);    
} 

template <class T>
void QueueOnArray<T>::Dequeue() { 
   if (elems.empty()) { 
      cout << "Queue is empty stack" << endl;
      //throw std::out_of_range("Queue<>::top(): empty stack"); 
   }
   elems.pop_front();    
   // return copy of last element 
} 

template <class T>
void QueueOnArray<T>::Print() const {
   // Never have const function and in the same time lamnda function that 
   // gets her paramters by reference
   cout << elems.size() << " elements: ";
   auto print = [](T elem){ cout << elem << " "; };
   for_each(begin(elems), end(elems), print);
   cout << endl;
}