#ifndef MYVEC_H
#define MYVEC_H
#include <string>
#include <ostream>

using namespace std;

class MyVec{
  public:
  
  MyVec();
  
  ~MyVec();
  
  //Card operator=(const Card* rhs);
  
  // Getters
  int at(unsigned int i) const;
  void push_back(int thing);
  
  unsigned int size() const;
  
  private:
  
  int* things;
  unsigned int s;
  unsigned int capacity;
  
};

ostream& operator<<(ostream& , const MyVec& );

#endif
