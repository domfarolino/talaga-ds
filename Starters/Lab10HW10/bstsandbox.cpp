/*
	Binary Search Tree Sandbox
	Paul Talaga
	October 2015
*/

#include <string>
#include <iostream>

#include "Scapegoat.h"

using namespace std;

// Returns a negative number if right is greater than right, 0 if equal
// and a positive number if left is greater than right.
int compare(const int& left, const int& right){
  return left - right;
}

int compare(const string& left, const string& right){
  // The string class has a built-in compare function!
  return left.compare(right);
}


int main(int argc, char* argv[]){
  srand(time(0));
  Scapegoat<int> a(compare);
  for(int i = 0; i < 10; i++){
    a.insert(i);
    cout << "inserted: " << i << endl;
  }
  cout << a.getPreOrder() << endl;
  cout << "size: " << a.size() << endl;
  
  a.remove(4);
  cout << a.getPreOrder() << endl;
  cout << a.verifyParents() << endl;
}
