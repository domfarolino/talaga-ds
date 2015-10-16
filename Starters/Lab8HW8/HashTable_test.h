#ifndef HASHTABLE_TEST_H
#define HASHTABLE_TEST_H

#include "HashTable.h"
#include <stdexcept>
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

const int SIZE = 2000;  // Size of Linked List to test speed.

// Some useful hash functions
unsigned int hash(const int& number){
  return abs(number);
}

unsigned int hash(const string& word){
  unsigned int ret = 0;
  for(unsigned int i = 0; i < word.length(); i++){
    ret += word[i] * i + i * 47;
  }
  return ret;
}

class HashTableInsertSizeCap : public CxxTest::TestSuite {
public:

  void testEmpty() {
    HashTable<int> a(hash, 5);
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_EQUALS(a.capacity(), 5);
  }
  
  void testInsert1() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(a.capacity(), 5);
  }
  // TODO
};

class HashTableClear : public CxxTest::TestSuite {
public:

  // TODO
  
};

class HashTableConCopyAssign : public CxxTest::TestSuite {
   
public:
  // Copy Constructor
	void testCopy() {
    HashTable<int> a(hash,5);
    a.insert(5);
    HashTable<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
  }
// TODO
  
};

class HashTableInsertFind : public CxxTest::TestSuite {
public:
  void testInsertFind1(){
    HashTable<int> a(hash, 5);
    a.insert(5);
    TS_ASSERT(a.find(5));
  }
  // TODO
  
};

class HashTableRemove : public CxxTest::TestSuite {
public:

  void testRm1() {
    HashTable<int> a(hash, 5);
    a.remove(5);
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  // TODO
};


#endif
