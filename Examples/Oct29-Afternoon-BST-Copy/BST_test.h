#ifndef BST_TEST_H
#define BST_TEST_H

#include "BST.h"
#include <string>
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

int compare(const int& left, const int& right){
  return left - right;
}

int compare(const string& left, const string& right){
  // The string class has a built-in compare function!
  return left.compare(right);
}

class BSTInsertSize : public CxxTest::TestSuite {
public:

  void testEmpty() {
    BST<int> a(compare);
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testInsert1() {
    BST<int> a(compare);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  // TODO
  
};

class BSTClear : public CxxTest::TestSuite {
public: 
  void testClear2() {
    BST<int> a(compare);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  // TODO
};

class BSTSmallestLargest : public CxxTest::TestSuite {
public:
  void testSmallest0(){
    BST<int> a(compare);
    TS_ASSERT_THROWS_ANYTHING(a.getSmallest());
  }
  
  void testSmallest1(){
    BST<int> a(compare);
    a.insert(5);
    TS_ASSERT_EQUALS(a.getSmallest(), 5);
  }
  // TODO
};

class BSTConCopyAssign : public CxxTest::TestSuite {
public:
  // Copy Constructor
	void testCopy() {
    BST<int> a(compare);
    a.insert(5);
    BST<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
  }

  void testCopy1() {
    BST<int> a(compare);
    a.insert(5);
    BST<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
    a.insert(6);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(b.size(), 1);
  }
// TODO
};

class BSTFind : public CxxTest::TestSuite {
public:
  void testInsertFind0(){
    BST<int> a(compare);
    TS_ASSERT(!a.find(5));
  }

  void testInsertFind1(){
    BST<int> a(compare);
    a.insert(5);
    TS_ASSERT(a.find(5));
  }
 
  void testInsertFind7(){  // balanced
    BST<string> a(compare);
    a.insert("bob");
    a.insert("apple");
    a.insert("binge");
    TS_ASSERT(a.find("bob"));
    TS_ASSERT(a.find("apple"));
    TS_ASSERT(a.find("binge"));
    TS_ASSERT(!a.find("broad"));
  }
  // TODO
};

class BSTGetOrders : public CxxTest::TestSuite {
public:
  
  void testInorder1(){
    BST<int> a(compare);
    a.insert(5);
    string out = a.getInOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5]");
  }
  
  void testInorder2(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    string out = a.getInOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,6,7,8]");
  }
 
   void testPostorder2(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    string out = a.getPostOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[8,7,6,5]");
  }
  // TODO
};

class BSTHeight : public CxxTest::TestSuite {
public:

  void testHeight0() {
    BST<int> a(compare);
    TS_ASSERT_EQUALS(a.getHeight(), 0);
  }
  
  void testHeight1() {
    BST<int> a(compare);
    a.insert(5);
    TS_ASSERT_EQUALS(a.getHeight(), 0);
  }
  
  void testHeight2() {
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    TS_ASSERT_EQUALS(a.getHeight(), 1);
  }
  // TODO
  
};

class BSTFull : public CxxTest::TestSuite {
public:
  void testFull0() {
    BST<int> a(compare);
    TS_ASSERT(a.isFull());
  }
  
  void testFull1() {
    BST<int> a(compare);
    a.insert(10);
    TS_ASSERT(a.isFull());
  }
  
  void testFull2() {
    BST<int> a(compare);
    a.insert(10);
    a.insert(12);
    TS_ASSERT(!a.isFull());
  }
  
  void testFull3() {
    BST<int> a(compare);
    a.insert(10);
    a.insert(12);
    a.insert(8);
    TS_ASSERT(a.isFull());
  }
  // TODO
};

class BSTBalanced : public CxxTest::TestSuite {
public:
  void testBalanced0(){
    BST<int> a(compare);
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced1(){
    BST<int> a(compare);
    a.insert(5);
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced2(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(3);
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced3(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(3);
    a.insert(8);
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced4(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(3);
    a.insert(8);
    a.insert(4);
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced5(){
    BST<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    TS_ASSERT(!a.isBalanced());
  }
  // TODO
};

#endif
