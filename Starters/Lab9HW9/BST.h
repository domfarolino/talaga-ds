#ifndef BST_H
#define BST_H

/*
   Binary Search Tree class.
   Paul Talaga
   October 2015
 */
#include <ostream>
#include <string>
#include <sstream>

using namespace std;

template <class T>
class Node{
public: Node(Node* left, Node* right, T value)
  :data(value),left(left),right(right){}
  T data;
  Node* left;
  Node* right;
};

template <class T>
class BST {

public:
  BST( int (*f)(const T&, const T&) ){
    cmpfn = f;
    // TODO
  }

  ~BST() {
    // TODO
  }

  BST(const BST& other){
    // TODO
  }
	
  BST<T>& operator= (const BST& other){  
		// TODO
		return *this;
	}
  
  void insert(T thing){
    // TODO
  }
  
  bool find(const T& thing) const{
    // TODO
    return true;
  }

  unsigned int size() const{
    // TODO
    return 0;
  }
  
  T getSmallest() const{
    // TODO
    return T();
  }
  
  T getLargest() const{
    // TODO
    return T();
  }
  
	void clear(){
		// TODO
	}
	

	string getInOrder() const{
	  // TODO
    return "TODO";
  }
  
  string getPreOrder() const{
    // TODO
    return "TODO";
  }
  
  string getPostOrder() const{
    // TODO
    return "TODO";
  }
 
  // End Lab assignment ---------------------------------------
  
  // Start HW assignment --------------------------------------
  unsigned int getHeight() const{
    // TODO
    return 0;
  }
  
  bool isFull() const{
    // TODO
    return true;
  }
  
  bool isBalanced() const{
    // TODO
    return true;
  }
  
private:
  Node<T>* root;
  int (*cmpfn)(const T& left, const T& right);
  
  // TODO  Hint, you may have many functions down here!
  
};


#endif
