#include <string>
#include <iostream>

using namespace std;

unsigned long long factorial(unsigned long long i){
  if(i <= 1){
    return 1;
  }
  return i * factorial(i-1);
}

unsigned long long factorial2(unsigned long long i){
  unsigned long long ret = 1;
  for(int j = i; j > 1; j--){
    ret = ret * j;
  }
  return ret;
}

unsigned long long fib(unsigned long long i){
  if(i == 0){
    return 0;
  }else if(i == 1){
    return 1;
  }
  return fib(i-1) + fib(i-2);
}


int main(){
  cout << "unsigned long: " << sizeof(unsigned long long) << endl;
  cout << factorial(45) << endl;
  cout << factorial2(45) << endl;
}
