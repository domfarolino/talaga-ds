#include <iostream>

#include "Linked.h"

using namespace std;

int main(){
  Linked mylist;
  
  mylist.push_back("problem");
  
  mylist.push_front("pizza");
  cout << "size: " << mylist.size() << endl;
  mylist.push_front("My");
  cout << "size: " << mylist.size() << endl;
  mylist.push_back("is");
  mylist.push_back("yummy!");
  cout << "size: " << mylist.size() << endl;
  
  mylist.print();
  
  mylist.remove(0);
  
  mylist.print();
}
