#ifndef COMPLEX_TEST_H
#define COMPLEX_TEST_H

#include <Complex.h>

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

const double delta = 0.0001;

class ComplexGetters : public CxxTest::TestSuite {  
public:
  void testGetReal1(){
    TS_ASSERT_DELTA(Complex(5,5).getReal(), 5, delta);
  }
  
  void testGetReal2(){
    TS_ASSERT_DELTA(Complex(6,8).getReal(), 6, delta);
  }
  
  void testGetReal3(){
    TS_ASSERT_DELTA(Complex(3,7).getReal(), 3, delta);
  }
  
  void testGetImaginary1(){
    TS_ASSERT_DELTA(Complex(9,1).getImaginary(), 1, delta);
  }
  
  void testGetImaginary2(){
    TS_ASSERT_DELTA(Complex(2,4).getImaginary(), 4, delta);
  }
  
  void testGetImaginary3(){
    TS_ASSERT_DELTA(Complex(8,2).getImaginary(), 2, delta);
  }
  
  
  // TODO: Add unit tests here
  
};

class ComplexAdd : public CxxTest::TestSuite {  
public:

  // TODO: Add unit tests here
  void testAdd1() {
    TS_ASSERT_EQUALS(Complex(5,1) + Complex(2,9), Complex(7,10));
  }
  
  void testAdd2() {
    TS_ASSERT_EQUALS(Complex(7,3) + Complex(2,6), Complex(9,9));
  }
  
  void testAdd3() {
    TS_ASSERT_EQUALS(Complex(8,4) + Complex(1,3), Complex(9,7));
  }
  
  void testAdd4() {
    TS_ASSERT_EQUALS(Complex(6,2) + Complex(8,9), Complex(14,11));
  }
  
  void testAdd5() {
    TS_ASSERT_EQUALS(Complex(4,2) + Complex(3,6), Complex(7,8));
  }
  
  void testAdd6() {
    TS_ASSERT_EQUALS(Complex(5,3) + Complex(2,7), Complex(7,10));
  }
  
};

class ComplexSub : public CxxTest::TestSuite {  
public:
  
  // TODO: Add unit tests here
  void testSub1() {
    TS_ASSERT_EQUALS(Complex(20,11) - Complex(8,2), Complex(12,9));
  }
  
  
  void testSub2() {
    TS_ASSERT_EQUALS(Complex(18,10) - Complex(9,5), Complex(9,5));
  }
  
  void testSub3() {
    TS_ASSERT_EQUALS(Complex(6,15) - Complex(2,10), Complex(4,5));
  }
  
  void testSub4() {
    TS_ASSERT_EQUALS(Complex(16,2) - Complex(4,1), Complex(12,1));
  }
  
  void testSub5() {
    TS_ASSERT_EQUALS(Complex(4,17) - Complex(2,7), Complex(2,10));
  }
  
  void testSub6() {
    TS_ASSERT_EQUALS(Complex(14,7) - Complex(11,6), Complex(3,1));
  }
  
};

class ComplexMult : public CxxTest::TestSuite {  
public:
  
  // TODO: Add unit tests here
  void testMult1() {
    TS_ASSERT_EQUALS(Complex(7,3) * Complex(5,1), Complex(32,22));
  }
  
  void testMult2() {
    TS_ASSERT_EQUALS(Complex(1,4) * Complex(6,3), Complex(-6,27));
  }
  
  void testMult3() {
    TS_ASSERT_EQUALS(Complex(5,8) * Complex(3,2), Complex(-1,34));
  }
  
  void testMult4() {
    TS_ASSERT_EQUALS(Complex(7,2) * Complex(4,3), Complex(22,29));
  }
  
  void testMult5() {
    TS_ASSERT_EQUALS(Complex(6,1) * Complex(5,2), Complex(28,17));
  }
  
};

class ComplexEquality : public CxxTest::TestSuite {  
public:
  
  // TODO: Add unit tests here
  
  void testEqual1(){
    TS_ASSERT_EQUALS(Complex(3,8), Complex(3,8));
  }
  
  void testEqual2(){
    TS_ASSERT_EQUALS(Complex(6,2), Complex(6,2));
  }
  
  void testEqual3(){
    TS_ASSERT_EQUALS(Complex(9,5), Complex(9,5));
  }
  
  void testEqual4(){
    TS_ASSERT_DIFFERS(Complex(1,4), Complex(3,2));
  }
  
  void testEqual5(){
    TS_ASSERT_DIFFERS(Complex(7,0), Complex(8,3));
  }
  
  void testEqual6(){
    TS_ASSERT_DIFFERS(Complex(4,6), Complex(5,9));
  }
  
};

class ComplexConjugate : public CxxTest::TestSuite {  
public:
  
  // TODO: Add unit tests here
  
  void testConj1(){
    TS_ASSERT_EQUALS(Complex(3,4).conjugate(), Complex(3,-4));
  }
  
  void testConj2(){
    TS_ASSERT_EQUALS(Complex(6,1).conjugate(), Complex(6,-1));
  }
  
  void testConj3(){
    TS_ASSERT_EQUALS(Complex(7,3).conjugate(), Complex(7,-3));
  }
  
  void testConj4(){
    TS_ASSERT_EQUALS(Complex(4,7).conjugate(), Complex(4,-7));
  }
  
  void testConj5(){
    TS_ASSERT_EQUALS(Complex(5,5).conjugate(), Complex(5,-5));
  }
  
  void testConj6(){
    TS_ASSERT_EQUALS(Complex(9,8).conjugate(), Complex(9,-8));
  }
};

#endif
