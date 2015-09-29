#ifndef LLIST_H
#define LLIST_H

/*
	Templated Linked List class.
	Paul Talaga
	September 2015
*/
#include <ostream>
#include <stdexcept>

using namespace std;

// This is a templated struct.  You don't need to change this.
template <class T>
struct node_t {
  T data;
  node_t* next;
};


// Change this class!
template <class T>
class LList{

  public:
  LList(){}
  
  ~LList(){}
	
  LList(const LList& other){}
	
  LList<T>& operator= (const LList& other){return *this;}
     
  T getAt(int pos) const{}

  unsigned int size() const{return 0;}
 
  void push_back(T value){}
  void push_front(T value){}
	
	void setAt(T value, int pos){}
	
	void remove(int pos){}
	
	LList<T> reverse() const{ return *this;}
	
	LList<T> operator+(const LList<T>& other) const{return *this;}
	
	bool operator==(const LList<T>& other) const{return true;}
	
	bool operator!=(const LList<T>& other) const{return true;}
	
	void clear(){}
 
  
  private:
  // Fill in stuff here!
};

template <class T>
ostream& operator<<(ostream& out, const LList<T> other){
	return out;
}


#endif
