#ifndef RATIONAL_H
#define RATIONAL_H


#include <ostream>

using namespace std;


class Rational{

  public:
  // No default constructor since a rational with no value doesn't make sense
  Rational(const int& top);
  Rational(const int& top, const int& bottom);
  
  
     
  
  int getNumerator() const;
  int getDenominator() const;
  
  double getAsDouble() const;
  //operator double();
  
  void simplify();
  
  
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
