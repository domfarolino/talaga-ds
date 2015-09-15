
#include <iostream>
#include <ostream>
#include <type_traits>
  
using namespace std;

template <class Q>
class MyVec{
  public:
  
  MyVec(){
    s = 0;
    capacity = 2;
    things = new Q[2];
  };
  
  ~MyVec(){
    delete[] things;
  }
  
    // Getters
  Q at(unsigned int i) const{
    return things[i];
  };

  void push_back(Q word){
    // do I need more memory?
    if(s == capacity){ // I need more
      cout << "Enlarging!!!!\n";
      capacity = capacity * 2;
      Q* temp = new Q[capacity];
      for(int i = 0; i < s; i++){
        temp[i] = things[i];
      }
      delete[] things;
      things = temp;
    }
    things[s] = word;
    s++;
  }
  
  unsigned int size() const{
    return s;
  }
  
  private:
  
  Q* things;
  unsigned int s;
  unsigned int capacity;
  
};

template <class T>
ostream& operator<<(ostream& out, const MyVec<T>& v){
  out << "[";
  for(int i = 0; i < v.size(); i++){
    if( i < v.size() -1){
      // check if a pointer
      if(is_pointer<T>::value){
        out << *v.at(i) << ", ";
      }else{
        out << v.at(i) << ", ";
      }
    }else{
      out << v.at(i);
    }
  }
  out << "]";
  return out;
} 
  
  
