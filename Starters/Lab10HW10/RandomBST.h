#ifndef RandomBST_H
#define RandomBST_H

/*
   Random Binary Search Tree class.
   This will rebuild the entire tree every RANDOMIZATION_OPERATIONS 
   of inserts or deletes.
   Paul Talaga
   October 2015
 */
#include <ostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <stdlib.h>

// Set to -1 to disable randomization, otherwise the tree will get rebuilt every
// RANDOMIZATION_OPERATIONS inserts or deletes.
const int RANDOMIZATION_OPERATIONS = 10;

using namespace std;

template <class T>
void permute(T* array, unsigned int size){
  if(size == 0){
    return;
  }
  // Using Fisher-Yates shuffle
  for(unsigned int i = size -1; i > 1; i--){
      int j = rand() % i;
      T temp = array[i];
      array[i] = array[j];
      array[j] = temp; 
    }
}

template <class T>
class Node{
public: Node(Node* parent, Node* left, Node* right, T value)
  :data(value),left(left),right(right),parent(parent){}
  T data;
  Node* left;
  Node* right;
  Node* parent;
};

template <class T>
class RandomBST {

public:
  RandomBST( int (*f)(const T&, const T&) ){
    cmpfn = f;
    root = NULL;
    modification_steps = 0;
  }

  ~RandomBST() {
    clear();
  }

  RandomBST(const RandomBST& other){
    cmpfn = other.cmpfn;
    modification_steps = 0;
    root = replicateFast(other.root);
  }
	
	// Similar to copy constructor, but check for self
	// assignment, if not, clear and copy all data.
  RandomBST<T>& operator= (const RandomBST& other){  
		if(this == &other){
			return *this;
		}
		cmpfn = other.cmpfn;
  	clear();
		root = replicateFast(other.root);
		return *this;
	}
  
  void insert(T thing){
    modification_steps++;
    if(RANDOMIZATION_OPERATIONS != -1 &&  
        modification_steps > RANDOMIZATION_OPERATIONS){
      rebuild();
    };
    // Note insert will handle root if not assigned yet.
    insert(root, thing);
  }
  
  bool find(const T& thing) const{
    return find(root, thing);
  }

  unsigned int size() const{
    //return the_size;
    return size(root);
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
    modification_steps++;
    if(RANDOMIZATION_OPERATIONS != -1 &&  
        modification_steps > RANDOMIZATION_OPERATIONS){
      rebuild();
    };
    remove(root, thing);
  }
  
  bool verifyParents() const{
    return verifyParents(root);
  }
  
  void rebuild(){
    rebuild(root);
    modification_steps = 0;
  }
  
  
private:
  Node<T>* root;
  int (*cmpfn)(const T& left, const T& right);
  unsigned int modification_steps;
  
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
    }
  }
  
  // Private insert that takes a node
  void insert(Node<T>* node, T thing){
    // Is this the first insert?
    if(node == NULL && root == NULL){
      root = new Node<T>(NULL,NULL,NULL,thing);
      return;
    }else if(node == NULL){
      // Something went wrong!
      throw logic_error("Internal insert error");
    }
    int dir = (*cmpfn)(thing, node->data);
    if(dir <= 0){ // go left
      if(node->left){
        return insert(node->left, thing);
      }else{
        node->right = new Node<T>(node, NULL,NULL,thing);
      }
    }else{ // go right
      if(node->right){
        return insert(node->right, thing);
      }else{
        node->right = new Node<T>(node, NULL,NULL,thing);
      }
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
      return find(node->right, thing);
    };
  }
  
  string getInOrder(Node<T>* node) const{
    if(node == NULL){
      return "";
    }
    string ret;
    if(node->right){
      ret = getInOrder(node->right) + ", ";
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
  
  unsigned int size(Node<T>* node) const{
    if(node == NULL){
      return 1;
    }else{
      return 1 + size(node->left) + size(node->right);
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
    return abs(left - right) <= 1 ||
      isBalanced(node->left) ||
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
      throw logic_error("pos too large!");
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
    }else{ // go find it on right
      remove(node->right, thing);
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
  
  void rebuild(Node<T>* node){
    // Will completely rebuild the subtree using a random insertion order
    unsigned int arr_size = size(node);
    T* array = new T[arr_size];
    // Walk the tree and insert into array
    unsigned int pos = 0;
    fillInArray(node, array, &pos, arr_size);
    permute(array, arr_size);  // mess up the order
    // We can't clear node because something points to it
    // So clear it's left and right
    // Then set it's data to the first element in the array
    clear(node->left);
    clear(node->right);
    node->left = NULL;
    node->right = NULL;  // Don't touch parent!
    if(arr_size > 0){
      node->data = array[0];
    }
    // Now go to town!
    for(int i = 1; i < arr_size; i++){ // insert all back in
      insert(node,array[i]);
    }
    delete[] array;
  }
  
};




#endif
