#include <iostream>

using namespace std;

int main(){
  int a = 5;
  cout << "hi: " << ++a <<  endl;
  cout << "a: " << a << endl;
  cout << "ho: " << (++a)++ <<  endl;
  cout << "a: " << a << endl;
  if( a = 5){
    cout << "Oh no\n";
  }
}
