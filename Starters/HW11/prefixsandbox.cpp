/*
	Prefix Tree Sandbox
	Paul Talaga
	November 2015
*/

#include <string>
#include <iostream>

#include "Prefix.h"

using namespace std;

int main(int argc, char* argv[]){
  Prefix a;
  a.insert("hi");
  a.insert("nothing can come");
  a.insert("apple pie");
  a.insert("abc is a good song!");

  vector<string> all = a.getAllStored();
  cout << "size: " << all.size() << endl;
  for(unsigned int i = 0; i < all.size(); i++){
    cout << i << ":" << all[i] << endl;
  }
  cout << "----\n";
  vector<string> all2 = a.getWPrefix("a");
  cout << "size: " << all2.size() << endl;
  for(unsigned int i = 0; i < all2.size(); i++){
    cout << i << ":" << all2[i] << endl;
  }
  cout << "num: " << a.getNumStored() << endl;
}
