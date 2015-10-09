#ifndef WAR_H
#define WAR_H
/*
  This runWar function runs a game of war between 2 automated players
  and returns the number of rounds (both put a card down 
  once per round) until someone won.  An integer is given 
  as an upper limit to how many rounds a game can go on for.
*/
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <stack>
#include <queue>

#include "deck.h"

using namespace std;

int runWar(unsigned int limit){
  // Get a deck of cards
  Deck d;
  // Deal cards to 2 players
  queue<Card> p1;
  queue<Card> p2;
  while(d.size() > 0){
    p1.push(d.getTopCard());
    p2.push(d.getTopCard());
  }
  //cout << p1.size() << endl;
  //cout << p2.size() << endl;
  
  stack<Card> war_pile;
  unsigned int rounds = 0;
  
  while(p1.size() > 1 && p2.size() > 1){
    // War pile status
    /*if( war_pile.size() > 0){
      cout << "War pile: " << war_pile.size() << endl;
    }*/
    
    Card c1 = p1.front();
    p1.pop();
    Card c2 = p2.front();
    p2.pop();
    //cout << p1.size() + p2.size() + war_pile.size() << " ";
    //cout << p1.size() << "-" << p2.size() << " " << c1 << " vs " << c2 << endl;
    if( numberCompare(c1, c2) > 0){
      // Player 1 had higher card, give both to P1
      p1.push(c1);
      p1.push(c2);
      while(war_pile.size() > 0){
        p1.push(war_pile.top());
        war_pile.pop();
      }
    }else if(numberCompare(c1, c2) < 0){
      // Player 2 had higher card, give both to P2
      p2.push(c1);
      p2.push(c2);
      while(war_pile.size() > 0){
        p2.push(war_pile.top());
        war_pile.pop();
      }
    }else{
      //cout << "war! \n";
      war_pile.push(c1);
      war_pile.push(c2);
      for(int i = 0; i < 3; i++){
        if(p1.size() > 0){
          war_pile.push(p1.front());
          p1.pop();
        }
        if(p2.size() > 0){
          war_pile.push(p2.front());
          p2.pop();
        }
      }
    }
    rounds++;
    if(rounds > limit){
      return limit;
    }
  }
  return rounds;
}

#endif
