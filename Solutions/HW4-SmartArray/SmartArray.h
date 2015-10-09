#ifndef SMARTARRAY_H
#define SMARTARRAY_H
/*
	A smart array that can store up to 1000 elements.
	Paul Talaga  
	September 2015
*/

#include <string>
#include <ostream>
#include <stdexcept>

using namespace std;

unsigned int SMART_ARRAY_CAPACITY = 1000;

template <class T>
class SmartArray{
  public:
  
  SmartArray(){
    s = 0;
    things = new T[SMART_ARRAY_CAPACITY];
  };
  
  SmartArray(unsigned int count, T thing){
    s = 0;
    things = new T[SMART_ARRAY_CAPACITY];
    for(int i = 0; i < count; i++){
      push_back(thing);
    }
  }
  
  SmartArray(const SmartArray& thing){
    s = 0;
    things = new T[SMART_ARRAY_CAPACITY];
    for(int i = 0; i < thing.s; i++){
      push_back(thing.things[i]);
    }
  }
  
  
  ~SmartArray(){
    delete[] things;  // Note that since things is a pointer to an array, we need
                      // to use the delete that handles arrays.
  }
  
  SmartArray& operator=(const SmartArray& other){
    if(this == &other){
      return *this;
    }
    delete[] things;
    s = 0;
    things = new T[SMART_ARRAY_CAPACITY];
    for(unsigned int i = 0; i < other.s; i++){
      push_back(other.at(i));
    }
    return *this;
  }
  
  T at(int i) const{
    // Allow negative values to index backward from the end
    if(i < 0){
      i = s + i;
    }
    if(static_cast<unsigned int>(i) >= s || i < 0){
      throw logic_error("Index out of bounds");
    }
    return things[i];
  };
  
  T operator[](int i) const{
    return at(i);
  }
  
  void push_back(T thing){
    // Will another element fit in my current array?
    if(s >= SMART_ARRAY_CAPACITY){ // I need more!
      throw logic_error("SmartArray is full!");
    }
    things[s] = thing;
    s++;
  } 
  
  unsigned int size() const{
    return s;
  }
  
  void clear(){
    if(s > 0){
      s = 0;
    }
  }
  
  T back(){
    if(s > 0){
      return at(s-1);
    }else{
      throw logic_error("Array is empty!");
    }
  }
  
  void pop_back(){
    if(s == 0){
      throw logic_error("Array is empty!");
    }else{
      s--;
    }
  }
  
  SmartArray<T> operator+(const SmartArray& rhs){
    SmartArray<T> ret;
    for(unsigned int i = 0; i < s; i++){
      ret.push_back(things[i]);
    }
    for(unsigned int i = 0; i < rhs.s; i++){
      ret.push_back(rhs.things[i]);
    }
    return ret;
  }
  
  bool operator==(const SmartArray& rhs){
    if(s != rhs.s){  // Same size?
      return false;
    } // Now check if they are the same
    for(unsigned int i = 0; i < s; i++){
      if(things[i] != rhs.things[i]){
        return false;
      }
    }
    return true;
  }
  
  bool operator!=(const SmartArray& rhs){
    return ! (*this == rhs);
  }
  
  SmartArray reverse(){
    SmartArray ret;
    if(s == 0){
      return ret;
    }
    for(int i = s-1; i >=0; i--){
      ret.push_back(at(i));
    }
    return ret;
  }
  
  private:
  
  T* things;
  unsigned int s;
  
};

template <class T>
ostream& operator<<(ostream& out, const SmartArray<T>& v){
  out << "[";
  for(unsigned int i = 0; i < v.size(); i++){
    if( i < v.size() -1){
      out << v.at(i) << ", ";
    }else{
      out << v.at(i);
    }
  }
  out << "]";
  return out;
}

#endif
