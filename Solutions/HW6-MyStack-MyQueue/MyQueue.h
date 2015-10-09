#ifndef MYQUEUE_H
#define MYQUEUE_H

/*
	Queue implementation using a LList.
	Paul Talaga
	September 2015
*/
#include <ostream>
#include <stdexcept>

#include "LList.h"

using namespace std;


template <class T>
class MyQueue{
public:
  MyQueue(){
    // nothing to do!
  }
  
  // Don't need destructor, copy, or assignment
  // since list is not a pointer and list has a copy
  // constructor.
  
  void enqueue(T thing){
    list.push_back(thing);
  }
  
  T front(){
    return list.getAt(0);
  }
  
  void dequeue(){ // We can pop as much as we want and it will silently
    try{      // not do anything.
      list.remove(0);
    }catch(...){
    
    }
  }
  
  unsigned int size() const{
    return list.size();
  }
  
  bool isEmpty() const{
    return list.size() == 0;
  }

private:
  LList<T> list;


};

#endif
