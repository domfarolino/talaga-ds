#ifndef RATIONAL_H
#define RATIONAL_H

/*
	Simple rational number class.
	Paul Talaga
	August 2015
*/
#include <ostream>

using namespace std;

// Class to store and manipulate rational numbers.
class Rational{

  public:
  // No default constructor since a rational with no value doesn't make sense
  Rational(const int& top);
  Rational(const int& top, const int& bottom);
  
  // No copy constructor or destructor needed because no dynamic memory
  // is used.
     
  // Getters
  int getNumerator() const;
  int getDenominator() const;
  
  double getAsDouble() const;
  //operator double();
  
  void simplify();
  
  // Operators
  Rational operator+ (const Rational& right);
  Rational operator- (const Rational& right);
  Rational operator* (const Rational& right);
  Rational operator/ (const Rational& right);  // For lab
  
  bool operator< (const Rational& right);
  bool operator<= (const Rational& right);
  bool operator> (const Rational& right);
  bool operator>= (const Rational& right); 
  bool operator== (const Rational& right);
  bool operator!= (const Rational& right);
  
  int compare(const Rational& right);
  
  private:
  int numerator;
  int denominator; 
  
  int gcd(int a, int b);
  
};

ostream& operator<< (ostream& out, const Rational& thing);


#endif
