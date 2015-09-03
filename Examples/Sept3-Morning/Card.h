
#include <string>

using namespace std;

class Card{
  public:
  
  Card();
  
  Card(int number, string suit);
  
  // Getters
  string getSuit() const;
  int getNumber() const;
  
  private:
  
  int number;
  string suit;
  
};
