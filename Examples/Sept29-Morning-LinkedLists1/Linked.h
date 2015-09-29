#ifndef LINKED_H
#define LINKED_H

#include <iostream>
#include <string>

using namespace std;

struct node_t{
  string value;
  node_t* next;
};

// Linked list class to store strings
class Linked{
public:
  Linked(){
    head = NULL;
  }
  
  ~Linked(){
    node_t* temp = head;
    while(temp){
      node_t* to_delete = temp;
      temp = temp->next;
      delete to_delete;
    }
    head = NULL;
  }
  
  void push_front(string thing){
    node_t* temp = new node_t;
    temp->next = head;
    temp->value = thing;
    head = temp;
  }
  
  void push_back(string thing){
    // Is the list empty?
    if(head == NULL){
      //push_front(thing);  this will work fine ..or
      node_t* new_node = new node_t;
      new_node->value = thing;
      new_node->next = NULL;
      head = new_node;
      return;
    }
    node_t* temp = head;
    while(temp->next){
      temp = temp->next;
    }
    // temp is...... a valid node with a null next pointer
    node_t* new_node = new node_t;
    new_node->value = thing;
    new_node->next = NULL;
    temp->next = new_node;
  }
  
  void print(){
    cout << "[";
    node_t* temp = head;
    int i = 0;
    while(temp){
      cout << i << ":" << temp->value << " ";
      i++;
      temp = temp->next;
    }
    cout << "]\n";
  }
  
  void remove(int i){
    if(i >= size()){
      return;
    }
    if(i == 0){ // first element
      node_t* temp = head;
      head = head->next;
      delete temp;
      return;
    }
    node_t* temp = head;
    while(temp && i > 1){
      i--;
      temp = temp->next;
    }
    if(!temp){
      cout << "Bad index!\n";
      return;
    }
    node_t* to_delete = temp->next;
    temp->next = temp->next->next;
    delete to_delete;
    //cout << "to delete: " << temp->value << endl;
  }
  
  int size(){
    node_t* temp = head;
    int i = 0;
    while(temp){
      i++;
      temp = temp->next;
    }
    return i;
  }

private:
  node_t* head;  
  
};

#endif
