
#include <string>
#include <iostream>
#include <vector>
#include "Card.h"

using namespace std;

int main(){
  vector<Card*> deck;
  
  string suits[4];
  suits[0] = "Diamonds";
  suits[1] = "Clubs";
  suits[2] = "Spades";
  suits[3] = "Hearts";
  
  for(int i = 0; i < 52; i++){
    deck.push_back(new Card( i % 13, suits[i / 13]) );
  }
  
  for(unsigned int i = 0; i < deck.size(); i++){
    cout << i << " " << " " << deck[i]->getNumber();
    cout  << " " << deck[i]->getSuit() << endl;
  }
}
