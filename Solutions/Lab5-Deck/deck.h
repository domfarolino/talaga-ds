#ifndef DECK_H
#define DECK_H


#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <stack>
#include <vector>

#include "card.h"

using namespace std;

class Deck{
  public:
  Deck(){
       
    for(int i = 1; i <= 13; i++){
    d.push(Card(CLUBS,i));
    d.push(Card(DIAMONDS,i));
    d.push(Card(SPADES,i));
    d.push(Card(HEARTS,i));
    }
    shuffle();
  }
 
  Card getTopCard(){
    
    Card top = d.top();
    d.pop();
    return top;
    return Card(SPADES, 5);
  }
 
  void shuffle(){
    int s = d.size();
    vector<Card> v;
   
    for(int i = 0; i < s; i++){
    
      v.push_back(d.top());
      d.pop();
    }
   
    int tempSpot;
    Card tempCard = Card(CLUBS,1);
   
    for(int i = 0; i < s; i++){
    
    tempSpot = (i + rand()%(s-i));
    tempCard = v[i];
    v[i] = v[tempSpot];
    v[tempSpot] = tempCard;
    
    }
   
    for(int i = 0; i < s; i++){
    d.push(v[i]);
    }
  }
 
  unsigned int size() const{
    return d.size();
    return 0;
  }
 
 
  private:
  stack<Card> d;    
  unsigned int num_cards;
 

};

#endif

