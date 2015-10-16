/*
	Dictionary lookup program.
	Paul Talaga
	October 2015
*/

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "HashTable.h"

using namespace std;

// Good hash function for strings
unsigned int hash(const string& thing){
  unsigned int ret = 7;
  for(unsigned int i = 0; i < thing.length(); i++){
    ret = ret * 31 * thing[i];
    // 31 is the next prime above 26
  }
  return ret;
}


int main(int argc, char* argv[]){
  // Change me!
  // Example of how to pass a function to a function.
  // This will pass the above hash function to the class.
  HashTable<string> test(hash, 10);
  test.insert("bob");
  cout << "bob? " << test.find("bob") << endl;
  
  return 0;
}
