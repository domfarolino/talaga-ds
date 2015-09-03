#include <string>
#include "Food.h"

using namespace std;

Food::Food(){
  name = "Pizza";
  quality = 10;
  quantity = 1;
  calories = 4000000;
}

Food::Food(string name, int quality, int quantity, int calories){
  this->name = name;
  this->quality = quality;
  this->quantity = quantity;
  this->calories = calories;
}

void Food::setName(string name){
  name = name;
}

string Food::getName(){
  return name;
}

int Food::getCaloriesForUnits(int units){
  return units  * calories / quantity;
}
