/*
	Rational and complex driver file.
	Paul Talaga
	August 2015
*/

// This file is to let you play with the Rational and Complex
// class.  All grading will be done in Rational_test.h and Complex_test.h.
#include <string>
#include <iostream>

#include "Rational.h"
#include "Complex.h"

using namespace std;


int main(){

  Rational a(1,2);
  
  cout << a - (a * 2)<< endl;
  
  //cout << Rational(1,6) / Rational(3,0) << endl;
  
  //Complex b(1,1);
  //cout << b << endl;
  
  return 0;
}
