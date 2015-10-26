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
  
  void testInsert2() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.insert(6);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(a.capacity(), 5);
  }
  
  void testInsert3() {
    HashTable<int> a(hash, 7);
    a.insert(5);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(a.capacity(), 7);
  }
  
  void testInsertSize4(){
    HashTable<int> a(hash, 50);
    a.insert(5);
    a.insert(6);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(a.capacity(), 50);
  }
  
  void testInsertSize5(){
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.insert(6);
    a.insert(5);
    a.insert(6);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(a.capacity(), 5);
  }
  
  void testInsertSize6(){
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    a.insert(9);
    TS_ASSERT_EQUALS(a.size(), 5);
    TS_ASSERT_EQUALS(a.capacity(), 5);
  }
};

class HashTableClear : public CxxTest::TestSuite {
public:

  void testClear1() {
    HashTable<int> a(hash, 5);
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_EQUALS(a.capacity(), 5);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_EQUALS(a.capacity(), 5);
  }
  
  void testClear2() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(a.capacity(), 5);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_EQUALS(a.capacity(), 5);
  }
  
  void testClear3() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.insert(6);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(a.capacity(), 5);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_EQUALS(a.capacity(), 5);
  }
  
  void testFull() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.insert(6);
    TS_ASSERT(! a.isFull());
    a.insert(5);
    a.insert(7);
    a.insert(8);
    a.insert(9);
    TS_ASSERT(a.isFull());
  }
  
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

  void testCopy1() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    HashTable<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
    a.insert(6);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(b.size(), 1);
  }

  void testCopy2() {
    HashTable<int> a(hash, 10);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    HashTable<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 4);
    TS_ASSERT_EQUALS(b.size(), 4);
    TS_ASSERT(a.find(5));
    TS_ASSERT(b.find(5));
  }	
  
  void testCopy3() {
    HashTable<int> a(hash, 10);
    a.insert(5);
    a.insert(6);
    a.insert(6);
    a.insert(8);
    HashTable<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 3);
    TS_ASSERT_EQUALS(b.size(), 3);
    TS_ASSERT(!a.find(10));
    TS_ASSERT(!b.find(10));
  }	
	
	// Assignment
	
	void testAssign() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    HashTable<int> b(hash, 5);
    b.insert(10);
    a = b;
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
    TS_ASSERT(a.find(10));
    TS_ASSERT(!a.find(5));
  }

  void testAssign1() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    a = a;
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  
};

class HashTableFind : public CxxTest::TestSuite {
public:
  void testInsertFind1(){
    HashTable<int> a(hash, 5);
    a.insert(5);
    TS_ASSERT(a.find(5));
  }
  
  void testInsertFind2(){
    HashTable<int> a(hash, 5);
    a.insert(5);
    TS_ASSERT(!a.find(6));
  }
  
  void testInsertFind3(){  // test wrap around
    HashTable<int> a(hash, 10);
    a.insert(9);
    a.insert(19);
    a.insert(29);
    TS_ASSERT(a.find(9));
    TS_ASSERT(a.find(19));
    TS_ASSERT(a.find(29));
    TS_ASSERT(!a.find(39));
  }
  
  void testInsertFind4(){ // test completely filling it
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.insert(15);
    a.insert(25);
    a.insert(35);
    a.insert(45);
    TS_ASSERT(!a.find(55));
  }
  
  void testInsertFind5(){ // test completely filling it
    HashTable<int> a(hash, 5);
    a.insert(-5);
    a.insert(15);
    a.insert(25);
    a.insert(-35);
    a.insert(45);
    TS_ASSERT(a.find(-5));
    TS_ASSERT(a.find(15));
    TS_ASSERT(a.find(25));
    TS_ASSERT(a.find(-35));
    TS_ASSERT(a.find(45));
    TS_ASSERT(!a.find(55));
  }
  
  void testInsertFind6(){ // test completely filling it
    HashTable<int> a(hash, 5);
    a.insert(-5);
    a.insert(15);
    a.insert(25);
    a.insert(-35);
    a.insert(45);
    //a.insert(-35);
    //a.insert(45);
    TS_ASSERT(a.find(-5));
    TS_ASSERT(a.find(15));
    TS_ASSERT(a.find(25));
    TS_ASSERT(a.find(-35));
    TS_ASSERT(a.find(45));
    TS_ASSERT(!a.find(55));
  }
  
  void testInsertFind7(){ // test completely filling it
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.insert(15);
    a.insert(25);
    a.insert(35);
    a.insert(45);
    TS_ASSERT_THROWS_ANYTHING(a.insert(55));
  }
  
};

class HashTableRemove : public CxxTest::TestSuite {
public:

  void testRm1() {
    HashTable<int> a(hash, 5);
    a.remove(5);
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testRm2() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.remove(5);
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT(! a.find(5));
  }
  
  void testRm3() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.remove(10);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT(a.find(5));
  }
  
  void testRm4() {
    HashTable<int> a(hash, 5);
    a.insert(5);
    a.insert(66);
    a.remove(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT(! a.find(5));
    TS_ASSERT(a.find(66));
  }
  
  void testRm5() {
    HashTable<int> a(hash, 10);
    a.insert(5);
    a.insert(15);
    a.insert(25);
    a.remove(5);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT(! a.find(5));
    TS_ASSERT(a.find(15));
    TS_ASSERT(a.find(25));
  }
  
  void testRm6() {
    HashTable<int> a(hash, 10);
    a.insert(5);
    a.insert(15);
    a.insert(25);
    a.remove(5);
    a.insert(6);
    a.insert(4);
    a.insert(14);
    TS_ASSERT_EQUALS(a.size(), 5);
    TS_ASSERT(! a.find(5));
    TS_ASSERT(a.find(6));
    TS_ASSERT(a.find(4));
  }
  
  void testRm7() {
    HashTable<string> a(hash, 10);
    a.insert("bob");
    a.insert("bib");
    a.insert("bab");
    a.remove("bla");
    a.remove("bab");
    a.remove("bib");
    a.remove("bob");
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT(! a.find("bob"));
  }
};

class HashTableFuzz : public CxxTest::TestSuite {
// https://en.wikipedia.org/wiki/Fuzz_testing
public:
  void testFuzz1(){
    HashTable<int> a(hash, SIZE);
    // Put numbers that should collide into the hash table
    for(unsigned int i = 0; i < SIZE; i++){
      a.insert(SIZE * i);
      TS_ASSERT_EQUALS(a.size(), i+1);
    }
    TS_ASSERT_EQUALS(a.size(), SIZE);
    for(unsigned int i = 0; i < SIZE; i++){
      a.remove(SIZE * i);
      TS_ASSERT_EQUALS(a.size(), SIZE - i - 1);
    }
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
};

class HashTableSpeed : public CxxTest::TestSuite {
// https://en.wikipedia.org/wiki/Fuzz_testing
public:
  void testInsertSpeed1() {
    HashTable<int> a(hash, SIZE * 10000);
    // How fast to insert 100 elements?
    clock_t first_start = clock();
    for(int i = 0 ; i < 100; i++){
      a.insert(rand());
    }
    clock_t hund_time = (clock() - first_start);
    
    // Insert SIZE/2 more and make sure they are all fast
    for(int i = 0; i < 50; i++){
      clock_t last2_start = clock();
      for(int i = 0 ; i < 1000; i++){
        a.insert(rand());
      }
      clock_t last2_stop = clock();
      TS_ASSERT(hund_time * 10 > (last2_stop - last2_start) - 200);
    }
  }
  
};

#endif
