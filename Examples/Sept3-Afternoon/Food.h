
#include <string>

using namespace std;

class Food{
  public:
  
  Food();
  Food(string name, int quality, int quantity, int calories);
  
  void setName(string name);
  void setQuality(int quality);
  void setQuantity(int quantity);
  void setCalories(int calories);
  
  // getters
  
  string getName();
  int getQuality();
  int getQuantity();
  int getCalories();
  
  int getCaloriesForUnits(int units);
  
  private:
  string name;
  int quantity;
  int calories;
  int quality;  // 0-10   0 being horrible, 10 excellent
};


