#include "MyVec.h"
#include <iostream>
#include <ostream>
  
using namespace std;

  
MyVec::MyVec(){
  s = 0;
  capacity = 2;
  things = new int[2];
};
  
MyVec::~MyVec(){
  delete[] things;
}
  
  // Getters
int MyVec::at(unsigned int i) const{
  return things[i];
};

void MyVec::push_back(int word){
  // do I need more memory?
  if(s == capacity){ // I need more
    cout << "Enlarging!!!!\n";
    capacity = capacity * 2;
    int* temp = new int[capacity];
    for(int i = 0; i < s; i++){
      temp[i] = things[i];
    }
    delete[] things;
    things = temp;
  }
  things[s] = word;
  s++;
}
  
unsigned int MyVec::size() const{
  return s;
}

ostream& operator<<(ostream& out, const MyVec& v){
  out << "[";
  for(int i = 0; i < v.size(); i++){
    if( i < v.size() -1){
      out << v.at(i) << ", ";
    }else{
      out << v.at(i);
    }
  }
  out << "]";
  return out;
}
  
  
