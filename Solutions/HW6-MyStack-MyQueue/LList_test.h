#ifndef LLIST_TEST_H
#define LLIST_TEST_H

#include <LList.h>
#include <stdexcept>

#include <sstream>
#include <algorithm>
#include <cxxtest/TestSuite.h>

using namespace std;



class LListConCopyAssign : public CxxTest::TestSuite {
   
public:
  
  
  void testEmpty() {
    LList<int> a;
    TS_ASSERT_EQUALS(a.size(), 0);
		
  }
  
  // Copy Constructor
	void testCopy() {
    LList<int> a;
    a.push_back(5);
    LList<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
		  }

  void testCopy1() {
    LList<int> a;
    a.push_back(5);
    LList<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
    a.push_front(10);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(b.size(), 1);
		
  }

  void testCopy2() {
    LList<int> a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    a.push_back(8);
    LList<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 4);
    TS_ASSERT_EQUALS(b.size(), 4);
    TS_ASSERT_EQUALS(a.getAt(3), 8);
    TS_ASSERT_EQUALS(b.getAt(3), 8);
		
  }	
	
	
	
	void testAssign() {
    LList<int> a;
    a.push_back(5);
    LList<int> b;
    b.push_back(10);
    a = b;
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
    TS_ASSERT_EQUALS(a.getAt(0), 10);
    TS_ASSERT_EQUALS(b.getAt(0), 10);
		
  }

  void testAssign1() {
    LList<int> a;
    a.push_back(5);
    a = a;
    TS_ASSERT_EQUALS(a.size(), 1);
		
  }
  
};

class LListPushes : public CxxTest::TestSuite {
public:

  void testPushBack1() {
    LList<int> a;
    TS_ASSERT_EQUALS(a.size(), 0);
		

  }

  void testPushBack2() {
    LList<int> a;
    a.push_back(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.push_back(6);
    TS_ASSERT_EQUALS(a.size(), 2);
		
  }
  
  void testPushBack3() {
    LList<string> a;
    a.push_back("hi");
    TS_ASSERT_EQUALS(a.size(), 1);
    a.push_back("bib");
    TS_ASSERT_EQUALS(a.size(), 2);
    a.push_back("bill");
    TS_ASSERT_EQUALS(a.size(), 3);
		
  }

  void testPushFront2() {
    LList<int> a;
    a.push_front(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.push_front(6);
    TS_ASSERT_EQUALS(a.size(), 2);
		
  }
  
  void testPushFront3() {
    LList<int> a;
    a.push_front(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.push_front(6);
    TS_ASSERT_EQUALS(a.size(), 2);
    a.push_front(7);
    TS_ASSERT_EQUALS(a.size(), 3);
		
  }
};

class LListSetAt : public CxxTest::TestSuite {
public:

  void testSet1() {
    LList<int> a;
    a.push_back(5);
    a.push_back(6);
		a.setAt(10,0);
    TS_ASSERT_EQUALS(a.getAt(0), 10);
		TS_ASSERT_EQUALS(a.getAt(1), 6);
		
  }
	
  void testSet2() {
    LList<int> a;
    a.push_back(5);
    a.push_back(6);
    TS_ASSERT_THROWS_ANYTHING(a.setAt(99,2));
		
  }
	
  void testSet3() {
    LList<int> a;
    a.push_back(5);
    a.push_back(6);
    TS_ASSERT_THROWS_ANYTHING(a.setAt(99,-3));
		
  }
	
  void testSet4() {
    LList<int> a;
    a.push_back(5);
    a.push_back(6);
		a.setAt(10,-1);
		TS_ASSERT_EQUALS(a.getAt(0), 5);
    TS_ASSERT_EQUALS(a.getAt(1), 10);
		
  }
	
	void testSet5() {
    LList<int> a;
    a.push_back(5);
    a.push_back(6);
		a.setAt(10,-2);
		TS_ASSERT_EQUALS(a.getAt(0), 10);
    TS_ASSERT_EQUALS(a.getAt(1), 6);
		
  }
	
};

class LListGetAt : public CxxTest::TestSuite {
public:

  void testGetAt1() {
    LList<int> a;
		TS_ASSERT_THROWS_ANYTHING(a.getAt(0));
		
  }
  
  void testGetAt2() {
    LList<int> a;
    a.push_back(5);
    TS_ASSERT_EQUALS(a.getAt(0), 5);
    TS_ASSERT_EQUALS(a.getAt(-1), 5);
    TS_ASSERT_THROWS_ANYTHING(a.getAt(-2));
		//cout<<"test passed"<<endl;
  }
  
  void testGetAt3() {
    LList<int> a;
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
};

class LListRemove : public CxxTest::TestSuite {
public:

  void testRemove1() {
    LList<int> a;
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_THROWS_ANYTHING(a.remove(0));
		
  }
  
  void testRemove2() {
    LList<int> a;
    a.push_front(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.remove(0);
    TS_ASSERT_EQUALS(a.size(), 0);
		
  }
  
  void testRemove3() {
    LList<int> a;
    a.push_front(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.remove(-1);
    TS_ASSERT_EQUALS(a.size(), 0);
		
  }
  
  void testRemove4() {
    LList<int> a;
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
    LList<int> a;
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
    LList<int> a;
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
    LList<int> a;
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
};

class LListReverse : public CxxTest::TestSuite {
public:
  void testRev0() {
    LList<int> a;
    LList<int> b = a.reverse();
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_EQUALS(b.size(), 0);
		
  }
  
  void testRev1() {
    LList<int> a;
    a.push_back(5);
    LList<int> b = a.reverse();
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
    TS_ASSERT_EQUALS(a.getAt(0), 5);
    TS_ASSERT_EQUALS(b.getAt(0), 5);
		
  }
  
  void testRev2() {
    LList<int> a;
    a.push_back(5);
    a.push_back(6);
    LList<int> b = a.reverse();
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(b.size(), 2);
    TS_ASSERT_EQUALS(a.getAt(0), 5);
    TS_ASSERT_EQUALS(b.getAt(0), 6);
    TS_ASSERT_EQUALS(a.getAt(1), 6);
    TS_ASSERT_EQUALS(b.getAt(1), 5);
		
  }
  
  void testRev3() {
    LList<int> a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    LList<int> b = a.reverse();
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
    LList<int> a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    a.push_back(8);
    LList<int> b = a.reverse();
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

class LListAdd : public CxxTest::TestSuite {
public:
  void testAdd0() {
    LList<int> c = LList<int>() + LList<int>();
    TS_ASSERT_EQUALS(c.size(), 0);
  }
  
  void testAdd1() {
    LList<int> a;
    a.push_back(5);
    LList<int> b;
    b.push_back(10);
    LList<int> c = a + b;
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
    TS_ASSERT_EQUALS(c.size(), 2);
    TS_ASSERT_EQUALS(c.getAt(0), 5);
    TS_ASSERT_EQUALS(c.getAt(1), 10);

  }
  
  void testAdd2() {
    LList<int> a;
    LList<int> b;
    b.push_back(10);
    b.push_back(11);
    LList<int> c = a + b;
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

class LListEq : public CxxTest::TestSuite {
public:
  void testEq0() {
    LList<int> a;
    LList<int> b;
    TS_ASSERT( a == b);
    TS_ASSERT( !(a != b));
  }
  
  void testEq1() {
    LList<int> a;
    a.push_back(6);
    LList<int> b;
    b.push_front(6);
    TS_ASSERT( a == b);
    TS_ASSERT( !(a != b));
  }
  
  void testEq2() {
    LList<int> a;
    a.push_back(6);
    LList<int> b;
    TS_ASSERT( a != b);
    TS_ASSERT( !(a == b));
  }
  
  void testEq3() {
    LList<int> a;
    LList<int> b;
    b.push_front(6);
    TS_ASSERT( a != b);
    TS_ASSERT( !(a == b));
  }
  
  void testEq4() {
    LList<int> a;
    a.push_back(6);
    LList<int> b;
    a.push_front(7);
    TS_ASSERT( a != b);
    TS_ASSERT( !(a == b));
  }
  
  void testEq5() {
    LList<int> a;
    a.push_front(5);
    a.push_back(6);
    LList<int> b;
    b.push_front(6);
    b.push_front(5);
    TS_ASSERT( a == b);
    TS_ASSERT( !(a != b));
  }
};

class LListClear : public CxxTest::TestSuite {
public:
  void testClear0() {
    LList<int> a;
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testClear1() {
    LList<int> a;
    a.push_back(6);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testClear2() {
    LList<int> a;
    a.push_back(6);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
    a.push_back(7);
    TS_ASSERT_EQUALS(a.getAt(0), 7);
  }
};

class LListStream : public CxxTest::TestSuite {
public:
  void testStream1(){
    LList<int> a;
    a.push_back(5);
    a.push_back(6);
    
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,6]");
  }
  
  void testStream2(){
    LList<int> a;
    
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[]");
  }
  
  void testStream3(){
    LList<float> a;
    a.push_back(5.5);
    
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5.5]");
  }
  
  void testStream4(){
    LList<string> a;
    a.push_back("stuff");
    a.push_back("more");
    
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[stuff,more]");
  }
  
  void testStream5(){
    LList<int> a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,6,7]");
  }
};


class LListFuzz : public CxxTest::TestSuite {
public:

  void testFuzz() {
    LList<int> a;
    const int size = 200;
    for(int i = 0; i < size; i++){
      a.push_back(i);
			a.push_back(i);
      a.push_front(i);
      a.remove(-1);
      TS_ASSERT_EQUALS(a.size(), (i+1) * 2);
    }
    
    long long int count = 0;
    for(int i = 0; i < a.size(); i++){
      count = count +  a.getAt(i);
    }
    TS_ASSERT_EQUALS(count, size * (size - 1)); 
    TS_ASSERT_EQUALS(a.size(), size * 2);
    
    for(int i = 0; i < size; i++){
      a.remove(-1);
      a.remove(0);
    }
    TS_ASSERT_EQUALS(a.size(), 0);
  }
};


#endif
