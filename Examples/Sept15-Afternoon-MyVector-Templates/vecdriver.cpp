
#include <string>
#include <iostream>
#include <vector>
#include "MyVec-templated.h"
#include "Rational.h"
#include <cstdlib>

using namespace std;



int main(){
  
  MyVec<Rational*> a;
  
  for(int i = 0; i < 10; i++){
    a.push_back( (new Rational(rand() % 10)) );
  }
  
  for(int i = 0; i < a.size(); i++){
    cout << i << ":" << *(a.at(i)) << endl;
  }
  
  cout << "Vector: " << a << endl;

}
