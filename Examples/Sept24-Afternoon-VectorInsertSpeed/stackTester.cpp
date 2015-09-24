#include <iostream>
#include <ctime>
#include <stack>

using namespace std;

int main(){

  for(int i = 10; i < 10000; i++){ // i represents a size input
  
    stack<int> test;
    clock_t start = clock();
      for(int j = 0; j < i; j++){
        test.push(j);
      }
    clock_t end = clock();
    
    clock_t starttop = clock();
      for(int j = 0; j < i; j++){
        test.top();
      }
    clock_t endtop = clock();
    
    clock_t startpop = clock();
      for(int j = 0; j < i; j++){
        test.pop();
      }
    clock_t endpop = clock();
    
    
    
    
    float avg_push_time = (float)(end-start) * 1000.0 / (float)CLOCKS_PER_SEC / (float) i;
    float avg_pop_time = (float)(endpop-startpop) * 1000.0 / (float)CLOCKS_PER_SEC / (float) i;
    float avg_top_time = (float)(endtop-starttop) * 1000.0 / (float)CLOCKS_PER_SEC / (float) i;
    //cout << i << '\t' << (float)(end-start) * 1000.0 / (float)CLOCKS_PER_SEC << endl; 
    cout << i << '\t' << avg_push_time << '\t' << avg_pop_time;
    cout << '\t' << avg_top_time << endl;
  }
}
