#include <iostream>
#include <ctime>
#include <stack>
#include <vector>

using namespace std;

int main(){
  
  for(int j = 0; j < 10000; j++){
  
    stack<int> test;
    clock_t start = clock();
    for(int i = 0 ; i < j; i++){
      test.push(i);
    }
    clock_t end = clock();
    
    vector<int> test2;
    clock_t startv = clock();
    for(int i = 0 ; i < j; i++){
      test2.push_back(i);
    }
    clock_t endv = clock();
    
    cout << j << '\t' << (float)(end - start) / (float)CLOCKS_PER_SEC / (float) j;
    cout  << '\t' << (float)(endv - startv) / (float)CLOCKS_PER_SEC / (float) j;
    
    cout << endl;
    
  }

};
