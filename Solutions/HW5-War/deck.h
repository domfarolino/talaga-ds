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
    // Fill in a temporary array with cards
    num_cards = 52;
    Card* tempDeck[num_cards];  // An array of pointers
    unsigned int i = 0;
    for(int suit = 0; suit <4; suit++){
      for(unsigned int rank = 1; rank <=13; rank++){
        tempDeck[i] = new Card((suit_t)suit,rank);
        i++;
      }
    } 
    // Initialize random number generator
    
    // Using Fisher-Yates shuffle
    for(unsigned int i = num_cards -1; i > 1; i--){
      int j = rand() % i;
      Card* temp = tempDeck[i];
      tempDeck[i] = tempDeck[j];
      tempDeck[j] = temp; 
    }
    // Push them all on a stack
    for(unsigned int i = 0; i < 52; i++){
      // Push card onto a stack
      d.push(*tempDeck[i]);
      // We can return the heap memory used now
      delete tempDeck[i];
      tempDeck[i] = NULL;
    }
  }
  
  Card getTopCard(){
    if(d.size() == 0){
      throw logic_error("Deck Empty");
    }
    Card ret = d.top();
    d.pop();
    return ret;
  }
  
  unsigned int size() const{
    return d.size();
  }
  
  
  private:
  stack<Card> d;
  unsigned int num_cards;
  

};

#endif
