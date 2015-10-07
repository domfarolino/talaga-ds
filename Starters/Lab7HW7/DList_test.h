#ifndef DLIST_TEST_H
#define DLIST_TEST_H

#include "DList.h"
#include <stdexcept>
// Needed for space removal.
#include <sstream>
#include <algorithm>
#include <cxxtest/TestSuite.h>
#include <ctime>

using namespace std;

// This requires CxxTest to be installed!
// For this CPPVideos example, navigate your terminal to CPPVideos and type:
// git submodule add https://github.com/CxxTest/cxxtest.git
// This will add the public CxxTest repository INSIDE the current repo.
// The current Makefile in this directory assumes cxxtest is a folder one
// level down.

const int SIZE = 2000;  // Size of Linked List to test speed.

class DListConCopyAssign : public CxxTest::TestSuite {
   
public:
  
  // Constructor tests
  void testEmpty() {
    DList<int> a;
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  // Copy Constructor
	void testCopy() {
    DList<int> a;
    a.push_back(5);
    DList<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
  }

  void testCopy1() {
    DList<int> a;
    a.push_back(5);
    DList<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
    a.push_front(10);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(b.size(), 1);
  }

  void testCopy2() {
    DList<int> a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    a.push_back(8);
    DList<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 4);
    TS_ASSERT_EQUALS(b.size(), 4);
    TS_ASSERT_EQUALS(a.getAt(3), 8);
    TS_ASSERT_EQUALS(b.getAt(3), 8);
  }	
	
	// Assignment
	
	void testAssign() {
    DList<int> a;
    a.push_back(5);
    DList<int> b;
    b.push_back(10);
    a = b;
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
    TS_ASSERT_EQUALS(a.getAt(0), 10);
    TS_ASSERT_EQUALS(b.getAt(0), 10);
  }

  void testAssign1() {
    DList<int> a;
    a.push_back(5);
    a = a;
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  
};

class DListPushes : public CxxTest::TestSuite {
public:

  void testPushBack1() {
    DList<int> a;
    TS_ASSERT_EQUALS(a.size(), 0);
  }

  void testPushBack2() {
    DList<int> a;
    a.push_back(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.push_back(6);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testPushBack3() {
    DList<string> a;
    a.push_back("hi");
    TS_ASSERT_EQUALS(a.size(), 1);
    a.push_back("bib");
    TS_ASSERT_EQUALS(a.size(), 2);
    a.push_back("bill");
    TS_ASSERT_EQUALS(a.size(), 3);
  }

  void testPushFront2() {
    DList<int> a;
    a.push_front(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.push_front(6);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testPushFront3() {
    DList<int> a;
    a.push_front(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.push_front(6);
    TS_ASSERT_EQUALS(a.size(), 2);
    a.push_front(7);
    TS_ASSERT_EQUALS(a.size(), 3);
  }
};

class DListSetAt : public CxxTest::TestSuite {
public:

  void testSet1() {
    DList<int> a;
    a.push_back(5);
    a.push_back(6);
		a.setAt(10,0);
    TS_ASSERT_EQUALS(a.getAt(0), 10);
		TS_ASSERT_EQUALS(a.getAt(1), 6);
  }
	
  void testSet2() {
    DList<int> a;
    a.push_back(5);
    a.push_back(6);
    TS_ASSERT_THROWS_ANYTHING(a.setAt(99,2));
  }
	
  void testSet3() {
    DList<int> a;
    a.push_back(5);
    a.push_back(6);
    TS_ASSERT_THROWS_ANYTHING(a.setAt(99,-3));
  }
	
  void testSet4() {
    DList<int> a;
    a.push_back(5);
    a.push_back(6);
		a.setAt(10,-1);
		TS_ASSERT_EQUALS(a.getAt(0), 5);
    TS_ASSERT_EQUALS(a.getAt(1), 10);
  }
	
	void testSet5() {
    DList<int> a;
    a.push_back(5);
    a.push_back(6);
		a.setAt(10,-2);
		TS_ASSERT_EQUALS(a.getAt(0), 10);
    TS_ASSERT_EQUALS(a.getAt(1), 6);
  }
	

  void testGetAt1() {
    DList<int> a;
		TS_ASSERT_THROWS_ANYTHING(a.getAt(0));
  }
  
  void testGetAt2() {
    DList<int> a;
    a.push_back(5);
    TS_ASSERT_EQUALS(a.getAt(0), 5);
    TS_ASSERT_EQUALS(a.getAt(-1), 5);
    TS_ASSERT_THROWS_ANYTHING(a.getAt(-2));
  }
  
  void testGetAt3() {
    DList<int> a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    TS_ASSERT_EQUALS(a.getAt(0), 5);
    TS_ASSERT_EQUALS(a.getAt(1), 6);
    TS_ASSERT_EQUALS(a.getAt(2), 7);
    TS_ASSERT_EQUALS(a.getAt(-1), 7);
    TS_ASSERT_EQUALS(a.getAt(-2), 6);
    TS_ASSERT_EQUALS(a.getAt(-3), 5);
    TS_ASSERT_THROWS_ANYTHING(a.getAt(-4));
  }
  
  void testGetAtSpeed1() {
    DList<int> a;
    for(int i = 0 ; i < SIZE; i++){
      a.push_front(i*2);
    }
    // How fast is accessing the first element?
    int sum = 0;
    clock_t first_start = clock();
    for(int i = 0 ; i < SIZE; i++){
      sum += a.getAt(0);
    }
    clock_t first_stop = clock();
    // How fast for the second to last?
    int sum2 = 0;
    clock_t last2_start = clock();
    for(int i = 0 ; i < SIZE; i++){
      sum2 += a.getAt(-2);
    }
    clock_t last2_stop = clock();
    //TS_ASSERT_DELTA(first_stop - first_start, last2_stop - last2_start, 100);
    TS_ASSERT_LESS_THAN(last2_stop - last2_start - 500, first_stop - first_start);
  }
  
  void testSetAtSpeed1() {
    DList<int> a;
    for(int i = 0 ; i < SIZE; i++){
      a.push_front(i*2);
    }
    // How fast is accessing the beginning elements?
    clock_t first_start = clock();
    for(int i = 0 ; i < SIZE/5; i++){
      a.setAt(42,i);
    }
    clock_t first_stop = clock();
    // How fast for accessing the last elements?
    clock_t last2_start = clock();
    for(int i = 0 ; i < SIZE/5; i++){
     a.setAt(42,SIZE - i - 1);
    }
    clock_t last2_stop = clock();
    //TS_ASSERT_DELTA(first_stop - first_start, last2_stop - last2_start, 500);
    TS_ASSERT_LESS_THAN(last2_stop - last2_start - 500, first_stop - first_start);
  }
};

class DListRemove : public CxxTest::TestSuite {
public:

  void testRemove1() {
    DList<int> a;
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_THROWS_ANYTHING(a.remove(0));
  }
  
  void testRemove2() {
    DList<int> a;
    a.push_front(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.remove(0);
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testRemove3() {
    DList<int> a;
    a.push_front(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.remove(-1);
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testRemove4() {
    DList<int> a;
    a.push_front(5);
    a.push_back(6);
    a.push_back(7);
    TS_ASSERT_EQUALS(a.size(), 3);
    a.remove(-1);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(a.getAt(0), 5);
    TS_ASSERT_EQUALS(a.getAt(1), 6);
    TS_ASSERT_THROWS_ANYTHING(a.getAt(2));
  }
  
  void testRemove5() {
    DList<int> a;
    a.push_front(5);
    a.push_back(6);
    a.push_back(7);
    TS_ASSERT_EQUALS(a.size(), 3);
    a.remove(1);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(a.getAt(0), 5);
    TS_ASSERT_EQUALS(a.getAt(1), 7);
  }
  
  void testRemove6() {
    DList<int> a;
    a.push_front(5);
    a.push_back(6);
    a.push_back(7);
    TS_ASSERT_EQUALS(a.size(), 3);
    a.remove(-2);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(a.getAt(0), 5);
    TS_ASSERT_EQUALS(a.getAt(1), 7);
  }
  
  void testRemove7() {
    DList<int> a;
    a.push_front(5);
    a.push_back(6);
    a.push_back(7);
    TS_ASSERT_EQUALS(a.size(), 3);
    a.remove(-1);
    TS_ASSERT_EQUALS(a.size(), 2);
    a.remove(-1);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.remove(-1);
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_THROWS_ANYTHING(a.remove(-1));
  }
  
  void testRemoveSpeed1() {
    DList<int> a;
    for(int i = 0 ; i < SIZE; i++){
      a.push_front(i*2);
    }
    // How fast is deleting the first element?
    clock_t first_start = clock();
    for(int i = 0 ; i < SIZE/5; i++){
      a.remove(0);
    }
    clock_t first_stop = clock();
    // How fast removing the last element?
    clock_t last2_start = clock();
    for(int i = 0 ; i < SIZE/5; i++){
      a.remove(-1);
    }
    clock_t last2_stop = clock();
    //TS_ASSERT_DELTA(first_stop - first_start, last2_stop - last2_start, 500);
    TS_ASSERT_LESS_THAN(last2_stop - last2_start - 500, first_stop - first_start);
  }
  
  void testRemoveSpeed2() {
    DList<int> a;
    const int SIZE = 1000;
    for(int i = 0 ; i < SIZE; i++){
      a.push_front(i*2);
    }
    // How fast is deleting the first element?
    clock_t first_start = clock();
    for(int i = 0 ; i < SIZE/5; i++){
      a.remove(0);
    }
    clock_t first_stop = clock();
    // How fast removing the last element?
    clock_t last2_start = clock();
    for(int i = 0 ; i < SIZE/5; i++){
      a.remove(-2);
    }
    clock_t last2_stop = clock();
    //TS_ASSERT_DELTA(first_stop - first_start, last2_stop - last2_start, 500);
    TS_ASSERT_LESS_THAN(last2_stop - last2_start - 500, first_stop - first_start);
  }
};

class DListReverse : public CxxTest::TestSuite {
public:
  void testRev0() {
    DList<int> a;
    DList<int> b = a.reverse();
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_EQUALS(b.size(), 0);
  }
  
  void testRev1() {
    DList<int> a;
    a.push_back(5);
    DList<int> b = a.reverse();
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
    TS_ASSERT_EQUALS(a.getAt(0), 5);
    TS_ASSERT_EQUALS(b.getAt(0), 5);
  }
  
  void testRev2() {
    DList<int> a;
    a.push_back(5);
    a.push_back(6);
    DList<int> b = a.reverse();
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(b.size(), 2);
    TS_ASSERT_EQUALS(a.getAt(0), 5);
    TS_ASSERT_EQUALS(b.getAt(0), 6);
    TS_ASSERT_EQUALS(a.getAt(1), 6);
    TS_ASSERT_EQUALS(b.getAt(1), 5);
  }
  
  void testRev3() {
    DList<int> a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    DList<int> b = a.reverse();
    TS_ASSERT_EQUALS(a.size(), 3);
    TS_ASSERT_EQUALS(b.size(), 3);
    TS_ASSERT_EQUALS(a.getAt(0), 5);
    TS_ASSERT_EQUALS(b.getAt(0), 7);
    TS_ASSERT_EQUALS(a.getAt(1), 6);
    TS_ASSERT_EQUALS(b.getAt(1), 6);
    TS_ASSERT_EQUALS(a.getAt(2), 7);
    TS_ASSERT_EQUALS(b.getAt(2), 5);
  }
  
  void testRev4() {
    DList<int> a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    a.push_back(8);
    DList<int> b = a.reverse();
    TS_ASSERT_EQUALS(a.size(), 4);
    TS_ASSERT_EQUALS(b.size(), 4);
    TS_ASSERT_EQUALS(a.getAt(0), 5);
    TS_ASSERT_EQUALS(b.getAt(0), 8);
    TS_ASSERT_EQUALS(a.getAt(1), 6);
    TS_ASSERT_EQUALS(b.getAt(1), 7);
    TS_ASSERT_EQUALS(a.getAt(2), 7);
    TS_ASSERT_EQUALS(b.getAt(2), 6);
    TS_ASSERT_EQUALS(a.getAt(3), 8);
    TS_ASSERT_EQUALS(b.getAt(3), 5);
  }
  
};

class DListAdd : public CxxTest::TestSuite {
public:
  void testAdd0() {
    DList<int> c = DList<int>() + DList<int>();
    TS_ASSERT_EQUALS(c.size(), 0);
  }
  
  void testAdd1() {
    DList<int> a;
    a.push_back(5);
    DList<int> b;
    b.push_back(10);
    DList<int> c = a + b;
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
    TS_ASSERT_EQUALS(c.size(), 2);
    TS_ASSERT_EQUALS(c.getAt(0), 5);
    TS_ASSERT_EQUALS(c.getAt(1), 10);
  }
  
  void testAdd2() {
    DList<int> a;
    DList<int> b;
    b.push_back(10);
    b.push_back(11);
    DList<int> c = a + b;
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_EQUALS(b.size(), 2);
    TS_ASSERT_EQUALS(c.size(), 2);
    TS_ASSERT_EQUALS(c.getAt(0), 10);
    TS_ASSERT_EQUALS(c.getAt(1), 11);
    try{
      c.getAt(2);
    }catch(logic_error& e){
      return;
    }
    TS_ASSERT(0);
  }
};

class DListEq : public CxxTest::TestSuite {
public:
  void testEq0() {
    DList<int> a;
    DList<int> b;
    TS_ASSERT( a == b);
    TS_ASSERT( !(a != b));
  }
  
  void testEq1() {
    DList<int> a;
    a.push_back(6);
    DList<int> b;
    b.push_front(6);
    TS_ASSERT( a == b);
    TS_ASSERT( !(a != b));
  }
  
  void testEq2() {
    DList<int> a;
    a.push_back(6);
    DList<int> b;
    TS_ASSERT( a != b);
    TS_ASSERT( !(a == b));
  }
  
  void testEq3() {
    DList<int> a;
    DList<int> b;
    b.push_front(6);
    TS_ASSERT( a != b);
    TS_ASSERT( !(a == b));
  }
  
  void testEq4() {
    DList<int> a;
    a.push_back(6);
    DList<int> b;
    a.push_front(7);
    TS_ASSERT( a != b);
    TS_ASSERT( !(a == b));
  }
  
  void testEq5() {
    DList<int> a;
    a.push_front(5);
    a.push_back(6);
    DList<int> b;
    b.push_front(6);
    b.push_front(5);
    TS_ASSERT( a == b);
    TS_ASSERT( !(a != b));
  }
};

class DListClear : public CxxTest::TestSuite {
public:
  void testClear0() {
    DList<int> a;
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testClear1() {
    DList<int> a;
    a.push_back(6);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testClear2() {
    DList<int> a;
    a.push_back(6);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
    a.push_back(7);
    TS_ASSERT_EQUALS(a.getAt(0), 7);
  }
};

class DListStream : public CxxTest::TestSuite {
public:
  void testStream1(){
    DList<int> a;
    a.push_back(5);
    a.push_back(6);
    // To test we stream to a stringstream, then remove spaces, then test
    // the result.
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,6]");
  }
  
  void testStream2(){
    DList<int> a;
    // To test we stream to a stringstream, then remove spaces, then test
    // the result.
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[]");
  }
  
  void testStream3(){
    DList<float> a;
    a.push_back(5.5);
    // To test we stream to a stringstream, then remove spaces, then test
    // the result.
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5.5]");
  }
  
  void testStream4(){
    DList<string> a;
    a.push_back("stuff");
    a.push_back("more");
    // To test we stream to a stringstream, then remove spaces, then test
    // the result.
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[stuff,more]");
  }
  
  void testStream5(){
    DList<int> a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    // To test we stream to a stringstream, then remove spaces, then test
    // the result.
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,6,7]");
  }
};


class DListFuzz : public CxxTest::TestSuite {
public:

  void testFuzz() {
    DList<int> a;
    const int size = 200;
    for(int i = 0; i < size; i++){
      a.push_back(i);
			a.push_back(i);
      a.push_front(i);
      a.remove(-1);
      TS_ASSERT_EQUALS(a.size(), (i+1) * 2);
    }
    // Make sure the sum is OK  Yes, this is very slow!
    long long int count = 0;
    for(unsigned int i = 0; i < a.size(); i++){
      count = count +  a.getAt(i);
    }
    TS_ASSERT_EQUALS(count, size * (size - 1)); // Does the count match?
    TS_ASSERT_EQUALS(a.size(), size * 2);
    
    for(int i = 0; i < size; i++){
      a.remove(-1);
      a.remove(0);
    }
    TS_ASSERT_EQUALS(a.size(), 0);
  }
};


#endif
