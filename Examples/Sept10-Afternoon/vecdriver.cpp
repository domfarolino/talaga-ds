
#include <string>
#include <iostream>
#include <vector>
#include "MyVec.h"
#include <cstdlib>

using namespace std;



int main(){
  
  MyVec a;
  
  for(int i = 0; i < 0; i++){
    a.push_back(rand() % 10);
  }
  
  for(int i = 0; i < a.size(); i++){
    cout << i << ":" << a.at(i) << endl;
  }
  
  cout << "Vector: " << a << endl;

}
