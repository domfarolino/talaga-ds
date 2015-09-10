#ifndef CARD_H
#define CARD_H
#include <string>

using namespace std;

class Card{
  public:
  
  Card();
  
  Card(int number, string suit);
  
  Card(const Card& other);
  
  ~Card();
  
  Card operator=(const Card* rhs);
  
  // Getters
  string getSuit() const;
  int getNumber() const;
  
  //private:
  
  int* number;
  string* suit;
  
};

ostream& operator<<(ostream& out, const Card& thing);

#endif
