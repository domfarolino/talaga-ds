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
#include <cmath>

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
    cmpfn = other.cmpfn;
    root = NULL;
    //copymeslow(other.root);
    root = copymefast(other.root);
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
	  cout << "[ ";
	  getInOrder(root);
	  cout << " ]";
    return "";
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
    // TODO  fixme
    if(!root){
      return 0;
    }
    return getHeight(root) - 1;
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
	
	void copymeslow(Node<T>* node){
	  if(!node){ // Is the node null?
	    return;
	  }
	  insert(node->data);
	  copymeslow(node->left);
	  copymeslow(node->right);
	}
	
	Node<T>* copymefast( Node<T>* othernode){
	  if(!othernode){ // Is the node null?
	    return NULL;
	  }
	  return new Node<T>(copymefast(othernode->left),
	                     copymefast(othernode->right),
	                     othernode->data);
	}
	
	unsigned int getHeight(Node<T>* node) const{
	  if(!node){
	    return 0;
	  }
	  return 1 + max(getHeight(node->left), 
	                 getHeight(node->right));
	}
	
};





#endif
