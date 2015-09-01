#include <string>
#include "Card.h"

using namespace std;

  
Card::Card(int number, string suit){
  this->number = number; // Note
  this->suit = suit;
}
  
  // Getters
string Card::getSuit() const{
  return suit;
}

int Card::getNumber() const{
  return number;
}

