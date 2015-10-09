#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>

using namespace std;

enum suit_t {DIAMONDS, SPADES, HEARTS, CLUBS};

class Card{
  public:
  
  Card(suit_t suit, unsigned int rank){
    // Rank is an unsigned int from 1 to 13, with Ace being
    // 13.  When printed, numbers are shifted up by 1.
    this->suit = suit;
    if(rank < 1 || rank > 13){
      throw logic_error("Rank out of range!");
    }
    this->rank = rank;
  }
  
  // Getters
  suit_t getSuit() const{ return suit;}
  unsigned int getRank() const{ return rank;}
  
  // string variants
  
  string getSuitString() const{
    switch(suit){
      case DIAMONDS: return "Diamonds";
      case SPADES: return "Spades";
      case HEARTS: return "Hearts";
      case CLUBS: return "Clubs";
      default: return "Invalid suit!";
    }
  }
  
  string getRankString() const{
    switch(rank){
      case 10: return "Jack";
      case 11: return "Queen";
      case 12: return "King";
      case 13: return "Ace";
      default: { stringstream o;
        o << rank + 1;
        return o.str();
      }
    }
  }
  
  private:
  suit_t suit;
  unsigned int rank;
};

ostream& operator<< (ostream& out, const Card& card){
  out << card.getRankString() << " of " << card.getSuitString();
  return out;
}

#endif
