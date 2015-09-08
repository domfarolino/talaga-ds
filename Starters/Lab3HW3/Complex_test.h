#ifndef COMPLEX_TEST_H
#define COMPLEX_TEST_H

#include <Complex.h>

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

const double delta = 0.0001;
// Multiple test classes are used so groups of functions can be tested
// independently.
class ComplexGetters : public CxxTest::TestSuite {  
public:
  void testGetReal1(){
    //TS_ASSERT_DELTA(Complex(5,5).getReal(), 5, delta);
  }
  
  // TODO: Add unit tests here
};

class ComplexAdd : public CxxTest::TestSuite {  
public:

  // TODO: Add unit tests here
  
};

class ComplexSub : public CxxTest::TestSuite {  
public:
  
  // TODO: Add unit tests here
  
};

class ComplexMult : public CxxTest::TestSuite {  
public:
  
  // TODO: Add unit tests here
  
};

class ComplexEquality : public CxxTest::TestSuite {  
public:
  
  // TODO: Add unit tests here
  
};

class ComplexConjugate : public CxxTest::TestSuite {  
public:
  
  // TODO: Add unit tests here
  
};

#endif
