#include <iostream>

using namespace std;

long fib(int n){// current is the sum of the previous two terms
//  0 1 1 2 3 5 8 13 21 34 55 
  if(n == 0){
    return 0;
  }else if(n == 1){
    return 1;
  }
  return fib(n-1) + fib(n-2);
}


int recurseLimit(int n){
  int a = 5;
  cout << n << endl;
  recurseLimit(n+1);
  int b = a;
  return b * n;
}

long fib2(int l2, int l1, int goal){
  if(goal == 0){
    return l2;
  }
  return fib2(l1, l1 + l2, goal -1);
}

long fact(long i){
// 
  if(i <=1){
    return 1;
  }else{
    return i * fact(i-1);
  }
}

int main(){
  recurseLimit(0);
  //cout << "fib : " << fib(10) << endl;
  //cout << "fib2: " << fib2(0,1,50) << endl;
  //cout << "fact: " << fact(55) << endl;
  
  
}
