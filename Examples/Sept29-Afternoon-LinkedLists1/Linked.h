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
      to_delete = NULL;
    }
    head = NULL;
 }
 
 void clear(){
  clear(head);
  delete head;
 }
 
 void clear(node_t* n){
  if(n->next == NULL){
    delete n;
  }else{
    clear(n->next);
    delete n;
  }
 }

 void push_front(string thing){
  node_t* temp = new node_t;
  temp->value = thing;
  temp->next = head;
  head = temp;
 }
 
 void push_back(string thing){
  if(head == NULL){
    head = new node_t;
    head->next = NULL;
    head->value = thing;
    return;
  }
  node_t* temp = head;
  while(temp->next){  // Assumes temp is not null
    temp = temp->next;
  }
  // temp is the last node
  node_t* new_node = new node_t;
  new_node->value = thing;
  new_node->next = NULL;
  temp->next = new_node;
 }
 
 void print(){
  node_t* temp = head;
  int i = 0;
  cout << "[";
  while(temp){
    cout << i << ":" << temp->value << " " ;
    temp = temp->next;
    i++;
  }
  cout << "]\n";
 }
 
 int size(){
  node_t* temp = head;
  int i = 0;
  while(temp){
    temp = temp->next;
    i++;
  }
  return i;
 }
 
 void remove(int i){
  if(i == 0){
    node_t* to_delete = head;
    head = head->next;
    delete to_delete;
    return;
  }
  node_t* temp = head;
  while(temp && i > 1){
    temp = temp->next;
    i--;
  } // temp is the one before we want to delete
  node_t* to_delete = temp->next;
  temp->next = temp->next->next;
  delete to_delete;
  
  //cout << "delete: " << temp->value << endl;
 }
 
 
 
 
 
private:
  node_t* head;  
  
};

#endif
