#ifndef MYQUEUE_TEST_H
#define MYQUEUE_TEST_H

#include <MyQueue.h>

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;



class MyQueueTests : public CxxTest::TestSuite {
   
public:

  void test0(){
    MyQueue<int> a;
		a.enqueue(1);
    TS_ASSERT_EQUALS(a.size(), 1);

  }

  void test1() {
    MyQueue<int> a;
		a.enqueue(1);
		a.enqueue(2);
		a.enqueue(3);
		a.dequeue();
    TS_ASSERT_EQUALS(a.size(), 2);

  }

  void test2() {
    MyQueue<int> a;
		a.enqueue(1);
		a.enqueue(2);
		a.enqueue(3);
    TS_ASSERT_EQUALS(a.front(), 1);

  }

  void test3(){
    MyQueue<int> a;
		a.enqueue(1);
    MyQueue<int> b;
		b.enqueue(10);
		b.enqueue(20);
		a=b;
    TS_ASSERT_EQUALS(a.size(), b.size());

  }

  void test4(){
    MyQueue<int> a;
		a.enqueue(1);
    MyQueue<int> b;
		b.enqueue(10);
		b.enqueue(20);
		b=a;
    TS_ASSERT_EQUALS(a.front(), b.front());

  }

  void test5(){
    MyQueue<int> a;
		a.enqueue(1);
    MyQueue<int> b;
		b.enqueue(1);
		b.enqueue(20);
    TS_ASSERT_EQUALS(a.front(), b.front());
  }
	
  void test6() {
    MyQueue<int> a;
		a.enqueue(1);
		a.enqueue(2);
		a.enqueue(3);
		a.dequeue();
		a.dequeue();
    TS_ASSERT_EQUALS(a.front(), 3);
  }

  void test7() {
    MyQueue<int> a;
		a.enqueue(1);
		a.enqueue(2);
		a.enqueue(3);
		a.dequeue();
		a.dequeue();
    TS_ASSERT_EQUALS(a.front(), 3);
  }

  void test8() {
    MyQueue<int> a;
		a.enqueue(1);
		a.enqueue(2);
		a.enqueue(3);
    TS_ASSERT_EQUALS(a.isEmpty(),false);
  }

  void test9() {
    MyQueue<int> a;
		a.enqueue(1);
		a.enqueue(2);
		a.enqueue(3);
		a.dequeue();
		a.dequeue();
		a.dequeue();

    TS_ASSERT_EQUALS(a.isEmpty(), true);
  }

  void test10() {
    MyQueue<int> a;
		a.enqueue(1);
		a.enqueue(2);
		a.enqueue(3);
		a.dequeue();
    MyQueue<int> b;
		b.enqueue(1);
		b.enqueue(21);
		b.enqueue(300);
		b.enqueue(300);
		b.dequeue();
    TS_ASSERT_DIFFERS(a.size(), b.size());
  }

  void test11() {
    MyQueue<int> a;
		a.enqueue(1);
		a.enqueue(2);
		a.enqueue(3);
		a.dequeue();
    MyQueue<int> b;
		b.enqueue(1);
		b.enqueue(2);
		b.enqueue(3);
		b.enqueue(4);
		b.enqueue(4);
		b.dequeue();
		b.dequeue();
    TS_ASSERT_DIFFERS(a.size(), b.size());
  }

  void test12() {
    MyQueue<int> a;
		a.enqueue(1);
		a.enqueue(2);
		a.enqueue(3);
		a.dequeue();
		a.dequeue();
    TS_ASSERT_DIFFERS(a.size(), 2);
  }

  void test13() {
    MyQueue<int> a;
		a.enqueue(1);
		a.enqueue(2);
		a.enqueue(3);
		a.dequeue();
    MyQueue<int> b;
		b=a;
    TS_ASSERT_EQUALS(a.size(), b.size());
	}

  void test14() {
    MyQueue<int> a;
		a.enqueue(1);
		a.enqueue(2);
		a.enqueue(3);
		a.dequeue();
		a.dequeue();
		a.dequeue();
    TS_ASSERT_EQUALS(a.size(), 0);
  }

  void test15() {
    MyQueue<int> a;
		a.enqueue(1);
		a.enqueue(2);
		a.enqueue(3);
		a.dequeue();
		a.dequeue();
		a.dequeue();
    TS_ASSERT_THROWS_ANYTHING(a.front());
  }
  
  

  
};


#endif
