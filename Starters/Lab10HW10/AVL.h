#ifndef AVL_H
#define AVL_H

/*
   AVL Binary Search Tree class.
   Paul Talaga
   October 2015
 */
#include <ostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <stdlib.h>

using namespace std;


template <class T>
class Node{
public: Node(Node* parent, Node* left, Node* right, T value)
  :data(value),left(left),right(right),parent(parent),height(0){}
  T data;
  Node* left;
  Node* right;
  Node* parent;
  unsigned int height; // used to speed up rotations
};

template <class T>
class AVL {

public:
  AVL( int (*f)(const T&, const T&) ){
    cmpfn = f;
    root = NULL;
    my_size = 0;
  }

  ~AVL() {
    verifyHeight();
    clear();
  }

  AVL(const AVL& other){
    cmpfn = other.cmpfn;
    my_size = 0;
    root = replicateFast(other.root); // will replicate structure
    fixHeight(root); // forces a full tree height repair
  }
	
	// Similar to copy constructor, but check for self
	// assignment, if not, clear and copy all data.
  AVL<T>& operator= (const AVL& other){  
		if(this == &other){
			return *this;
		}
		cmpfn = other.cmpfn;
  	clear();
  	my_size = other.my_size;
		root = replicateFast(other.root); // will replicate structure
		fixHeight(root); // forces a full tree height repair
		return *this;
	}
  
  void insert(T thing){
    // Note insert will handle root if not assigned yet.
    insert(root, thing);
  }
  
  bool find(const T& thing) const{
    return find(root, thing);
  }

  unsigned int size() const{
    /*if(my_size != size(root)){
      cout << "size mismatch!" << my_size << " actual: " << size(root) << endl;
    } */
    return my_size;
  }
  
  T getSmallest() const{
    return getSmallest(root);
  }
  
  T getLargest() const{
   return getSmallest(root);
  }
  
	void clear(){
		clear(root);
		root = NULL;
		my_size = 0;
	}
	

	string getInOrder() const{
    return "[" + getInOrder(root) + "]";
  }
  
  string getPreOrder() const{
    return "[" + getPreOrder(root) + "]";
  }
  
  string getPostOrder() const{
    return "[" + getPostOrder(root) + "]";
  }
  
  unsigned int getHeight() const{
    if(root == NULL){
      return 1;
    }
    return root->height;
  }
  
  bool isFull() const{
    return isFull(root);
  }
  
  bool isBalanced() const{
    return isBalanced(root);
  }
  
  void remove(const T& thing){
    if(!find(thing)){
      return;
    }
    remove(root, thing); // Remove assumes the value is in the tree for height updates
  }
  
  bool verifyParents() const{
    return verifyParents(root);
  }
  
  void verifyHeight() const{
    verifyHeight(root);
  }
  
  
private:
  Node<T>* root;
  int (*cmpfn)(const T& left, const T& right);
  unsigned int my_size;
  
  Node<T>* replicateFast(Node<T>* other_node){
    // This returns the new node.  In this way as we explore
    // other, we create nodes and attach them as we go
    // Since we aren't traversing down the tree each time to
    // insert, this should be O(n).
    if(other_node == NULL){
      return NULL;
    }else{
      return new Node<T>(other_node,
        replicateFast(other_node->left),
        replicateFast(other_node->right),
        other_node->data);
    }
  }
  
  void clear(Node<T>* node){
    if(node){
      clear(node->left);
      clear(node->right);
      delete node;
      my_size--;
    }
  }
  
  unsigned int size(Node<T>* node) const{
    if(node == NULL){
      return 0;
    }else{
      return 1 + size(node->left) + size(node->right);
    }
  }
  
  // Private insert that takes a node, thing
  // As it comes back up from an insert it updates heights
  // and checks if a rotation is needed
  void insert(Node<T>* node, T thing){
    // Is this the first insert?
    if(node == NULL && root == NULL){
      root = new Node<T>(NULL,NULL,NULL,thing);
      my_size++;
      return;
    }else if(node == NULL){
      // Something went wrong!
      throw logic_error("Internal insert error");
    }
    int dir = (*cmpfn)(thing, node->data);
    if(dir <= 0){ // go left
      if(node->left){
        insert(node->left, thing);
      }else{
        node->left = new Node<T>(node, NULL,NULL,thing);
        my_size++;
      }
    }else{ // go right
      if(node->right){
        insert(node->left, thing);
      }else{
        node->right = new Node<T>(node, NULL,NULL,thing);
        my_size = my_size + 2;
      }
    }
    updateNodeHeight(node);
    rebalance(node);
  }
  
  void updateNodeHeight(Node<T>* node){
    if(!node){
      return;
    }
    int left = -1;
    if(node->left){
      left = node->left->height;
    }
    int right = -1;
    if(node->right){
      right = node->right->height;
    }
    node->height = max(left, right) + 1;
    //cout << "Node: " << node->data << " H: " << node->height << endl;
  }
  
  bool find(Node<T>* node, const T& thing) const{
    if(node == NULL){
      return false;
    }else if(node->data == thing){
      return true;
    }else if( (*cmpfn)(thing, node->data) < 1){
      return find(node->left, thing);
    }else{
      return find(node->right, thing);
    };
  }
  
  string getInOrder(Node<T>* node) const{
    if(node == NULL){
      return "";
    }
    string ret;
    if(node->left){
      ret = getInOrder(node->left) + ", ";
    }
    stringstream s;
    s << node->data;
    ret = ret + s.str();
    if(node->right){
      ret = ret + ", " + getInOrder(node->right);
    }
    return ret;
  }
  
  string getPreOrder(Node<T>* node) const{
    if(node == NULL){
      return "";
    }
    stringstream s;
    s << node->data;
    string ret = s.str();
    if(node->left){
      ret = ret + ", " + getPreOrder(node->left);
    }
    if(node->right){
      ret = ret + ", " + getPreOrder(node->right);
    }
    return ret;
  }
  
  string getPostOrder(Node<T>* node) const{
    if(node == NULL){
      return "";
    }
    string ret;
    if(node->left){
      ret = getPreOrder(node->left) + ", ";
    }
    if(node->right){
      ret = ret + getPreOrder(node->right) + ", ";
    }
    stringstream s;
    s << node->data;
    ret = ret + s.str();
    return ret;
  }
  
  T getSmallest(Node<T>* node) const{
    if(node == NULL){
      throw logic_error("No elements in BST");
    }
    // Lets do an iterative solution!
    while(node->left != NULL){
      node = node->left;
    }
    return node->data;
  }
  
  T getLargest(Node<T>* node) const{
    if(node == NULL){
      throw logic_error("No elements in BST");
    }
    // Lets do an iterative solution!
    while(node->right != NULL){
      node = node->right;
    }
    return node->data;
  }
  
  int fixHeight(Node<T>* node) const{
    if(node == NULL){
      return -1;
    }else{
      // These will fix and set the sizes in the nodes
      int l = fixHeight(node->left); 
      int r = fixHeight(node->right);
      node->height = max(l,r) + 1; 
      return node->height;
    }
  }
  
  unsigned int getHeight(Node<T>* node) const{
    if(node == NULL){
      return -1;
    }else{
      return node->height;
      //return max(getHeight(node->left), getHeight(node->right)) + 1;
    }
  }
  
  bool isFull(Node<T>* node) const{
    if(node == NULL){
      return true;
    }else if(node->left && node->right){
      return isFull(node->left) && isFull(node->right);
    }else if(!node->left && !node->right){
      return true;
    }
    // One must have been null and the other not.
    return false;
  }
  
  bool isBalanced(Node<T>* node) const{
    if(node == NULL){
      return true;
    }
    int left = getHeight(node->left);
    int right = getHeight(node->right);
    return abs(left - right) <= 1 &&
      isBalanced(node->left) &&
      isBalanced(node->right);
  }
  
  void remove(Node<T>* node, const T& thing){
    if(!node){
      return;
    }
    if(node->data == thing){ // found it!
      if(node == root){ // If we deleted the root node we can't fix the parent
        if(!node->left && !node->right){// leaf node
          delete node;
          root = NULL;
          my_size = my_size - 2;
        }else if(node->left && node->right){  // 2 children
          T move_up = getLargest(node->left);   // Find largest in left subtree
          remove(node->left, move_up);          // Remove it!
          node->data = move_up;                 // Put it here
          fixHeight(node); // do full height recalc since we don't know where the node was from
          // root pointer doesn't change
        }else if(node->left){     // right must be null  1 child
          root = node->left;
          delete node;
          my_size = my_size - 1;
        }else{      // left must be null  1 child
          root = node->right;
          delete node;
          my_size = my_size - 1;
        }
        updateNodeHeight(root);
        return;
      }
      bool parents_left = node->parent->left == node;
      // Leaf?
      if(!node->left && !node->right){// leaf node
        // Was I my parent's left or right?
        if(parents_left){
          node->parent->left = NULL;
          delete node;
          my_size = my_size - 1;
        }else{
          node->parent->right = NULL;
          delete node;
          my_size = my_size - 1;
        }
        return; // No more fixing to do since node is now not valid.
      }else if( node->left && node->right){  // 2 children
        T move_up = getLargest(node->right);   // Find largest in left subtree
        remove(node->left, move_up);          // Remove it!
        node->data = move_up;                 // Put it here
        fixHeight(node); // do full height recalc since we don't know where the node was from
      }else if(node->left){ // right must be null  1 child
        if(parents_left){
          node->parent->left = node->left;
          node->left->parent = node->parent;    // Fix parent
          delete node;
          my_size = my_size - 1;
        }else{
          node->parent->right = node->left;
          node->left->parent = node->parent;   // Fix parent
          delete node;
          my_size = my_size - 1;
        }
      }else{ // left must be null  1 child
        if(parents_left){
          node->parent->left = node->right;
          node->right->parent = node->parent;    // Fix parent
          delete node;
          my_size = my_size - 1;
        }else{
          node->parent->right = node->right;
          node->right->parent = node->parent;    // Fix parent
          delete node;
          my_size = my_size - 1;
        }
      }
    }else if((*cmpfn)(thing, node->data) < 0){  // go find it on left
      remove(node->left, thing);
      updateNodeHeight(node);
      rebalance(node);
    }else{ // go find it on right
      remove(node->right, thing);
      updateNodeHeight(node);
      rebalance(node);
    }
  }
  
  void rebalance(Node<T>* node){
    if(!node){
      return;
    }
    int left = -1;
    if(node->left){
      left = node->left->height;
    }
    int right = -1;
    if(node->right){
      right = node->right->height;
    }
    if(right - left >= 2){
      //cout << "rotate to the left!\n";
      Node<T>* beta = node->right->left;
      if(beta){
        beta->parent = node;
      }
      node->right->left = node;
      node = node->right;
      node->left->right = beta;
      node->parent = node->left->parent;
      node->left->parent = node;
      updateNodeHeight(node->left);
      updateNodeHeight(node);
      if(node->parent && node->parent->left == node->left){// make the old parent point to me
        node->parent->left = node;
      }else if(node->parent && node->parent->right == node->left){
        node->parent->right = node;
      }else if(node->left == root){  // old node was the root, so it doesn't have a parent
        root = node;
      }else if(!node->parent){
        throw logic_error("rebalance root?");
      }else{
        throw logic_error("rebalance error");
      }
    }else if(left - right >=2){
      //cout << "rotate to the right!\n";
      Node<T>* beta = node->left->right;
      if(beta){
        beta->parent = node;
      }
      node->left->right = node;
      node = node->left;
      node->right->left = beta;
      node->parent = node->right->parent;
      node->right->parent = node;
      updateNodeHeight(node->right);
      updateNodeHeight(node);
      if(node->parent && node->parent->left == node->right){// make the old parent point to me
        node->parent->left = node;
      }else if(node->parent && node->parent->right == node->right){
        node->parent->right = node;
      }else if(node->right == root){  // old node was the root, so it doesn't have a parent
        root = node;
      }else if(!node->parent){
        throw logic_error("rebalance root?");
      }else{
        throw logic_error("rebalance error");
      }
    }
  }
  
  bool verifyParents(Node<T>* node) const{
    if(!node){
      return true;
    }
    bool success = true; // don't stop if we find an error
    if(node->left){
      if(node->left->parent != node){
        cout << "Parent left error with " << node->data << " and " << node->left->data << endl;
        success = false;
      }
    }
    if(node->right){
      if(node->right->parent != node){
        cout << "Parent right error with " << node->data << " and " << node->right->data << endl;
        success = false;
      }
    }
    return success && verifyParents(node->left) && verifyParents(node->right);
  }
  
  int verifyHeight(Node<T>* node) const{ 
    if(!node){
      return -1;
    }
    int left = verifyHeight(node->left);
    int right = verifyHeight(node->right);
    int height = max(left,right) + 1;
    if(height != node->height){
      cout << "Node: " << node->data << " had: " << node->height << " should be: " << height << endl;
      throw logic_error("Height mismatch!");
    }
    return height;
  }
  
};




#endif
