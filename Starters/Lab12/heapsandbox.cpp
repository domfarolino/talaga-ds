/*
	Heap Sandbox
	Paul Talaga
	November 2015
*/

#include <string>
#include <iostream>

#include "MaxHeap.h"

using namespace std;

int main(int argc, char* argv[]){
  MaxHeap<string> h;
  h.push("happy");
  h.push("birthday");
  h.push("everyone");
  
  while(h.size() > 0){
    cout << h.top() << endl;
    h.pop();
  }
}
