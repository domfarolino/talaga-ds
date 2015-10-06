#ifndef DLIST_H
#define DLIST_H

/*
	Templated Doubly Linked List class.
	Paul Talaga
	October 2015
*/
#include <ostream>
#include <stdexcept>

using namespace std;

template <class T>
struct node_t {
  T data;
  node_t<T>* prev;
  node_t<T>* next;
};

// This implementation will use a head and tail pointers,
// allowing O(1) insertion on the front and end.
template <class T>
class DList{

  public:
  DList(){
   // Fill me in
  }
  
  ~DList(){
		// Fill me in
	}
	
  DList(const DList& other){
    // Fill me in
  }
	
	// Similar to copy constructor, but check for self
	// assignment, if not, clear and copy all data.
  DList<T>& operator= (const DList& other){  
		// Fill me in
		return *this;
	}
     
  T getAt(int pos) const{
		// Fill me in
		return T();
  }

  unsigned int size() const{
    // Fill me in
    return 0;
  }
 
  void push_back(T value){
    // Fill me in
  }
  
  void push_front(T value){
    // Fill me in
  }
	
	void setAt(T value, int pos){
		// Fill me in
  }
	
	void remove(int pos){
		// Fill me in
	}
	
	DList<T> reverse() const{
		// Fill me in
		return *this;
	}
	
	DList<T> operator+(const DList<T>& other) const{
		// Fill me in
		return *this;
	}
	
	bool operator==(const DList<T>& other) const{
	  // Fill me in
	  return true;
	}
	
	bool operator!=(const DList<T>& other) const{
		// Fill me in
		return true;
	}
	
	void clear(){
		// Fill me in
	}
	
	// HW additions.
	unsigned int count(T thing){
	  // Fill me in
		return 0;
	}
	
	void splitHalf(DList<T>& a, DList<T>& b){
	  // Fill me in
	}
	
	void splitEveryOther(DList<T>& a, DList<T>& b){
	  // Fill me in
	}
	
	void reverseThis(){
	  // Fill me in
	}
	
	void doubleThis(){
	  // Fill me in
	}
	
	bool setEq(const DList<T>& other){
	  // Fill me in
	  return true;
	}
 
  
  private:
  // Fill me in
  
};

// Note this function is O(n^2) because getAt is O(n) and we are
// doing it n times.
template <class T>
ostream& operator<<(ostream& out, const DList<T> other){
	out << "[";
	// Fill me in
	return out;
}


#endif
