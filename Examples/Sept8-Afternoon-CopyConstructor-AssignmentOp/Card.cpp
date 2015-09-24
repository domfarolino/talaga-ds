#include <string>
#include <iostream>
#include <ostream>
#include <vector>
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
  number = new int(*other.number);
  suit = new string(*other.suit);
}

Card& Card::operator=(const Card& other){
  if(this == &other){
    return *this;
  }
  delete number;
  delete suit;
  number = new int(*other.number);
  suit = new string(*other.suit);
  return *this;
}

Card::~Card(){
  //cout << "Destructor called " << *number << " " << *suit << "\n";
  return;
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

Card Card::operator+ (const Card& right){
  if(*(right.number) > *number){
    return right;
  }else{
    return *this;
  }
}




ostream& operator<< (ostream& out, const Card& thing){
  out << thing.getNumber() << " of " << thing.getSuit();
  return out;
}


