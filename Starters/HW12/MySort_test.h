#ifndef SORT_TEST_H
#define SORT_TEST_H

#include "MySort.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cxxtest/TestSuite.h>

using namespace std;

class SortTest : public CxxTest::TestSuite {
public:
  void (*f)(vector<int>& list);
  
  void setUp(){
    // TODO:
  }
  
  void testisSortedEmpty() {
   // TODO:
  }
  
  // TODO:
  
};

#endif
