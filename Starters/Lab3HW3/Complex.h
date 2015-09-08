#ifndef COMPLEX_H
#define COMPLEX_H

/*
	Simple complex number class.
	Paul Talaga
	August 2015
*/

using namespace std;

// Class to store and manipulate complex numbers.
class Complex{

  public:
  // No default constructor since a complex with no values doesn't make sense
  Complex(const double& real);     // Will have 0 complex
  Complex(const double& real, const double& complex);
  
  // Fill in the rest of the interface file here!

};
#endif
