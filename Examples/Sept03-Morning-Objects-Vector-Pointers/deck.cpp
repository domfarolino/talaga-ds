
#include <string>
#include <iostream>
#include <vector>
#include "Card.h"

using namespace std;

const long NUM_CARDS = 10; //30000000;

int main(){

  
  
  

 vector<Card*> deck;
 // vector<Card> deck2;
  
  string* suits[4];
  suits[0] = new string("Diamonds");
  suits[1] = new string("Clubs");
  suits[2] = new string("Spades");
  suits[3] = new string("Hearts");
  
  string** temp = NULL;
  
  temp = suits;
  
  
  
  //temp[2] = new string("Stuff");
  //temp[1] = temp[2];
  
  for(int i = 0; i < 4; i++){
    cout << *temp[i] << endl;
  }
  
  
  for(int i = 0; i < 4; i++){
    delete suits[i];
  }
  return 0;
  
  //Card a[NUM_CARDS];
  
  /*for(unsigned int i = 0; i < NUM_CARDS; i++){
    if(i % 1000 == 0 && 0){
      cout << i << " " << " " << a[i].getNumber();
      cout  << " " << a[i].getSuit() << endl;
    }
  } */
  
  /*
  
  for(int i = 0; i < NUM_CARDS; i++){
    deck.push_back(new Card( i % 13, suits[(i / 13) % 4])  );
    //deck2.push_back(Card( i % 13, suits[(i / 13) % 4]) );
  }
  
  for(unsigned int i = 0; i < deck.size(); i++){
    //cout << i << " " << " " << deck[i]->getNumber();
    //cout  << " " << deck[i]->getSuit() << endl;
    if(deck[i]->getSuit().compare("Hearts") == 0 && i % 100 == 0){
      cout << i << " " << " " << deck[i]->getNumber();
      cout  << " " << deck[i]->getSuit() << endl;
    }
  }
  cout << "sizeof b (KB): " << NUM_CARDS / 1024 * sizeof(Card)  << endl;
  */
}
