#ifndef DECK_H
#define DECK_H
/*
  The Deck class implements a random deck of 52 cards.
*/
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <stack>

#include "card.h"

using namespace std;

class Deck{
  public:
  Deck(){
    // Set up the instance so getTopCard can give out random cards from a deck.
  }
  
  Card getTopCard(){
    // Return the top card to the requestor.
    return Card(SPADES, 5);
  }
  
  unsigned int size() const{
    // Return the size of the rest of the deck.
    return 0;
  }
  
  
  private:
  stack<Card> d;    // Hint hint!
  unsigned int num_cards;
  

};

#endif
