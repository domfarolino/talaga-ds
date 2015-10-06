#ifndef DLISTHW_TEST_H
#define DLISTHW_TEST_H

#include "DList.h"

#include <stdexcept>
// Needed for space removal.
#include <sstream>
#include <algorithm>
#include <cxxtest/TestSuite.h>

using namespace std;

// This requires CxxTest to be installed!
// For this CPPVideos example, navigate your terminal to CPPVideos and type:
// git submodule add https://github.com/CxxTest/cxxtest.git
// This will add the public CxxTest repository INSIDE the current repo.
// The current Makefile in this directory assumes cxxtest is a folder one
// level down.

const int SIZE = 3000;  

class DListCount : public CxxTest::TestSuite {
   
public:
  void testCount2(){
    DList<int> a;
    a.push_back(5);
    TS_ASSERT_EQUALS(a.count(5), 1);
  }
  
};

class DListSplitHalf : public CxxTest::TestSuite {
   
public:
  void testSplit1(){
    DList<int> a;
    DList<int> b;
    DList<int> c;
    c.push_back(1);
    c.push_back(2);
    c.splitHalf(a,b);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
    TS_ASSERT_EQUALS(c.size(), 0);
    TS_ASSERT_EQUALS(a.getAt(0), 1);
    TS_ASSERT_EQUALS(b.getAt(0), 2);
  }
};  

class DListSplitHalfSpeed : public CxxTest::TestSuite {
public:
  void testSplitSpeed1() {
    DList<int> a;
    // How fast to create the two lists?
    clock_t first_start = clock();
    for(int i = 0 ; i < SIZE; i++){
      a.push_front(i*2);
    }
    clock_t first_stop = clock();
    
    DList<int> b;
    DList<int> c;
    // How fast to split??
    clock_t last2_start = clock();
    a.splitHalf(b,c);
    clock_t last2_stop = clock();
    TS_ASSERT((first_stop - first_start) > (last2_stop - last2_start) - 30);
  }
};
  
class DListSplitEveryOther : public CxxTest::TestSuite {
   
public:
  void testSplitEO1(){
    DList<int> a;
    DList<int> b;
    DList<int> c;
    c.push_back(1);
    c.push_back(2);
    c.splitEveryOther(a,b);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
    TS_ASSERT_EQUALS(c.size(), 0);
    TS_ASSERT_EQUALS(a.getAt(0), 1);
    TS_ASSERT_EQUALS(b.getAt(0), 2);
  }
};

class DListReverseThis : public CxxTest::TestSuite {
   
public:
  void testReverseThis1(){
    DList<int> c;
    c.push_back(1);
    c.push_back(2);
    c.reverseThis();
    TS_ASSERT_EQUALS(c.size(), 2);
    TS_ASSERT_EQUALS(c.getAt(0), 2);
    TS_ASSERT_EQUALS(c.getAt(1), 1);
  }
};

class DListReverseSpeed : public CxxTest::TestSuite {
public:
  void testReverseSpeed1() {
    DList<int> a;
    // How fast to create the list?
    clock_t first_start = clock();
    for(int i = 0 ; i < SIZE; i++){
      a.push_front(i*2);
    }
    clock_t first_stop = clock();
    
    // How fast to split??
    clock_t last2_start = clock();
    a.reverseThis();
    clock_t last2_stop = clock();
    TS_ASSERT((first_stop - first_start) > (last2_stop - last2_start) - 30);
  }
};

class DListDoubleThis : public CxxTest::TestSuite {
public:
  
  void testDoubleThis2(){
    DList<int> a;
    a.push_back(1);
    a.doubleThis();
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
};

class DListSetEq : public CxxTest::TestSuite {
   
public:
  
  void testSetEQ2(){
    DList<int> a;
    DList<int> b;
    a.push_back(1);
    b.push_back(1);
    TS_ASSERT(a.setEq(b));
  }
  
  void testSetEQ3(){
    DList<int> a;
    DList<int> b;
    a.push_back(1);
    b.push_back(2);
    TS_ASSERT(! a.setEq(b));
  }
  
  void testSetEQSpeed2() {
    DList<int> a;
    DList<int> b;
    // How fast to create the lists? O(n)
    clock_t first_start = clock();
    for(int i = 0 ; i < SIZE; i++){
      a.push_front(i);
      b.push_back(i);
    }
    clock_t first_stop = clock();
    
    // How fast to check??
    clock_t last2_start = clock();
    TS_ASSERT(a.setEq(b));
    clock_t last2_stop = clock();
    // O(n*m)
    TS_ASSERT((first_stop - first_start) * (first_stop - first_start) > (last2_stop - last2_start) );
  }
};

class DListSetEqSpeed : public CxxTest::TestSuite {
public:
  void testSetEQSpeed1() {
    DList<int> a;
    DList<int> b;
    // How fast to create the lists?  O(n)
    clock_t first_start = clock();
    for(int i = 0 ; i < SIZE; i++){
      a.push_front(i);
      b.push_front(i);
    }
    clock_t first_stop = clock();
    
    // How fast to check??
    clock_t last2_start = clock();
    TS_ASSERT(a.setEq(b));
    clock_t last2_stop = clock();
    // O(n)  
    TS_ASSERT((first_stop - first_start) > (last2_stop - last2_start) - 40);
  }
  
  
};

#endif
