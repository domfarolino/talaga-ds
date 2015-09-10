#include <string>
#include <iostream>
#include "Card.h"

using namespace std;

Card::Card(){
  number = new int(7);
  suit = new string("Diamonds");
  //cout << "Default constructor called\n";
}
  
Card::Card(int number, string suit){
  this->number = new int(number);
  this->suit = new string(suit);
  //cout << "2 parameter constructor called\n";
}

Card::Card(const Card& other){
  number = new int( *(other.number) );
  suit = new string( *(other.suit));
} 

Card Card::operator=(const Card& rhs){
  if(this == &rhs){
    cout << "assigned to myself!\n";
    return *this;
  }
  delete number;
  number = NULL;
  delete suit;
  suit = NULL;
  number = new int( *(rhs.number) );
  suit = new string( *(rhs.suit));
  return *this; 
}

Card::~Card(){
  //cout << "Destructor called\n";
  delete number;
  number = NULL;
  delete suit;
  suit = NULL;
}
  
  // Getters
string Card::getSuit() const{
  return *suit;
}

int Card::getNumber() const{
  return *number;
}

ostream& operator<<(ostream& out, const Card& thing){
  out << thing.getNumber() << " of " << thing.getSuit() << endl;
  return out;
}
