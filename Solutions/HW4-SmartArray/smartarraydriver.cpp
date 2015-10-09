/*
	SmartArray driver file.
	Paul Talaga
	August 2015
*/

// This file is to let you play with the SmartArray
// class.  All grading will be done in SmartArray.h and SmartArray_hw_test.h
#include <string>
#include <iostream>

#include "SmartArray.h"

using namespace std;


int main(){

  SmartArray<int> a;
  
  cout << a << endl;
  
  a.push_back(5);
  cout << a << endl;
  
  a.push_back(10);
  cout << a << endl;
  
  cout << "size: " << a.size() << endl;
  
  cout << "back(): " << a.back() << endl;
  
  SmartArray<float> b(11, 6.6);
  
  cout << b << endl;
  cout << "size(): " << b.size() << endl;
  
  b.pop_back();
  b.pop_back();
  
  cout << b << endl;
  cout << "size(): " << b.size() << endl;
}
