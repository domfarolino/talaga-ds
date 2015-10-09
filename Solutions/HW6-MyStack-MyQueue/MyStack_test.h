#ifndef MYSTACK_TEST_H
#define MYSTACK_TEST_H

#include "MyStack.h"

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;



class MyStackTests : public CxxTest::TestSuite {
   
public:
  
		
  void test0(){
    MyStack<int> a;
		a.push(1);
    TS_ASSERT_EQUALS(a.size(), 1);

  }

  void test1() {
    MyStack<int> a;
		a.push(1);
		a.push(2);
		a.push(3);
		a.pop();
    TS_ASSERT_EQUALS(a.size(), 2);

  }

  void test2() {
    MyStack<int> a;
		a.push(1);
		a.push(2);
		a.push(3);
    TS_ASSERT_EQUALS(a.top(), 3);

  }

  void test3(){
    MyStack<int> a;
		a.push(1);
    MyStack<int> b;
		b.push(10);
		b.push(20);
		a=b;
    TS_ASSERT_EQUALS(a.size(), b.size());

  }

  void test4(){
    MyStack<int> a;
		a.push(1);
    MyStack<int> b;
		b.push(10);
		b.push(20);
		a=b;
    TS_ASSERT_EQUALS(a.top(), b.top());

  }

  void test5(){
    MyStack<int> a;
		a.push(1);
    MyStack<int> b;
		b.push(10);
		b.push(20);
		a=b;
    TS_ASSERT_EQUALS(a.top(), b.top());
  }
	
  void test6() {
    MyStack<int> a;
		a.push(1);
		a.push(2);
		a.push(3);
		a.pop();
		a.pop();
    TS_ASSERT_EQUALS(a.top(), 1);
  }

  void test7() {
    MyStack<int> a;
		a.push(1);
		a.push(2);
		a.push(3);
		a.pop();
		a.pop();
    TS_ASSERT_EQUALS(a.top(), 1);
  }

  void test8() {
    MyStack<int> a;
		a.push(1);
		a.push(2);
		a.push(3);
    TS_ASSERT_EQUALS(a.isEmpty(),false);
  }

  void test9() {
    MyStack<int> a;
		a.push(1);
		a.push(2);
		a.push(3);
		a.pop();
		a.pop();
    MyStack<int> b;
		b.push(1);
		b.push(21);
		b.push(300);
		b.push(300);
		b.pop();
		b.pop();
		b.pop();
    TS_ASSERT_EQUALS(a.top(), b.top());
  }

  void test10() {
    MyStack<int> a;
		a.push(1);
		a.push(2);
		a.push(3);
		a.pop();
    MyStack<int> b;
		b.push(1);
		b.push(21);
		b.push(300);
		b.push(300);
		b.pop();
    TS_ASSERT_DIFFERS(a.size(), b.size());
  }

  void test11() {
    MyStack<int> a;
		a.push(1);
		a.push(2);
		a.push(3);
		a.pop();
    MyStack<int> b;
		b.push(1);
		b.push(2);
		b.push(3);
		b.push(4);
		b.push(4);
		b.pop();
		b.pop();
    TS_ASSERT_DIFFERS(a.size(), b.size());
  }

  void test12() {
    MyStack<int> a;
		a.push(1);
		a.push(2);
		a.push(3);
		a.pop();
    TS_ASSERT_DIFFERS(a.size(), 3);
  }

  void test13() {
    MyStack<int> a;
		a.push(1);
		a.push(2);
		a.push(3);
		a.pop();
    MyStack<int> b;
		b=a;
    TS_ASSERT_EQUALS(a.size(), b.size());
	}

  void test14() {
    MyStack<int> a;
		a.push(1);
		a.push(2);
		a.push(3);
		a.pop();
		a.pop();
		a.pop();
    TS_ASSERT_EQUALS(a.size(), 0);
  }

  void test15() {
    MyStack<int> a;
		a.push(1);
		a.push(2);
		a.push(3);
		a.pop();
		a.pop();
		a.pop();
    TS_ASSERT_THROWS_ANYTHING(a.top());
  }
};


#endif
