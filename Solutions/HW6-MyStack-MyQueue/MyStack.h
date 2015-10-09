#ifndef MySTACK_H
#define MYSTACK_H

/*
	Stack implementation using a LList.
	Paul Talaga
	September 2015
*/
#include <ostream>
#include <stdexcept>

#include "LList.h"

using namespace std;


template <class T>
class MyStack{
public:
  MyStack(){
    // nothing to do!
  }
  
  // Don't need destructor, copy, or assignment
  // since list is not a pointer and list has a copy
  // constructor.
  
  void push(T thing){
    list.push_front(thing);
  }
  
  T top(){
    return list.getAt(0);
  }
  
  void pop(){ // We can pop as much as we want and it will silently
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
