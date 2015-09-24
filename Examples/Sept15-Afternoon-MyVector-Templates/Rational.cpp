/*
	Simple rational number class.
	Paul Talaga
	August 2015
*/
//#include <ostream>
#include <ostream>

#include "Rational.h"

using namespace std;

Rational::Rational(const int& top){
  numerator = top;
  denominator = 1;
}

Rational::Rational(const int& top,const int& bottom){
  numerator = top;
  denominator = bottom;
  simplify();
}

int Rational::getNumerator() const{
  return numerator;
}

int Rational::getDenominator() const{
  return denominator;
}

double Rational::getAsDouble() const{
  // Must convert BEFORE division otherwise integer division will occur
  return static_cast<double>(numerator) / static_cast<double>(denominator);
}

void Rational::simplify(){
  // We only allow the numerator to be negative, so flip both if both negative
  if(numerator < 0 && denominator < 0){
    numerator  = numerator * -1;
    denominator = denominator * -1;
  }

  // Divide top and bottom by greatest common divisor
  int the_gcd = gcd(numerator,denominator);
  numerator = numerator / the_gcd;
  denominator = denominator / the_gcd;

  // Denominator negative and numerator not?
  if(numerator > 0 && denominator < 0){
    numerator  = numerator * -1;
    denominator = denominator * -1;
  }
}

int Rational::gcd(int a, int b){
  if(b == 0){
    return a;
  }else{
    return gcd(b, a % b);
  }
}

/*
Care must be taken when dealing with auto-type conversion that you don't
allow the compiler to have a choice in which way to convert.  Allowing the
following double converter poses many problems when also overloading +,-,* as
many statements could be interpreted in a few ways, causing compilation issues.
Thus, this is commented out to make the examples work.
Rational::operator double(){
  // Must convert BEFORE division otherwise integer division will occur
  return static_cast<double>(numerator) / static_cast<double>(denominator);
}
*/

Rational Rational::operator+ (const Rational& right){
  // We need to find a common denominator before we add
  int common_denom = denominator * right.getDenominator();
  int left_common_num = numerator * right.getDenominator();
  int right_common_num = right.getNumerator() * denominator;
  Rational ret(left_common_num + right_common_num, common_denom);
  ret.simplify();
  return ret;
}

Rational Rational::operator- (const Rational& right){
  // We need to find a common denominator before we subtract
  int common_denom = denominator * right.getDenominator();
  int left_common_num = numerator * right.getDenominator();
  int right_common_num = right.getNumerator() * denominator;
  Rational ret(left_common_num - right_common_num, common_denom);
  ret.simplify();
  return ret;
}

Rational Rational::operator* (const Rational& right){
  Rational ret(numerator * right.getNumerator(),
     denominator * right.getDenominator());
  ret.simplify();
  return ret;
}


bool Rational::operator< (const Rational& right){
  return compare(right) < 0;
}

bool Rational::operator<= (const Rational& right){
  return compare(right) <=0;
}

bool Rational::operator> (const Rational& right){
  return compare(right) > 0;
}

bool Rational::operator>= (const Rational& right){
  return compare(right) >= 0;
}

bool Rational::operator== (const Rational& right){
  return compare(right) == 0;
}

bool Rational::operator!= (const Rational& right){
  return compare(right) != 0;
}
  
// Returns 0 if the same, negative if the first is less, 
// positive if the first is greater
int Rational::compare(const Rational& right){
  // We need to find a common denominator before we compare
  int left_common_num = numerator * right.getDenominator();
  int right_common_num = right.getNumerator() * denominator;
  return left_common_num - right_common_num;
}

ostream& operator<< (ostream& out, const Rational& thing){
  out << thing.getNumerator() << "/" << thing.getDenominator();
  return out;
}

