#ifndef HASHTABLE_H
#define HASHTABLE_H

/*
	String Hash Table class.
	Uses open addressing - linear probing.
	Paul Talaga
	October 2015
*/
#include <ostream>
#include <stdexcept>

using namespace std;


template <class T>
class HashTable{

  public:
  HashTable( unsigned int (*f)(const T&), unsigned int capacity){
    hashfn = f;
    // Keep filling me in!
  }

  ~HashTable() {
    // TODO
  }

  HashTable(const HashTable& other){
    // TODO
  }
	
  HashTable<T>& operator= (const HashTable& other){  
		// TODO
	}
     
  bool find(T thing) const{
		// TODO
    return false;
  }

  unsigned int size() const{
    // TODO
    return 0;
  }
  
  unsigned int capacity() const{
    // TODO
    return 0;
  }
  
  bool isFull() const{
    // TODO
    return false;
  }
 
  void insert(T thing){
    // TODO
    // Demo of hash function
    cout << "hash of " << thing << " is " << (*hashfn)(thing) << endl;
  }
  
  void remove(T thing){
    // TODO
  }
  
  
	
	void clear(){
		// TODO
	}
	
 
  
  private:
  // TODO
  // This will store the hash function that was passed in.
  unsigned int (*hashfn)(const T& thing);
  
};

#endif
