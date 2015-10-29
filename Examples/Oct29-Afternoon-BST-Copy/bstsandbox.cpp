/*
	Binary Search Tree Sandbox
	Paul Talaga
	October 2015
*/

#include <string>
#include <iostream>

#include "BST.h"

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
  BST<int> a(compare);
  a.insert(-42);
  a.insert(5);
  a.insert(6);
  /*a.insert(2);
  a.insert(15);
  a.insert(17);
  a.insert(3); */

  cout << a.getInOrder() << endl;
  cout << "a size: " << a.size() << endl;
  
  BST<int>b(a);
  b.insert(2);
  cout << "a: " << a.getInOrder() << endl;
  cout << "a size: " << a.size() << endl;
  cout << "b:" << b.getInOrder() << endl;
  cout << "b size: " << b.size() << endl;
  cout << "a height: " << a.getHeight() << endl;

}
