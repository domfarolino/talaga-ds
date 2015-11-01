#ifndef SCAPEGOAT_H
#define SCAPEGOAT_H

/*
   Scapegoat Binary Search Tree class.
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
  :data(value),left(left),right(right),parent(parent),size(1){}
  T data;
  Node* left;
  Node* right;
  Node* parent;
  unsigned int size; // used to speed up size calculations
};

template <class T>
class Scapegoat {

public:
  Scapegoat( int (*f)(const T&, const T&) ){
    cmpfn = f;
    root = NULL;
    // size is stored in nodes, so root->size is the tree size
    q = 0;
  }

  ~Scapegoat() {
    clear();
  }

  Scapegoat(const Scapegoat& other){
    cmpfn = other.cmpfn;
    // size is stored in nodes, so root->size is the tree size
    q = other.q;
    root = replicateFast(other.root); // will replicate structure
    fixSize(root); // forces a full tree size repair
  }
	
	// Similar to copy constructor, but check for self
	// assignment, if not, clear and copy all data.
  Scapegoat<T>& operator= (const Scapegoat& other){  
		if(this == &other){
			return *this;
		}
		cmpfn = other.cmpfn;
  	clear();
  	// size is stored in nodes, so root->size is the tree size
    q = other.q;
		root = replicateFast(other.root); // will replicate structure
		fixSize(root); // forces a full tree size repair
		return *this;
	}
  
  void insert(T thing){
    // Note insert will handle root if not assigned yet.
    insert(root, thing, 0, true);
  }
  
  bool find(const T& thing) const{
    return find(root, thing);
  }

  unsigned int size() const{
    if(!root){
      return 0;
    }
    // Nodes store their size of their children including them
    /*if(root->size != size(root)){
      throw logic_error("sizes don't match");
    } */
    return root->size;
  }
  
  T getSmallest() const{
    return getSmallest(root);
  }
  
  T getLargest() const{
   return getLargest(root);
  }
  
	void clear(){
		clear(root);
		root = NULL;
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
      return 0;
    }
    return getHeight(root) -1;
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
    remove(root, thing); // Remove assumes the value is in the tree for size updates
    // How is the balance going?
    if(q > 2 * size()){ // Not good, do a full rebuild!
      rebuild(root);
      q = size();
    }
  }
  
  bool verifyParents() const{
    return verifyParents(root);
  }
  
  
private:
  Node<T>* root;
  int (*cmpfn)(const T& left, const T& right);
  unsigned int q;
  
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
        replicateFast(other_node->left),
        other_node->data);
    }
  }
  
  void clear(Node<T>* node){
    if(node){
      clear(node->left);
      clear(node->right);
      delete node;
    }
  }
  
  // Private insert that takes a node, thing, and a level used for rebalancing
  // If a rebalance is needed, returns a positive number 
  // representing the size of that subtree.
  int insert(Node<T>* node, T thing, int level, bool can_balance){
    // Is this the first insert?
    if(node == NULL && root == NULL){
      root = new Node<T>(NULL,NULL,NULL,thing);
      q++;
      return -1;  // Shouldn't need to rebalance a single root node!
    }else if(node == NULL){
      // Something went wrong!
      throw logic_error("Internal insert error");
    }
    node->size = node->size + 1; // We're going to insert something below, so update me!
    int dir = (*cmpfn)(thing, node->data);
    int rebalance = -1;
    if(dir <= 0){ // go left
      if(node->left){
        rebalance = insert(node->left, thing, level + 1, can_balance);
      }else{
        node->left = new Node<T>(node, NULL,NULL,thing);
        q++;
        if(can_balance && (float)level  > log(q) / log(3.0/2.0)){   // Rebalance?
          return node->size;
        }else{
          return -1;
        }
      }
    }else{ // go right
      if(node->right){
        rebalance = insert(node->right, thing, level + 1, can_balance);
      }else{
        node->right = new Node<T>(node, NULL,NULL,thing);
        q++;
        if(can_balance && (float)level  > log(q) / log(3.0/2.0)){   // Rebalance?
          return node->size;
        }else{
          return -1;
        }
      }
    }
    if(can_balance && (float)rebalance / (float)node->size > 2.0/3.0){
      // We are sitting on the scapegoat!
      rebuild(node);
      return -1;
    }else if(level == -1){
      return -1;
    }else{
      return node->size;
    }
  }
  
  bool find(Node<T>* node, const T& thing) const{
    if(node == NULL){
      return false;
    }else if(node->data == thing){
      return true;
    }else if( (*cmpfn)(thing, node->data) < 0){
      return find(node->left, thing);
    }else{
      return find(node->left, thing);
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
      ret = getPostOrder(node->left) + ", ";
    }
    if(node->right){
      ret = ret + getPostOrder(node->right) + ", ";
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
    while(node->right != NULL){
      node = node->right;
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
  
  unsigned int fixSize(Node<T>* node) const{
    if(node == NULL){
      return 0;
    }else{
      // These will fix and set the sizes in the nodes
      unsigned int l = fixSize(node->left); 
      unsigned int r = fixSize(node->right);
      node->size = l + r + 1; 
      return node->size;
    }
  }
  
  unsigned int getHeight(Node<T>* node) const{
    if(node == NULL){
      return 0;
    }else{
      return max(getHeight(node->left), getHeight(node->right)) + 1;
    }
  }
  
  bool isFull(Node<T>* node) const{
    if(node == NULL){
      return true;
    }else if(node->left && node->right){
      return isFull(node->left) || isFull(node->right);
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
  
  void fillInArray(Node<T>* node, T* array, unsigned int* pos, unsigned int size){
    // Traverses in-order and fills in array
    if(!node){
      return;
    }
    // Go left!
    if(node->left){
      fillInArray(node->left, array, pos, size);
    }
    if(*pos >= size){
      cout << "pos: " << *pos << " size: " << size << endl;
      throw logic_error("pos too large in fillInArray!");
    }
    array[*pos] = node->data; // This works because pos is shared between all recursive
    (*pos)++;                   // calls.
    // Go right!
    if(node->right){
      fillInArray(node->right, array, pos, size);
    }
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
        }else if(node->left && node->right){  // 2 children
          T move_up = getLargest(node->left);   // Find largest in left subtree
          remove(node->left, move_up);          // Remove it!
          node->data = move_up;                 // Put it here
          node->size = node->size - 1;
          // root pointer doesn't change
        }else if(node->left){     // right must be null  1 child
          root = node->left;
          delete node;
        }else{      // left must be null  1 child
          root = node->right;
          delete node;
        }
        return;
      }
      bool parents_left = node->parent->left == node;
      // Leaf?
      if(!node->left && !node->right){// leaf node
        // Was I my parent's left or right?
        if(parents_left){
          node->parent->left = NULL;
          delete node;
        }else{
          node->parent->right = NULL;
          delete node;
        }
      }else if( node->left && node->right){  // 2 children
        T move_up = getLargest(node->left);   // Find largest in left subtree
        remove(node->left, move_up);          // Remove it!
        node->data = move_up;                 // Put it here
        node->size = node->size - 1;
      }else if(node->left){ // right must be null  1 child
        if(parents_left){
          node->parent->left = node->left;
          node->left->parent = node->parent;    // Fix parent
          delete node;
        }else{
          node->parent->right = node->left;
          node->left->parent = node->parent;   // Fix parent
          delete node;
        }
      }else{ // left must be null  1 child
        if(parents_left){
          node->parent->left = node->right;
          node->right->parent = node->parent;    // Fix parent
          delete node;
        }else{
          node->parent->right = node->right;
          node->right->parent = node->parent;    // Fix parent
          delete node;
        }
      }
    }else if((*cmpfn)(thing, node->data) < 0){  // go find it on left
      remove(node->left, thing);
      node->size = node->size -1;
    }else{ // go find it on right
      remove(node->right, thing);
      node->size = node->size -1;
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
  
  void insertMid(Node<T>* node, T* array, unsigned int low, unsigned int high,
      unsigned int max){
    if(low > high){
      return;
    }
    if(max < high){
      cout << "max error!\n";
      return;
    }
    if(max <= low){
      cout << "low error!\n";
      return;
    }
    if(low == high){
      insert(node, array[low], 0, false); // Don't allow a rebalance
      return;
    }
    if(high - low == 1){
      insertMid(node, array, low, low, max);
      insertMid(node, array, high, high, max);
      return;
    }
    unsigned int mid = (high - low) / 2 + low + 1;
    insertMid(node, array, mid, mid, max);
    insertMid(node, array, low, mid-1, max);
    insertMid(node, array, mid+1, high, max);
  }
  
  void rebuild(Node<T>* node){
    if(!node){
      return;
    }
    // Will completely rebuild the subtree into a complete tree
    unsigned int arr_size = node->size;
    T* array = new T[arr_size];
    // Walk the tree and insert into array
    unsigned int pos = 0;
    fillInArray(node, array, &pos, arr_size);
    // We can't clear node because something points to it
    // So clear it's left and right
    // Then set it's data to the first element in the array
    clear(node->left);
    clear(node->right);
    node->left = NULL;
    node->right = NULL;  // Don't touch parent pointer!
    node->size = 1;   // insert will update in the future.
    // size should also be good
    // Fix the sub-head node
    if(arr_size > 0){
      node->data = array[arr_size /2];
    }
    // Shift all the numbers up so that half one isn't there.
    for(int i = arr_size/2; i > 0; i--){
      array[i] = array[i-1];
    }
    // Now go to town!
    insertMid(node, array, 1, arr_size-1, arr_size);
    delete[] array;
  }
  
};




#endif
