
#include <string>
#include <iostream>
#include <vector>
#include "Food.h"

using namespace std;

int main(){
  Food pizza("Pizza", 8, 1, 800);
  
  cout << pizza.getName() << endl;
  
  cout << "5 pizzas: " << pizza.getCaloriesForUnits(5) << endl;
  
  vector<Food*> table;
  table.push_back(new Food("Pasta", 6, 1, 500));
  table.push_back(new Food("Fruit Salad", 4, 1, 100));
  
  for(unsigned int i = 0; i < table.size(); i++){
    cout << table[i]->getName() << endl;
  }
}
