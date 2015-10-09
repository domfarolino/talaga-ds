#ifndef LLIST_H
#define LLIST_H

/*
	Linked List class that store integers, with iterator.
	Paul Talaga
	September 2015
*/
#include <ostream>
#include <stdexcept>

using namespace std;

template <class T>
struct node_t {
  T data;
  node_t* next;
};

// This implementation will use a head and tail pointers,
// allowing O(1) insertion on the front and end.
template <class T>
class LList{

  public:
  LList(){
    head = NULL;
    tail = NULL;
    the_size = 0;
  }
  
  ~LList(){
		clear();
	}
	
  LList(const LList& other){
    // Do the same as the default constructor
  	head = NULL;
		tail = NULL;
		the_size = 0;
		// Check if the other LList is empty
		if(other.head == NULL || other.tail == NULL){
			return;
		}
		// Not empty?  Iterate through the other list
		// and push_back on myself.
		node_t<T>* temp = other.head;
		while(temp){
			push_back(temp->data);
			temp = temp->next;
		}
  }
	
	// Similar to copy constructor, but check for self
	// assignment, if not, clear and copy all data.
  LList<T>& operator= (const LList& other){  
		if(this == &other){
			return *this;
		}
  	clear();
		if(other.head == NULL || other.tail == NULL){
			return *this;
		}
		node_t<T>* temp = other.head;
		while(temp){
			push_back(temp->data);
			temp = temp->next;
		}
		return *this;
	}
     
  T getAt(int pos) const{
		// Handle negatives
		if(pos < 0){
			pos = pos + the_size;	
		}
		if(pos < 0){
			throw logic_error("Index too negative");
		}
		// Walk down the list and decrement pos.
    node_t<T>* temp = head;
    while(temp != NULL && pos > 0){
      temp = temp->next;
      pos--;
    }
    // As long as we don't have a NULL temp, return
    // what was desired.
    if(pos == 0 && temp !=NULL){
      return temp->data;
    }
    throw logic_error("Index invalid");
  }

  unsigned int size() const{
    return the_size;
  }
 
  void push_back(T value){
    // Empty list?
    if(head == NULL || tail == NULL){
      push_front(value);
    }else{
      // Not empty.  Use my tail pointer to tack
      // on a last element.
      node_t<T>* temp = new node_t<T>;
      temp->data = value;
      temp->next = NULL;
      tail->next = temp;
      tail = temp;
      the_size++;
    }
  }
  void push_front(T value){
    // Empty list?
    if(head == NULL || tail == NULL){
      head = new node_t<T>;
      head->data = value;
      head->next = NULL;
      tail = head;
      the_size = 1;
    }else{// Not empty
      node_t<T>* temp = new node_t<T>;
      temp->data = value;
      temp->next = head;
      head = temp;
      the_size++;
    }
  }
	
	void setAt(T value, int pos){
		// Handle negatives
		if(pos < 0){
			pos = pos + the_size;	
		}
		if(pos < 0){
			throw logic_error("Index too negative");
		}
		node_t<T>* temp = head;
    while(temp != NULL && pos > 0){
      temp = temp->next;
      pos--;
    }
    // As long as I don't have a null pointer, assign.
    if(pos == 0 && temp !=NULL){
    	temp->data = value;
			return;
    }
    throw logic_error("Index invalid");
  }
	
	void remove(int pos){
		// Handle negatives
		if(pos < 0){
			pos = pos + the_size;	
		}
		if(pos < 0){
			throw logic_error("Index too negative");
		}
		if(pos >= the_size){
			throw logic_error("Index invalid");
		}
		// Removing the first and only element?
		if(pos == 0 and the_size == 1){
			delete head;
			head = NULL;
			tail = NULL;
			the_size = 0;
		}else if(pos == 0){ // First element when more than one?
			node_t<T>* temp = head;
			head = head->next;
			delete temp;
			the_size--;
			return;
		}else if(pos == the_size-1){ // Last element?
			node_t<T>* temp = head;
	    while(temp->next != tail ){
	      temp = temp->next;
	    }
			node_t<T>* to_delete = temp->next;
			tail = temp;
			temp->next = NULL;
			delete to_delete;
			the_size--;
		}else{ // In the middle, get the node before.
			// Need to get one before
			pos = pos - 1;
			node_t<T>* temp = head;
	    while(temp != NULL && pos > 0){
	      temp = temp->next;
	      pos--;
	    }
	    // Verify temp is valid before dereferencing.
	    if(pos == 0 && temp !=NULL){
	    	// Now delete the next element!
				node_t<T>* to_delete = temp->next;
				temp->next = to_delete->next;
				delete to_delete;
				the_size--;
				return;
	    }
	    throw logic_error("Index invalid");
		}
	}
	
	LList<T> reverse() const{
		// Step through this list and add to the front of ret.
		LList<T> ret;
		node_t<T>* temp = head;
		while(temp){
			ret.push_front(temp->data);
			temp = temp->next;
		}
		return ret;
	}
	
	LList<T> operator+(const LList<T>& other) const{
		// Step through this list and add to the end of ret.
		LList<T> ret;
		node_t<T>* temp = head;
		while(temp){
			ret.push_back(temp->data);
			temp = temp->next;
		}
		// Do the same for other
		temp = other.head;
		while(temp){
			ret.push_back(temp->data);
			temp = temp->next;
		}
		return ret;
	}
	
	bool operator==(const LList<T>& other) const{
	  // Sizes differ?
		if(the_size != other.the_size){
			return false;
		}
		// Now step through both lists and verify data
		node_t<T>* temp1 = head;
		node_t<T>* temp2 = other.head;
		while(temp1 && temp2){
			if(temp1->data != temp2->data){
				return false; // Why keep looking if we found an error?
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		// Did we pop out early because one is NULL?
		if(temp1 != temp2){ // Both should be null!
			return false;
		}
		return true;
	}
	
	bool operator!=(const LList<T>& other) const{
		return ! operator==(other);
	}
	
	void clear(){
		node_t<T>* last = head;
		while(head){
			head = head->next;
			delete last;
			last = head;
		}
		// Normaly you never want to change head or you'll orphan part
		// of the list, but in this case we are wiping the list,
		// so it is ok to so and saves us a variable.
		head = NULL;
		tail = NULL;
		the_size = 0;
	}
 
  
  private:
  node_t<T>* head;
  node_t<T>* tail;
  
  unsigned int the_size;
};

// Note this function is O(n^2) because getAt is O(n) and we are
// doing it n times.
template <class T>
ostream& operator<<(ostream& out, const LList<T> other){
	out << "[";
	for(unsigned int i = 1; i < other.size(); i++){
		out << other.getAt(i-1) << ", ";
	}
	if(other.size() > 0){
		out << other.getAt(-1);
	}
	out << "]";
	return out;
}


#endif
