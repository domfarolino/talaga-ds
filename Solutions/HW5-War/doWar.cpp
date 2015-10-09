#include <iostream>
#include <iomanip>

#include "deck.h"
#include "war.h"

using namespace std;

int main(){

  srand(time(0));

  
  unsigned int samples = 1000;
  unsigned int max_rounds = 1000;
  unsigned int rows = 50;
  
  unsigned long long avg = 0;
  int bucket_width = (max_rounds) / rows;
  
  // Bucket array
  int counts[rows];
  for(unsigned int i = 0; i < rows; i++){
    counts[i] = 0;
  }
  // Run war a bunch of times!
  for(unsigned int i = 0; i < samples; i++){
    int count = runWar(max_rounds-1);
    avg += count;
    if(count / bucket_width >= 50){
      cout << count << endl;
    }
    counts[count / bucket_width]++;
  }
  
  
  
  for(unsigned int i = 0; i < rows; i++){
    cout << setw(3) << i*bucket_width;
    cout << "-";
    cout << setw(3) << (i+1) * bucket_width - 1;
    cout << ":" ;
    cout << setw(3) << counts[i];
    cout << ":";
    for(int j = 0; j < counts[i]; j++){
      cout << "*";
    }
    cout << endl;
  } 
  cout << endl << "Average: " << (float)avg / (float)samples << endl;
  return 0;
}
