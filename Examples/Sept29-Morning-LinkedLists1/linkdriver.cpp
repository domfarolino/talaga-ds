#include <iostream>

#include "Linked.h"

using namespace std;

int main(){
  Linked mylist;
  
  mylist.push_back("My");
  cout << "size: " << mylist.size() << endl;
  mylist.push_front("cheese");
  cout << "size: " << mylist.size() << endl;
  mylist.push_front("gouda");
  cout << "size: " << mylist.size() << endl;
  mylist.push_back("is");
  cout << "size: " << mylist.size() << endl;
 
  mylist.print();
  
  mylist.remove(0);
  
  mylist.print();
  
  mylist.remove(0);
  
  mylist.print();
  
  mylist.remove(0);
  
  mylist.print();
  
  mylist.remove(0);
  
  mylist.print();
  
  mylist.remove(0);
  
  mylist.print();
}
