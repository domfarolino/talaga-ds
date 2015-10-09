#ifndef DECK_TEST_H
#define DECK_TEST_H

#include "deck.h"
#include "card.h"
#include <set>

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

bool comp(const Card& a, const Card& b){
  if( a.getSuit() < b.getSuit()){
    return true;
  }else if(a.getSuit() > b.getSuit()){
    return false;
  }else if(a.getRank() < b.getRank()){
    return true;
  }else{
    return false;
  }
}

bool operator==(const Card& a, const Card& b){
  return a.getSuit() == b.getSuit() && a.getRank() == b.getRank();
}

int myfind(const vector<Card>& v, const Card& thing){
  for(unsigned int i = 0; i < v.size(); i++){
    if( v[i] == thing){
      return (int) i;
    }
  }
  return -1;
}

class DeckSize : public CxxTest::TestSuite {  
public:
  
  void testDeckSize() {
    Deck a;
    TS_ASSERT_EQUALS(a.size(), 52);
  }
  
  void testDeckSize2() {
    Deck a;
    for(int i = 0; i < 52; i++){
      a.getTopCard();
    }
    TS_ASSERT_EQUALS(a.size(), 0);
  }
};
class DeckUnique : public CxxTest::TestSuite {  
public:
  
  void testDeckUnique() {
    Deck a;
    set<Card, bool(*)(const Card& a, const Card& b)> s(&comp);
    for(int i = 0; i < 52; i++){
      Card card = a.getTopCard();
      TS_ASSERT_EQUALS(s.count(card), 0);
      s.insert(card);
    }
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_EQUALS(s.size(), 52);
  }
  
  void ttestDeckRandom(){
    Deck a;
    Deck b;
    int num_same = 0;
    for(int i = 0; i < 52; i++){
      if(a.getTopCard() == b.getTopCard()){
        num_same++;
      }
    }
    //cout << num_same << endl;
    TS_ASSERT(num_same < 52);
  }
};

class DeckTestDistribution : public CxxTest::TestSuite {  
public:
  void testDeckRandom2(){
    srand(time(0));
    // Create a bunch of decks and check the position of each card in 
    // all of them.
    vector<vector<Card>* > cards;
    for(int i = 0; i < 10000; i++){
      Deck a;
      vector<Card>* v = new vector<Card>;
      while(a.size() > 0){
        v->push_back(a.getTopCard());
      }
      cards.push_back(v);
    }
    // Now take the first vector's cards and search all the other
    // vectors for where they are
    vector<Card>* ref = cards[0];
    
    for(unsigned int i = 0; i < ref->size(); i++){
      Card c = ref->at(i);
      int pos = 0;
      for(unsigned int j = 0; j < cards.size(); j++){
        pos += myfind(* (cards[j]), c);
      }
      //cout << pos << endl;
      TS_ASSERT_DELTA(pos, 51/2 * 10000, 20000);  //51/2 * 10000;
    } 
    // Return all memory
    for(uint i = 0; i < cards.size(); i++){
      delete cards[i];
    }
   
  }
  
};


#endif
