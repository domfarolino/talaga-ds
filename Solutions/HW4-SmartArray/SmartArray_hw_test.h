#ifndef SMARTARRAY_HW_TEST_H
#define SMARTARRAY_HW_TEST_H

#include "SmartArray.h"

#include <iostream>
#include <cxxtest/TestSuite.h>
// Needed for space removal.
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

class SmartArrayAT : public CxxTest::TestSuite {  
public:
  
  // At and [] tests
  void testat1() {
    SmartArray<int> a;
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_THROWS_ANYTHING(a.at(0));
  }
  
  void testbracket1() {
    SmartArray<int> a;
    TS_ASSERT_THROWS_ANYTHING(a[0]);
  }
  
  void testat2() {
    SmartArray<int> a;
    a.push_back(5);
    a.push_back(7);
    TS_ASSERT_EQUALS(a.at(0), 5);
  }
  
  void testbracket2() {
    SmartArray<int> a;
    a.push_back(5);
    a.push_back(7);
    TS_ASSERT_EQUALS(a[0], 5);
  }
  
  void testat3() {
    SmartArray<int> a;
    a.push_back(5);
    a.push_back(7);
    a.push_back(8);
    TS_ASSERT_EQUALS(a.at(-1), 8);
  }
  
  void testbracket3() {
    SmartArray<int> a;
    a.push_back(5);
    a.push_back(7);
    a.push_back(8);
    TS_ASSERT_EQUALS(a[-1], 8);
  }
  // exception tests
  void testat4() {
    SmartArray<int> a;
    a.push_back(5);
    a.push_back(7);
    a.push_back(8);
    TS_ASSERT_THROWS_ANYTHING(a.at(3));
  }
  
  void testbracket4() {
    SmartArray<int> a;
    a.push_back(5);
    a.push_back(7);
    a.push_back(8);
    TS_ASSERT_THROWS_ANYTHING(a[3]);
  }
  
  void testat5() {
    SmartArray<int> a;
    a.push_back(5);
    a.push_back(7);
    a.push_back(8);
    TS_ASSERT_THROWS_ANYTHING(a.at(-4));
  }
  
  void testbracket5() {
    SmartArray<int> a;
    a.push_back(5);
    a.push_back(7);
    a.push_back(8);
    TS_ASSERT_THROWS_ANYTHING(a[-4]);
  }
};

class SmartArrayClear : public CxxTest::TestSuite {  
public:
  // .clear() tests (only need 3)
  void testClear1(){
    SmartArray<int> a;
    a.push_back(5);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testClear2(){
    SmartArray<int> a;
    a.push_back(5);
    a.clear();
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testClear3(){
    SmartArray<int> a;
    a.push_back(5);
    a.clear();
    a.clear();
    a.push_back(6);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(a[0], 6);
  }
};

class SmartArrayAdd : public CxxTest::TestSuite {  
public:
  // + between two SmartArray tests
  void testAdd1(){
    SmartArray<int> a;
    SmartArray<int> b;
    a.push_back(5);
    b.push_back(6);
    SmartArray<int> c = a + b;
    TS_ASSERT_EQUALS(c.size(), 2);
    TS_ASSERT_EQUALS(c[0], 5);
    TS_ASSERT_EQUALS(c[1], 6);
  }
  
  void testAdd2(){
    SmartArray<int> a;
    SmartArray<int> b;
    b.push_back(6);
    SmartArray<int> c = a + b;
    TS_ASSERT_EQUALS(c.size(), 1);
    TS_ASSERT_EQUALS(c[0], 6);
  }
  
  void testAdd3(){
    SmartArray<int> a;
    SmartArray<int> b;
    a.push_back(6);
    SmartArray<int> c = a + b;
    TS_ASSERT_EQUALS(c.size(), 1);
    TS_ASSERT_EQUALS(c[0], 6);
  }
  
  void testAdd4(){
    SmartArray<int> a;
    SmartArray<int> b;
    a.push_back(6);
    a.push_back(7);
    b.push_back(8);
    b.push_back(9);
    SmartArray<int> c = a + b;
    TS_ASSERT_EQUALS(c.size(), 4);
    TS_ASSERT_EQUALS(c[2], 8);
  }
  
  // Verify the old didn't change
  void testAdd5(){
    SmartArray<int> a;
    SmartArray<int> b;
    a.push_back(6);
    a.push_back(7);
    b.push_back(8);
    b.push_back(9);
    SmartArray<int> c = a + b;
    TS_ASSERT_EQUALS(c.size(), 4);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(b.size(), 2);
    TS_ASSERT_EQUALS(a[0], 6);
    TS_ASSERT_EQUALS(b[0], 8);
  }
};

class SmartArrayReverse : public CxxTest::TestSuite {  
public:
  // .reverse() tests
  void testReverse1(){
    SmartArray<int> a;
    SmartArray<int> b = a.reverse();
    TS_ASSERT_EQUALS(b.size(), 0);
  }
  
  void testReverse2(){
    SmartArray<int> a;
    a.push_back(8);
    SmartArray<int> b = a.reverse();
    TS_ASSERT_EQUALS(b.size(), 1);
    TS_ASSERT_EQUALS(b[0], 8);
  }
  
  void testReverse3(){
    SmartArray<int> a;
    a.push_back(8);
    a.push_back(9);
    SmartArray<int> b = a.reverse();
    TS_ASSERT_EQUALS(b.size(), 2);
    TS_ASSERT_EQUALS(b[0], 9);
    TS_ASSERT_EQUALS(b[1], 8);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testReverse4(){
    SmartArray<int> a;
    a.push_back(8);
    a.push_back(9);
    a.push_back(10);
    SmartArray<int> b = a.reverse();
    TS_ASSERT_EQUALS(b.size(), 3);
    b.push_back(7);
    TS_ASSERT_EQUALS(b[0], 10);
    TS_ASSERT_EQUALS(b[1], 9);
    TS_ASSERT_EQUALS(a.size(), 3);
    TS_ASSERT_EQUALS(b.size(), 4);
  }
  
  void testReverse5(){
    SmartArray<int> a;
    a.push_back(8);
    a.push_back(9);
    a.push_back(10);
    TS_ASSERT_EQUALS(a.reverse().reverse(), a);
  }
  
};

class SmartArrayEquality : public CxxTest::TestSuite {  
public:
  // == and != tests
  void testEq1(){
    SmartArray<int> a;
    SmartArray<int> b;
    TS_ASSERT( a == b);
  }
  
  void testEq2(){
    SmartArray<int> a;
    SmartArray<int> b;
    a.push_back(5);
    b.push_back(5);
    TS_ASSERT( a == b);
  }
  
  void testEq3(){
    SmartArray<int> a;
    a.push_back(5);
    SmartArray<int> b;
    TS_ASSERT(! (a == b));
  }
  
  void testEq4(){
    SmartArray<int> a;
    SmartArray<int> b;
    b.push_back(5);
    TS_ASSERT(! (a == b));
  }
  
  void testEq5(){
    SmartArray<int> a;
    SmartArray<int> b;
    a.push_back(5);
    b.push_back(6);
    TS_ASSERT(! (a == b));
  }
  
  void testnEq1(){
    SmartArray<int> a;
    SmartArray<int> b;
    TS_ASSERT( !(a != b));
  }
  
  void testnEq2(){
    SmartArray<int> a;
    SmartArray<int> b;
    a.push_back(5);
    b.push_back(5);
    TS_ASSERT( !(a != b));
  }
  
  void testnEq3(){
    SmartArray<int> a;
    a.push_back(5);
    SmartArray<int> b;
    TS_ASSERT( a != b );
  }
  
  void testnEq4(){
    SmartArray<float> a;
    SmartArray<float> b;
    b.push_back(5.5);
    TS_ASSERT( a != b );
  }
  
  void testnEq5(){
    SmartArray<bool> a;
    SmartArray<bool> b;
    a.push_back(true);
    b.push_back(false);
    TS_ASSERT( a != b );
  }
};

class SmartArrayCopyAssignment : public CxxTest::TestSuite {  
public:
  // Copy Constructor and assignment
  void changeSomething(SmartArray<int> thing){
    thing.push_back(6);
  }
  
  void testCopy1(){
    SmartArray<int> a;
    a.push_back(5);
    changeSomething(a);
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  
  void testCopy2(){
    SmartArray<int> a;
    a.push_back(5);
    a.push_back(9);
    changeSomething(a);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(a.back(), 9);
  }
  
  void testAssign1(){
    SmartArray<string> a;
    a.push_back("thing");
    SmartArray<string> b;
    b = a;
    TS_ASSERT_EQUALS(b.size() , 1);
  }
  
  void testAssign2(){
    SmartArray<string> a;
    a.push_back("thing");
    SmartArray<string> b;
    b = a;
    TS_ASSERT_EQUALS(b.back() , "thing");
  }
  
  void testAssign3(){
    SmartArray<string> a;
    a.push_back("thing");
    SmartArray<string> b;
    b = a;
    a.push_back("tree");
    TS_ASSERT_EQUALS(b.size() , 1);
  }
  
  void testAssign4(){
    SmartArray<string> a;
    a.push_back("thing");
    SmartArray<string> b;
    b = a;
    a.push_back("tree");
    b.push_back("nothing");
    TS_ASSERT_EQUALS(a.size() , 2);
    TS_ASSERT_EQUALS(b.size() , 2);
    TS_ASSERT_EQUALS(b.back() , "nothing");
  }
  
  void testAssign5(){
    SmartArray<string> a;
    a.push_back("thing");
    a = a;
    TS_ASSERT_EQUALS(a.back() , "thing");
    TS_ASSERT_EQUALS(a.size() , 1);
  }
  
  
};

class SmartArrayStream : public CxxTest::TestSuite {  
public:
  // << tests
  void testStream1(){
    SmartArray<int> a;
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
    SmartArray<int> a;
    // To test we stream to a stringstream, then remove spaces, then test
    // the result.
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[]");
  }
  
  void testStream3(){
    SmartArray<float> a;
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
    SmartArray<string> a;
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
    SmartArray<int> a;
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

#endif
