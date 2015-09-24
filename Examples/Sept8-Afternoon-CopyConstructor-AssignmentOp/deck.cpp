
#include <string>
#include <iostream>
#include <vector>
#include "Card.h"

using namespace std;

const long NUM_CARDS = 4; 

void changeCard(Card& a){
  *(a.number) = 12;
}

void changeCard2(Card a){
  *(a.number) = 12;
}

int main(){
  
  Card a = Card(5, "Hearts");
  
  Card b = Card(10, "Diamonds");
  b = a;
  a = a;
  
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
 
 
  changeCard(a);
  
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
}
