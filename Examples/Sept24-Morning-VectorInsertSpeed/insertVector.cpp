#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>

using namespace std;

int main(){
  srand(time(0));

  for(int i = 10; i < 10000; i+= 5){ // i represents a size input
  
    vector<int> test;
    clock_t start = clock();
      for(int j = 0; j < i; j++){
        test.push_back(j);
      }
    clock_t end = clock();
    
    clock_t starttop = clock();
      for(int j = 0; j < i; j++){
        vector<int>::iterator it;
        it = test.begin() ;
        test.insert(it, 5);
        //it = test.top();
        //test.pop_back();
      }
    clock_t endtop = clock();
    
    
    
    
    float avg_push_time = (float)(end-start) * 1000.0 / (float)CLOCKS_PER_SEC / (float) i;
    //float avg_pop_time = (float)(endpop-startpop) * 1000.0 / (float)CLOCKS_PER_SEC / (float) i;
    float avg_top_time = (float)(endtop-starttop) * 1000.0 / (float)CLOCKS_PER_SEC / (float) i;
    //cout << i << '\t' << (float)(end-start) * 1000.0 / (float)CLOCKS_PER_SEC << endl; 
    cout << i << '\t' << avg_push_time;// << '\t' << avg_pop_time;
    cout << '\t' << avg_top_time;
    cout  << endl;
  }
}
