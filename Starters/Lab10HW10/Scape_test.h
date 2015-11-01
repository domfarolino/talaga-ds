#ifndef SCAPE_TEST_H
#define SCAPE_TEST_H

#include "Scapegoat.h"
#include <string>
// Needed for space removal.
#include <sstream>
#include <algorithm>
#include <cxxtest/TestSuite.h>
#include <ctime>

#define ALG Scapegoat

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

template <class T>
void permute(T* array, unsigned int size){
  if(size == 0){
    return;
  }
  // Using Fisher-Yates shuffle
  for(unsigned int i = size -1; i > 1; i--){
      int j = rand() % i;
      T temp = array[i];
      array[i] = array[j];
      array[j] = temp; 
    }
}

class InsertSize : public CxxTest::TestSuite {
public:

  void testEmpty() {
    ALG<int> a(compare);
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testInsert1() {
    ALG<int> a(compare);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  
  void testInsert2() {
    ALG<int> a(compare);
    a.insert(5);
    a.insert(6);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testInsert3() {
    ALG<int> a(compare);
    a.insert(5);
    a.insert(5);
    a.insert(6);
    TS_ASSERT_EQUALS(a.size(), 3);
  }
  
  void testInsertSize4(){
    ALG<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(10);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 4);
  }
  
  void testInsertSize5(){
    srand(time(0));
    ALG<int> a(compare);
    for(int i = 0; i < 100; i++){
      a.insert(rand());
    }
    TS_ASSERT_EQUALS(a.size(), 100);
  }
};

class Clear : public CxxTest::TestSuite {
public:
  void testClear1() {
    ALG<int> a(compare);
    TS_ASSERT_EQUALS(a.size(), 0);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testClear2() {
    ALG<int> a(compare);
    a.insert(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testClear3() {
    ALG<int> a(compare);
    a.insert(5);
    a.insert(6);
    TS_ASSERT_EQUALS(a.size(), 2);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testClear4() {
    ALG<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(3);
    TS_ASSERT_EQUALS(a.size(), 3);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
};

class SmallestLargest : public CxxTest::TestSuite {
public: 
  void testSmallest0(){
    ALG<int> a(compare);
    TS_ASSERT_THROWS_ANYTHING(a.getSmallest());
  }
  
  void testSmallest1(){
    ALG<int> a(compare);
    a.insert(5);
    TS_ASSERT_EQUALS(a.getSmallest(), 5);
  }
  
  void testSmallest2(){
    ALG<int> a(compare);
    a.insert(5);
    a.insert(4);
    TS_ASSERT_EQUALS(a.getSmallest(), 4);
  }
  
  void testSmallest3(){
    ALG<int> a(compare);
    a.insert(5);
    a.insert(6);
    TS_ASSERT_EQUALS(a.getSmallest(), 5);
  }
  
  void testSmallest4(){
    ALG<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    TS_ASSERT_EQUALS(a.getSmallest(), 5);
  }
  
  void testSmallest5(){
    ALG<int> a(compare);
    a.insert(5);
    a.insert(2);
    a.insert(4);
    TS_ASSERT_EQUALS(a.getSmallest(), 2);
  }
  
  void testLargest0(){
    ALG<int> a(compare);
    TS_ASSERT_THROWS_ANYTHING(a.getLargest());
  }
  
  void testLargest1(){
    ALG<int> a(compare);
    a.insert(5);
    TS_ASSERT_EQUALS(a.getLargest(), 5);
  }
  
  void testLargest2(){
    ALG<int> a(compare);
    a.insert(5);
    a.insert(4);
    TS_ASSERT_EQUALS(a.getLargest(), 5);
  }
  
  void testLargest3(){
    ALG<int> a(compare);
    a.insert(8);
    a.insert(6);
    TS_ASSERT_EQUALS(a.getLargest(), 8);
  }
  
  void testLargest4(){
    ALG<int> a(compare);
    a.insert(5);
    a.insert(4);
    a.insert(3);
    TS_ASSERT_EQUALS(a.getLargest(), 5);
  }
  
  void testLargest5(){
    ALG<int> a(compare);
    a.insert(1);
    a.insert(2);
    a.insert(4);
    TS_ASSERT_EQUALS(a.getLargest(), 4);
  }
};

class CopyAssign : public CxxTest::TestSuite {
public:
  // Copy Constructor
	void testCopy() {
    ALG<int> a(compare);
    a.insert(5);
    ALG<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
  }

  void testCopy1() {
    ALG<int> a(compare);
    a.insert(5);
    ALG<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
    a.insert(6);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(b.size(), 1);
  }

  void testCopy2() {
    ALG<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    ALG<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 4);
    TS_ASSERT_EQUALS(b.size(), 4);
    TS_ASSERT(a.find(5));
    TS_ASSERT(b.find(5));
  }	
  
  void testCopy3() {
    ALG<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(6);
    a.insert(8);
    ALG<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 4);
    TS_ASSERT_EQUALS(b.size(), 4);
    TS_ASSERT(!a.find(10));
    TS_ASSERT(!b.find(10));
  }	
	
	// Assignment
	
	void testAssign() {
    ALG<int> a(compare);
    a.insert(5);
    ALG<int> b(compare);
    b.insert(10);
    a = b;
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
    TS_ASSERT(a.find(10));
    TS_ASSERT(!a.find(5));
  }

  void testAssign1() {
    ALG<int> a(compare);
    a.insert(5);
    a = a;
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  

  void testCopySpeed1() { 
    ALG<int> a(compare);
    // How fast to insert 1000 elements?
    clock_t first_start = clock();
    for(int i = 0 ; i < 1000; i++){
      a.insert(rand());
    }
    clock_t pre_time = (clock() - first_start);
    
    // Make sure this is at least as fast as insertion.
    clock_t last_start = clock();
    ALG<int> b(a);
    clock_t last_stop = clock();
    // Allow 10% fudge factor
    TS_ASSERT_LESS_THAN(last_stop - last_start, pre_time * 110 / 100);
  }
  
  void testAssignSpeed1() {
    ALG<int> a(compare);
    // How fast to insert 100 elements?
    clock_t first_start = clock();
    for(int i = 0 ; i < 100; i++){
      a.insert(rand());
    }
    clock_t pre_time = (clock() - first_start);
    
    ALG<int> b(compare);
    b.insert(10);
    // Make sure this is at least as fast as insertion.
    clock_t last_start = clock();
    b = a;
    clock_t last_stop = clock();
    // Allow 10% fudge factor
    TS_ASSERT_LESS_THAN(last_stop - last_start, pre_time * 110 / 100);
  }
};

class Find : public CxxTest::TestSuite {
public:
  void testInsertFind0(){
    ALG<int> a(compare);
    TS_ASSERT(!a.find(5));
  }

  void testInsertFind1(){
    ALG<int> a(compare);
    a.insert(5);
    TS_ASSERT(a.find(5));
  }
  
  void testInsertFind2(){
    ALG<int> a(compare);
    a.insert(5);
    TS_ASSERT(!a.find(6));
  }
  
  void testInsertFind3(){  // balanced
    ALG<int> a(compare);
    a.insert(20);
    a.insert(10);
    a.insert(30);
    TS_ASSERT(a.find(20));
    TS_ASSERT(a.find(10));
    TS_ASSERT(a.find(30));
    TS_ASSERT(!a.find(40));
  }
  
  void testInsertFind4(){ // test right branch only
    ALG<int> a(compare);
    a.insert(5);
    a.insert(15);
    a.insert(25);
    a.insert(35);
    a.insert(45);
    TS_ASSERT(a.find(45));
    TS_ASSERT(a.find(35));
    TS_ASSERT(a.find(25));
    TS_ASSERT(a.find(15));
    TS_ASSERT(a.find(5));
    TS_ASSERT_EQUALS(a.size(), 5);
  }
  
  void testInsertFind5(){ // test left branch only
    ALG<int> a(compare);
    a.insert(100);
    a.insert(90);
    a.insert(80);
    a.insert(70);
    a.insert(60);
    TS_ASSERT(a.find(100));
    TS_ASSERT(a.find(90));
    TS_ASSERT(a.find(80));
    TS_ASSERT(a.find(70));
    TS_ASSERT(a.find(60));
    TS_ASSERT_EQUALS(a.size(), 5);
  }
  
  void testInsertFind6(){ // test balanced
    ALG<int> a(compare);
    a.insert(50);
    a.insert(25);
    a.insert(75);
    a.insert(10);
    a.insert(30);
    a.insert(60);
    a.insert(80);
    TS_ASSERT(a.find(80));
    TS_ASSERT(a.find(60));
    TS_ASSERT(a.find(30));
    TS_ASSERT(a.find(10));
    TS_ASSERT(a.find(75));
    TS_ASSERT(a.find(25));
    TS_ASSERT(a.find(50));
    TS_ASSERT(!a.find(5));
    TS_ASSERT_EQUALS(a.size(), 7);
  }
  
  void testInsertFind7(){  // balanced
    ALG<string> a(compare);
    a.insert("bob");
    a.insert("apple");
    a.insert("binge");
    TS_ASSERT(a.find("bob"));
    TS_ASSERT(a.find("apple"));
    TS_ASSERT(a.find("binge"));
    TS_ASSERT(!a.find("broad"));
  }
 };

class InOrders : public CxxTest::TestSuite {
public:
  void testInorder0(){
    ALG<int> a(compare);
    string out = a.getInOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[]");
  }
  
  void testInorder1(){
    ALG<int> a(compare);
    a.insert(5);
    string out = a.getInOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5]");
  }
  
  void testInorder2(){
    ALG<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    string out = a.getInOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,6,7,8]");
  }
  
  void testInorder3(){
    ALG<int> a(compare);
    a.insert(7);
    a.insert(8);
    a.insert(5);
    a.insert(6);
    string out = a.getInOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,6,7,8]");
  }
  
  void testInorder4(){
    ALG<int> a(compare);
    a.insert(8);
    a.insert(7);
    a.insert(6);
    a.insert(5);
    string out = a.getInOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,6,7,8]");
  }
  
  void testInorder5(){
    ALG<string> a(compare);
    a.insert("blue");
    a.insert("bob");
    a.insert("amy");
    a.insert("blam");
    string out = a.getInOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[amy,blam,blue,bob]");
  }
  
};

class HeightFullBalanced : public CxxTest::TestSuite {
public:

  void testHeight0() {
    ALG<int> a(compare);
    TS_ASSERT_EQUALS(a.getHeight(), 0);
  }
  
  void testHeight1() {
    ALG<int> a(compare);
    a.insert(5);
    TS_ASSERT_EQUALS(a.getHeight(), 0);
  }
  
  void testHeight2() {
    ALG<int> a(compare);
    a.insert(5);
    a.insert(6);
    TS_ASSERT_EQUALS(a.getHeight(), 1);
  }
  
  void testHeight3() {
    ALG<int> a(compare);
    a.insert(5);
    a.insert(3);
    a.insert(6);
    TS_ASSERT_EQUALS(a.getHeight(), 1);
  }
  
  void testHeight4(){
    ALG<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(10);
    a.insert(3);
    TS_ASSERT_EQUALS(a.getHeight(), 2);
  }
  
  
  void testFull0() {
    ALG<int> a(compare);
    TS_ASSERT(a.isFull());
  }
  
  void testFull1() {
    ALG<int> a(compare);
    a.insert(10);
    TS_ASSERT(a.isFull());
  }
  
  void testFull2() {
    ALG<int> a(compare);
    a.insert(10);
    a.insert(12);
    TS_ASSERT(!a.isFull());
  }
  
  void testFull3() {
    ALG<int> a(compare);
    a.insert(10);
    a.insert(12);
    a.insert(8);
    TS_ASSERT(a.isFull());
  }
  
  void testFull4() {
    ALG<int> a(compare);
    a.insert(10);
    a.insert(12);
    a.insert(8);
    a.insert(3);
    TS_ASSERT(!a.isFull());
  }
  
  void testBalanced0(){
    ALG<int> a(compare);
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced1(){
    ALG<int> a(compare);
    a.insert(5);
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced2(){
    ALG<int> a(compare);
    a.insert(5);
    a.insert(3);
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced3(){
    ALG<int> a(compare);
    a.insert(5);
    a.insert(3);
    a.insert(8);
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced4(){
    ALG<int> a(compare);
    a.insert(5);
    a.insert(3);
    a.insert(8);
    a.insert(4);
    TS_ASSERT(a.isBalanced());
  }
  
  void testBalanced5(){
    ALG<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    TS_ASSERT(!a.isBalanced());
  }
  

  void testBalanced8(){
    ALG<int> a(compare);
    for(int i = 0; i < 10; i++){
      a.insert(i);
    }
    TS_ASSERT_LESS_THAN(a.getHeight(), 9);
  }

};

class Remove : public CxxTest::TestSuite {
public:
  void testRemove0(){
    ALG<int> a(compare);
    a.remove(0);
    TS_ASSERT_EQUALS(a.size() , 0);
  }
  
  void testRemove01(){
    ALG<int> a(compare);
    a.insert(10);
    a.remove(0);
    TS_ASSERT_EQUALS(a.size() , 1);
  }
  
  void testRemove02(){
    ALG<int> a(compare);
    a.insert(10);
    a.insert(20);
    a.remove(0);
    TS_ASSERT_EQUALS(a.size() , 2);
  }
  
  void testRemove1(){
    ALG<int> a(compare);
    a.insert(5);
    a.remove(0);
    TS_ASSERT_EQUALS(a.size() , 1);
  }
  
  void testRemoveLeaf1(){
    ALG<int> a(compare);
    a.insert(5);
    a.remove(5);
    TS_ASSERT_EQUALS(a.size() , 0);
  }
  
  void testRemoveLeaf2(){
    ALG<int> a(compare);
    a.insert(5);
    a.insert(3);
    a.insert(6);
    a.remove(3);
    TS_ASSERT_EQUALS(a.size() , 2);
  }
  
  void testRemoveLeaf3(){
    ALG<int> a(compare);
    a.insert(5);
    a.insert(3);
    a.insert(6);
    a.remove(6);
    TS_ASSERT_EQUALS(a.size() , 2);
    TS_ASSERT(a.find(5));
    TS_ASSERT(!a.find(6));
  }
  
  void testRemoveLeaf4(){
    ALG<int> a(compare);
    a.insert(5);
    a.insert(3);
    a.insert(6);
    a.remove(3);
    a.remove(6);
    TS_ASSERT_EQUALS(a.size() , 1);
    TS_ASSERT(a.verifyParents());
  }
  
  void testRemoveSingle0(){
    ALG<int> a(compare);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.remove(4);
    TS_ASSERT_EQUALS(a.size() , 2);
    TS_ASSERT(a.find(3));
    TS_ASSERT(a.find(5));
    TS_ASSERT(!a.find(4));
    TS_ASSERT(a.verifyParents());
  }
  
  void testRemoveSinle1(){
    ALG<int> a(compare);
    a.insert(6);
    a.insert(5);
    a.insert(3);
    a.insert(4);
    a.remove(5);
    TS_ASSERT_EQUALS(a.size() , 3);
    TS_ASSERT(a.find(3));
    TS_ASSERT(a.find(4));
    TS_ASSERT(!a.find(5));
    TS_ASSERT(a.verifyParents());
  }
  
  void testRemoveDouble1(){
    ALG<int> a(compare);
    a.insert(6);
    a.insert(5);
    a.insert(8);
    a.remove(6);
    TS_ASSERT_EQUALS(a.size() , 2);
    TS_ASSERT(a.find(5));
    TS_ASSERT(a.find(8));
    TS_ASSERT(!a.find(6));
    TS_ASSERT(a.verifyParents());
  }
  
  void testRemoveDouble2(){
    ALG<int> a(compare);
    a.insert(6);
    a.insert(4);
    a.insert(3);
    a.insert(5);
    a.remove(4);
    TS_ASSERT_EQUALS(a.size() , 3);
    TS_ASSERT(a.find(3));
    TS_ASSERT(a.find(5));
    TS_ASSERT(a.find(6));
    TS_ASSERT(!a.find(4));
    TS_ASSERT(a.verifyParents());
  }
  
  void testRemoveDouble3(){
    ALG<int> a(compare);
    a.insert(6);
    a.insert(8);
    a.insert(7);
    a.insert(9);
    a.remove(8);
    TS_ASSERT_EQUALS(a.size() , 3);
    TS_ASSERT(a.find(7));
    TS_ASSERT(a.find(9));
    TS_ASSERT(a.find(6));
    TS_ASSERT(!a.find(8));
    TS_ASSERT(a.verifyParents());
  }
  
  void testRemoveFuzz(){
    const int SIZE = 1000;
    int numbers[SIZE];
    for(int i = 0; i < SIZE; i++){
      numbers[i] = rand() % 1000;
    }
    ALG<int> a(compare);
    // insert numbers
    for(int i = 0; i < SIZE; i++){
      a.insert(numbers[i]);
    }
    // verify they are there
    for(int i = 0; i < SIZE; i++){
      TS_ASSERT(a.find(numbers[i]));
    }
    // remove them in a random order
    permute(numbers, SIZE);
    for(int i = 0; i < SIZE; i++){
      a.remove(numbers[i]);
      TS_ASSERT_EQUALS(a.size(), SIZE - i - 1);
      TS_ASSERT(a.verifyParents());
    }
    TS_ASSERT_EQUALS(a.size(), 0);
  }
};

class Speed : public CxxTest::TestSuite {
public: 
  
  void testInsertSpeed1() {
    ALG<int> a(compare);
    // How fast to insert 100 elements in order?
    clock_t first_start = clock();
    for(int i = 0 ; i < 100; i++){
      a.insert(i);
    }
    clock_t hund_time = (clock() - first_start);
    
    // Add some more
    for(int i = 0 ; i < 400; i++){
      a.insert(i + 100);
    }
    // Now we have 500
    // Insert 100 more and make sure they are faster than O(n)
    // If it was O(n), then inserting 100 now should be about 5x as
    // slow as the first 100, so make sure it is faster.
    clock_t last2_start = clock();
    for(int i = 0 ; i < 100; i++){
      a.insert(i + 500);
    }
    clock_t last2_stop = clock();
    // Allow 20% fudge factor
    TS_ASSERT_LESS_THAN(last2_stop - last2_start, hund_time * 5 * 120 / 100);
  }
  
  
  void testFindSpeed0() {
    ALG<int> a(compare);
    // Insert a bunch of elements, worst case
    clock_t first_start = clock();
    for(int i = 0 ; i < 1000; i++){
      a.insert(i);
    }
    clock_t hund_time = (clock() - first_start);
    
    // Now search for them
    clock_t last2_start = clock();
    for(int i = 0 ; i < 1000; i++){
      TS_ASSERT(a.find(i));
    }
    clock_t last2_stop = clock();
    // Allow 20% fudge factor
    TS_ASSERT_LESS_THAN(last2_stop - last2_start, hund_time * 120 / 100);
  }
  
  void testFindSpeed1() {
    int rand_list[1000];
    for(int i = 0; i < 1000; i++){
      rand_list[i] = rand();
    }
    ALG<int> a(compare);
    // Insert a bunch of elements
    clock_t first_start = clock();
    for(int i = 0 ; i < 1000; i++){
      a.insert(rand_list[i]);
    }
    clock_t hund_time = (clock() - first_start);
    
    // Now search for them
    clock_t last2_start = clock();
    for(int i = 0 ; i < 1000; i++){
      TS_ASSERT(a.find(rand_list[1000- i - 1]));
    }
    clock_t last2_stop = clock();
    // Allow 20% fudge factor
    TS_ASSERT_LESS_THAN(last2_stop - last2_start, hund_time * 120 / 100);
  }
  
  void testInsertRemoveSpeed2(){
    const int SIZE = 10000;
    int numbers[SIZE];
    for(int i = 0; i < SIZE; i++){
      numbers[i] = rand() % 10000;
    }
    ALG<int> a(compare);
    // insert 
    clock_t starthalf = clock();
    for(int i = 0; i < SIZE/2; i++){
      a.insert(numbers[i]);
    }
    clock_t endhalf = clock();
    TS_ASSERT_EQUALS(a.size(), SIZE /2);
    // Remove half of what is there
    for(int i = 0; i < SIZE/2; i = i + 2){
      a.remove(numbers[i]);
    }
    TS_ASSERT_EQUALS(a.size(), SIZE /4);
    // Now see how long it takes to put 1/2 of them back
    clock_t start2 = clock();
    for(int i = SIZE/2; i < SIZE; i++){
      a.insert(numbers[i]);
    }
    clock_t stop2 = clock();
    // If insert is O(log n) then inserting the second half should be faster than
    // twice the first half.
    TS_ASSERT_LESS_THAN(stop2 - start2, (endhalf-starthalf) * 2 );
  }

};

#endif
