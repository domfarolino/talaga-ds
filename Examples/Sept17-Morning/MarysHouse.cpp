#include <iostream>
#include <vector>
#include "Animals.h"

using namespace std;

int main(){

  vector<Animal*> animalList;
  
  Cat a(400, "Pizza", "red");
  
  animalList.push_back( new Dog(56, "bob") );
  animalList.push_back( new Cat(5, "Jim", "purple") );
  animalList.push_back( new Cat(6, "Beyonce", "lime green") );
  animalList.push_back( &a );


  
  
  for(unsigned int i = 0; i < animalList.size(); i++){
    cout << endl<< animalList[i]->getType() << endl;
    cout << animalList[i]->getName() << endl;
    cout << animalList[i]->getColor() << endl;
    cout << animalList[i]->getWeight() << endl;
    cout << animalList[i]->landSpeed() << endl;
  }
  
  
  return 0;
}
