#ifndef COMPLEX_H
#define COMPLEX_H


using namespace std;


class Complex{

  public:
  // No default constructor since a complex with no values doesn't make sense
  Complex(const double& left);     // Will have 0 complex
  Complex(const double& left, const double& right);
  
  // Fill in the rest of the interface file here!
  double getReal() const;
  double getImaginary() const;
  
  Complex operator+ (const Complex& rightside);
  Complex operator- (const Complex& rightside);
  Complex operator* (const Complex& rightside);
  
  bool operator== (const Complex& rightside);
  bool operator!= (const Complex& rightside);
  
  int compare(const Complex& rightside);
  
  Complex conjugate() const;
  
  private:
  
  double real;
  double imaginary;
  
};

ostream& operator<< (ostream&out, const Complex& thing);
#endif
