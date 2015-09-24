
#include <string>
#include <iostream>
#include <vector>
#include "Card.h"

using namespace std;

const long NUM_CARDS = 4; 

void chargeCard(Card a){
  *(a.number) = 12;
}

void chargeCard2(Card& a){
  *(a.number) = 12;
}

void chargeCard3(Card* a){
  *(a->number) = 12;
  //*((*a).number) = 12;
}

int main(){
  
  Card a = Card(5, "Hearts")  ;
  Card b = Card(8, "Diamonds");
  
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
 
  
  //chargeCard2(a);
  //chargeCard3(&a);
  a = a;
  
  //chargeCard2(a);
  
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  
 

}
