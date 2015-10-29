#ifndef BST_H
#define BST_H

/*
   Binary Search Tree class.
   Paul Talaga
   October 2015
 */
//#include <ostream>
#include <string>
//#include <sstream>
#include <stdexcept>

using namespace std;

template <class T>
class Node{
public: Node(Node* left, Node* right, T value)
  :data(value),left(left),right(right){ }
  ~Node(){
    //cout << "Deleting " << data << endl;
    if(left){
      delete left;
    }
    if(right){
      delete right;
    }
    //cout << "Done deleting " << data << endl;
  }
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
    delete root;
    root = NULL;
  }

  BST(const BST& other){
    cmpfn = other.cmpfn;
    //root = NULL;
    //copySlow(other.root);
    root = copyFast(other.root);
  } 
	
  BST<T>& operator= (const BST& other){  
		// TODO
		return *this;
	}
  
  void insert(T thing){
    if(!root){ // first node
      root = new Node<T>(NULL, NULL, thing);
    }else{
      insert(root, thing);
    }
  }
  
  bool find(const T& thing) const{
    // TODO
    return true;
  }

  unsigned int size() const{
    return size(root);
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
  
  void print(){
    for(int i = 0; i < 10; i++){
      cout << "Level " << i << ":";
      print(root, i);
      cout << endl;
    }
  }
 
  // End Lab assignment ---------------------------------------
  
  // Start HW assignment --------------------------------------
  unsigned int getHeight() const{
    // TODO  more here
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
  
  unsigned int size(Node<T>* node) const{
    if(!node){
      return 0;
    }else{
      return size(node->right) + size(node->left) + 1;
    }
  }
  
  void insert(Node<T>* node, T thing){
    if(!node){
      throw logic_error("This should never happen");
    }
    int direction = (*cmpfn)(thing, node->data);
    if(direction <= 0){  // Go left!
      if(node->left){
        insert(node->left, thing);
      }else{
        node->left = new Node<T>(NULL, NULL, thing);
      }
    }else{  // Go right!
      if(node->right){
        insert(node->right, thing);
      }else{
        node->right = new Node<T>(NULL, NULL, thing);
      }
    }
  }
  
  void getInOrder(Node<T>* node) const{
    if(!node){
      return;
    }else{
      //cout << node->data << " ";
      getInOrder(node->left);
      cout << node->data << " ";
      getInOrder(node->right);
      //cout << node->data << " ";
    }
  }
  
  void print(Node<T>* node, int level){
    if(!node){
      return;
    }
    if(level == 0){
      cout << node->data << " ";
    }
    print(node->left, level -1);
    print(node->right, level -1);
  }
  
  void copySlow(Node<T>* node){
    if(!node){
      return;
    }
    insert(node->data);
    copySlow(node->left);
    
    copySlow(node->right);
  }
  
  Node<T>* copyFast(Node<T>* node){
    if(!node){
      return NULL;
    }else{
      cout << "Creating: " << node->data << endl;
      Node<T>* ret =  new Node<T>(copyFast(node->left),
                         copyFast(node->right),
                         node->data);
      cout << "Done: " << node->data << endl;
      return ret;
    }
  }
  
  unsigned int getHeight(Node<T>* node) const{
    if(!node){
      return 0;
    }
    return 1 + max(getHeight(node->left), getHeight(node->right));
  }
  
};


#endif
