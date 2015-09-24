
#include <string>
#include <ostream>
#include <vector>

using namespace std;

class Card{
  public:
  
  Card();
  
  Card(int number, string suit);
  
  Card(const Card& other);
  
  ~Card();
  
  // Getters
  string getSuit() const;
  int getNumber() const;
  
  Card operator+ (const Card& right);
  Card& operator=(const Card& right);
  
  //private:
  
  int* number;
  string* suit;
  
};

ostream& operator<< (ostream& out, const Card& thing);

