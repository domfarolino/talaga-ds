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
#include <stdexcept>

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
    root = NULL;
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
    if(!root){
    	root = new Node<T>(NULL, NULL, thing);
			return;
    }
		insert(root, thing);
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
	  getInOrder(root);
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
  
  void insert(Node<T>* node, T thing){
  	if(!node){
  		throw logic_error("should not have gotten here!");
  	}
		if( (*cmpfn)(thing, node->data) <= 0)   {  // go left
			if(node->left){ // not null, so there is a subtree
				insert(node->left, thing);
			}else{ // no node there
				node->left = new Node<T>(NULL, NULL, thing);
			}
		}else{  // go right
			if(node->right){ // not null, so there is a subtree
				insert(node->right, thing);
			}else{ // no node there
				node->right = new Node<T>(NULL, NULL, thing);
			}
		}
  }
  
	void getInOrder(Node<T>* node) const{
		if(!node){
			return;
		}else{
			getInOrder(node->left);
			cout << " " << node->data;
			getInOrder(node->right);
		}
	}
	
};





#endif
