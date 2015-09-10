
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

const long MYSIZE = 50000000;

int main(){
  
  vector<int> a(MYSIZE);
  
  
  //a.resize(25);
  
  for(int i = 0; i < MYSIZE; i++){
    a[i] = (rand() % 50);
    //cout << "Capacity: " << a.capacity() << endl;
  }
 
  
  for(int i = 0; i < a.size(); i++){
    a[i] = a[(i * 50) % a.size() ];
    //a.at(i) = a.at((i * 50) % a.size());
    //cout << i << ": "<< a[i] << endl;
  }
  

}
