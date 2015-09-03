
#include <string>
#include <iostream>
#include <vector>
#include "Food.h"

using namespace std;

const long TABLE_SIZE = 600000;
const long TABLE_SIZE2 = 20000;
int main(){

/*
Food table[TABLE_SIZE];


for(unsigned int i = 0; i < TABLE_SIZE; i++){
  cout << "I: " << i << endl;
  if(i % 50 == 0){
    cout << table[i].getName() << endl;
  }
}
*/

vector<Food*> table;

for(unsigned int i = 0; i < TABLE_SIZE2; i++){
  if(i % 200 == 0){
    cout << "size (KB): " << i /1024 * sizeof(Food)<< endl;
  }
  table.push_back(new Food("Fruit Salad", 4, 1, 100));
}

//cout << "size (KB): " << sizeof(Food) * TABLE_SIZE / 1024<< endl;

cout << "size (KB): " << TABLE_SIZE2 /1024 * sizeof(Food)<< endl;

table[10] = table[50];

for(unsigned int i = 0; i < TABLE_SIZE2; i++){
  cout << "pre: " << table[i];
  delete table[i];
  table[i] = NULL;
  cout << " post: " << table[i] << endl;
  cout << table[i]->getName() << endl;
  //table[i] = NULL;
}

for(unsigned int i = 0; i < TABLE_SIZE2; i++){
  //delete table[i];
  cout << table[i]->getName() << endl;
}

return 0;
/*
  Food pizza("Pizza", 8, 1, 800);
  
  cout << pizza.getName() << endl;
  
  cout << "5 pizzas: " << pizza.getCaloriesForUnits(5) << endl;
  
  vector<Food*> table;
  table.push_back(new Food("Pasta", 6, 1, 500));
  table.push_back(new Food("Fruit Salad", 4, 1, 100));
  
  for(unsigned int i = 0; i < table.size(); i++){
    cout << table[i]->getName() << endl;
  }
  
  */
}
