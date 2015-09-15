#ifndef SMARTARRAY_LAB_TEST_H
#define SMARTARRAY_LAB_TEST_H

#include "SmartArray.h"

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

class SmartArraySize : public CxxTest::TestSuite {  
public:
  
  // Constructor/size tests
  void testSize1() {
    SmartArray<int> a;
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testSize2() {
    SmartArray<int> a(1,5);
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  
  void testSize3() {
    SmartArray<int> a(10,5);
    TS_ASSERT_EQUALS(a.size(), 10);
  }
  
  void testSize4() {
    SmartArray<int> a(0,5);
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
};

class SmartArrayPushBack : public CxxTest::TestSuite {  
public:
  
  // Sadly this does not test the values, just the size
  /*
  void ttestPushBack1() {
    SmartArray<int> a;
    a.push_back(6);
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  
  void ttestPushBack2() {
    SmartArray<int> a(1,5);
    a.push_back(10);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void ttestPushBack3() {
    SmartArray<int> a(10,5);
    a.push_back(0);
    a.push_back(10);
    TS_ASSERT_EQUALS(a.size(), 12);
  }
  
  void ttestPushBack4() {
    SmartArray<int> a(0,5);
    a.push_back(-5);
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  */
};

class SmartArrayBack : public CxxTest::TestSuite {  
public:
/*
  void ttestBack1() {
    SmartArray<int> a;
    a.push_back(6);
    TS_ASSERT_EQUALS(a.back(), 6);
  }
  
  void ttestBack2() {
    SmartArray<int> a(1,5);
    a.push_back(10);
    TS_ASSERT_EQUALS(a.back(), 10);
  }
  
  void ttestBack3() {
    SmartArray<int> a(10,5);
    a.push_back(0);
    a.push_back(10);
    TS_ASSERT_EQUALS(a.back(), 10);
  }
  
  void ttestBack4() {
    SmartArray<int> a(0,5);
    a.push_back(-5);
    TS_ASSERT_EQUALS(a.back(), -5);
    a.push_back(99);
    TS_ASSERT_EQUALS(a.back(), 99);
  }
  
  void ttestBack5(){
    SmartArray<int> a;
    TS_ASSERT_THROWS_ANYTHING(a.back());
  }
  */
};

class SmartArrayPopBack : public CxxTest::TestSuite {  
public:
/*
  void ttestPopBack1() {
    SmartArray<int> a;
    a.push_back(6);
    a.pop_back();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void ttestBack2() {
    SmartArray<int> a(1,5);
    a.push_back(10);
    a.push_back(12);
    a.pop_back();
    TS_ASSERT_EQUALS(a.back(), 10);
  }
  
  void ttestBack3() {
    SmartArray<int> a(10,5);
    a.pop_back();
    a.push_back(10);
    TS_ASSERT_EQUALS(a.back(), 10);
    TS_ASSERT_EQUALS(a.size(), 10);
  }
  
  void ttestBack4() {
    SmartArray<int> a(2,5);
    a.pop_back();
    TS_ASSERT_EQUALS(a.back(), 5);
    a.push_back(99);
    TS_ASSERT_EQUALS(a.back(), 99);
    a.pop_back();
    a.pop_back();
    TS_ASSERT_THROWS_ANYTHING(a.back());
  }
  */
};

#endif
