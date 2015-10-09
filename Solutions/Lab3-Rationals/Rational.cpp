
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
  //   if not  integer division will occur
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



Rational Rational::operator+ (const Rational& right){
  
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


//TODO impliment division
Rational Rational::operator/ (const Rational& right){
	if (denominator == 0 || right.getNumerator() == 0){
		return Rational(0,1);
	}
	else{
		Rational ret(numerator * right.getDenominator(),
		denominator * right.getNumerator());
	  ret.simplify();
	  return ret;
	}
//  return ret;
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

