#include <iostream>

using namespace std;

long fib(int n){// current is the sum of the previous two terms
//  0 1 1 2 3 5 8 13 21 34 55 89 
  if(n == 0){
    return 0;
  }else if(n == 1){
    return 1;
  }
  return fib(n-1) + fib(n-2);
}

long fib(int l2, int l1, int goal){
  if( l1 < l2){  // l1 should never be less than l2, if it is, it overflowed
    cout << "overflow!\n";
  }
  if(goal == 0){
    return l2 ;
  }else{
    return fib( l1 , l1 + l2 , goal - 1 );
  }
}

int recurseLimit(int n){
  int i = 0;
  cout << n << endl;
  recurseLimit(n+1);
  return 5;
}


int main(){
  recurseLimit(0);  // Try compiling and running this with g++ -O3 to enable
                    // tail-recursive optimization.
  //cout << "fib : " << fib(15) << endl;
  //cout << "fib2: " << fib(0,1,45000) << endl;
  //cout << "fact: " << fact(55) << endl;
  
  
}
