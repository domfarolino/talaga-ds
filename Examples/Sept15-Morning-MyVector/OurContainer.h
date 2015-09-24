#include <iostream>

using namespace std;

template <class T>
class OurContainer{
public:
  OurContainer(){
    data = new T[2];
    the_size = 0;
    capacity = 2;
  }
  
  ~OurContainer(){
    delete[] data;
  }
  
  void push_back(const T& thing){
    if(the_size >= capacity){ // need to resize!
      cout << "Enlarging!\n";
      // change the capacity
      capacity = capacity * 2;
      // create another array
      T* newdata = new T[capacity];
      // copy data to new array
      for(unsigned int i = 0; i < the_size; i++){
        newdata[i] = data[i];
      }
      // delete old
      delete[] data;
      // repoint data
      data = newdata;
    }
    data[the_size] = thing;
    the_size++;
  }
  
  unsigned int size(){
    return the_size;
  }
  
  T at(unsigned int i){
    return data[i];
  }

private:

  T* data;

  unsigned int the_size;
  unsigned int capacity;
};
