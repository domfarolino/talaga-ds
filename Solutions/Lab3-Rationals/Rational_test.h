#ifndef RATIONAL_TEST_H
#define RATIONAL_TEST_H

#include <Rational.h>

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

class RationalStarter : public CxxTest::TestSuite {
private:
   Rational* zero;
   Rational* third;
   Rational* half;
   Rational* one;
   Rational* two;
   
public:
  
  virtual void setUp() {
    zero = new Rational(0,1);
    third = new Rational(1,3);
    half = new Rational(1,2);
    one = new Rational(1,1);
    two = new Rational(2,1);
  }

  virtual void tearDown() {
    delete zero;
    delete third;
    delete half;
    delete one;
    delete two;
  }
  
  
  void testConstructor1() {
    TS_ASSERT_EQUALS(*one, Rational(1));
  }
  
  void testConstructor2() {
    TS_ASSERT_EQUALS(*two, Rational(2));
  }
  
  // Get tests
  void testgetNumerator() {
    TS_ASSERT_EQUALS(half->getNumerator(), 1);
  }
  
  void testgetNumerator2() {
    TS_ASSERT_EQUALS(two->getNumerator(), 2);
  }
  
  void testgetDenominator() {
    TS_ASSERT_EQUALS(half->getDenominator(), 2);
  }
  
  void testgetDenominator2() {
    TS_ASSERT_EQUALS(two->getDenominator(), 1);
  }
  
  void testgetAsDouble() {
    TS_ASSERT_DELTA(one->getAsDouble(), 1.0, 0.001);
  }
  
  void testgetAsDouble2() {
    TS_ASSERT_DELTA(two->getAsDouble(), 2.0, 0.001);
  }
  
  void testgetAsDouble3() {
    TS_ASSERT_DELTA(half->getAsDouble(), 0.5, 0.001);
  }
  
  void testgetAsDouble4() {
    TS_ASSERT_DELTA(third->getAsDouble(), 0.33333, 0.001);
  }
  
  // Math Operators
  
  void testAdd1() {
    TS_ASSERT_EQUALS(*half + *half, *one);
  }
  
  void testAdd2() {
    TS_ASSERT_EQUALS(*third + *third + *third, *one);
  }
  
  void testAdd3() {
    TS_ASSERT_EQUALS(*third + *zero, *third);
  }
  
  void testAdd4() {
    TS_ASSERT_EQUALS(*third + *third + *third + 1, *two);
  }
  
  void testSub1() {
    TS_ASSERT_EQUALS(*half - *half, *zero);
  }
  
  void testSub2() {
    TS_ASSERT_EQUALS(*third - *third - *third + *third + *third, *third);
  }
  
  void testmult1(){
    TS_ASSERT_EQUALS(*half * 2, *one);
  }
  
  void testmult2(){
    TS_ASSERT_EQUALS(*third * Rational(12,2), *two);
  }
  
  void testmult3(){
    TS_ASSERT_EQUALS(*two * -1, *zero - *two);
  }
  


  // Boolean operators
  void testless1(){
    TS_ASSERT(*one < *two);
  }
  
  void testless2(){
    TS_ASSERT(! (*one < *one));
  }
  
  void testlessEqual1(){
    TS_ASSERT(*one <= *two);
  }
  
  void testlessEqual2(){
    TS_ASSERT( (*one <= *one));
  }
  
  void testgreater1(){
    TS_ASSERT(*one > *half);
  }
  
  void testgreater2(){
    TS_ASSERT(! (*one > *one));
  }
  
  void testgreaterEqual1(){
    TS_ASSERT(*one >= *half);
  }
  
  void testgreaterEqual2(){
    TS_ASSERT( (*one >= *one));
  }
  
  void testequal1(){
    TS_ASSERT(*one == *one);
  }
  
  void testequal2(){
    TS_ASSERT(! (*one == *half));
  }
  
  void testnotEqual1(){
    TS_ASSERT(*one != *two);
  }
  
  void testnotEqual2(){
    TS_ASSERT(! (*one != Rational(5,5)));
  }
  
};

class RationalLab : public CxxTest::TestSuite {
private:
   Rational* zero;
   Rational* third;
   Rational* half;
   Rational* one;
   Rational* two;
   
public:
  
  virtual void setUp() {
    zero = new Rational(0,1);
    third = new Rational(1,3);
    half = new Rational(1,2);
    one = new Rational(1,1);
    two = new Rational(2,1);
  }

  virtual void tearDown() {
    delete zero;
    delete third;
    delete half;
    delete one;
    delete two;
  }
  
	  
  void testdivide_01(){
   TS_ASSERT((Rational(12,2) / Rational(12,0)) == Rational(0));
  }
  void testdivide_02(){
   TS_ASSERT((Rational(12,2) / Rational(12,2)) == Rational(1,1));
  }
  void testdivide_03(){
   TS_ASSERT((Rational(12,2) / Rational(12,2)) == Rational(1));
  }
  void testdivide_04(){
   TS_ASSERT((Rational(45,2) / Rational(5,2)) == Rational(9,1));
  }
  void testdivide_05(){
   TS_ASSERT((Rational(45,2) / Rational(5,2)) == Rational(9));
  }
  

};

#endif
