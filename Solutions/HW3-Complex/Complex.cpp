
#include <ostream>
#include <cmath>

#include "Complex.h"

using namespace std;


Complex::Complex(const double& left){
  real = left;
  imaginary = 0;
}

Complex::Complex(const double& left,const double& right){
  real = left;
  imaginary = right;
}


double Complex::getReal() const{
  return real;
}

double Complex::getImaginary() const{
  return imaginary;
}

Complex Complex::operator+ (const Complex& rightside){
  Complex ret(real + rightside.getReal(), imaginary + rightside.getImaginary());
  return ret;
}

Complex Complex::operator- (const Complex& rightside){
  Complex ret(real - rightside.getReal(), imaginary - rightside.getImaginary());
  return ret;
}

Complex Complex::operator* (const Complex& rightside){
  double first = (real * rightside.getReal()) - (imaginary * rightside.getImaginary());
  double second = (imaginary * rightside.getReal()) + (real * rightside.getImaginary());
  Complex ret(first, second);
  return ret;
}

bool Complex::operator== (const Complex& rightside){
  double reallow = real - 0.001;
  double realhigh = real + 0.001;
  double imaginarylow = imaginary - 0.001;
  double imaginaryhigh = imaginary + 0.001;
  if((rightside.getReal() >= reallow && rightside.getReal() <= realhigh) && (rightside.getImaginary() >= imaginarylow && rightside.getImaginary() <= imaginaryhigh)){
    return true;
  }
  return false;
}

bool Complex::operator!= (const Complex& rightside){
  return !(*this == rightside);
}


Complex Complex::conjugate() const{
  Complex ret(real, -1 * imaginary);
  return ret;
}
 

ostream& operator<< (ostream& out, const Complex& thing){
  out << "(" << thing.getReal() << "+" << thing.getImaginary() << "i"<< ")" << endl;
  return out;
}

