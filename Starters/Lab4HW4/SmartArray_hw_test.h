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
  
};

class SmartArrayClear : public CxxTest::TestSuite {  
public:
  // .clear() tests (only need 3)
};

class SmartArrayAdd : public CxxTest::TestSuite {  
public:
  // + between two SmartArray tests
};

class SmartArrayReverse : public CxxTest::TestSuite {  
public:
  // .reverse() tests
};

class SmartArrayEquality : public CxxTest::TestSuite {  
public:
  // == and != tests
};

class SmartArrayCopyAssignment : public CxxTest::TestSuite {  
public:
  // Copy Constructor and assignment
};

class SmartArrayStream : public CxxTest::TestSuite {  
public:
  // << tests
  void testStream1(){
    SmartArray<int> a;
    a.push_back(5);
    a.push_back(6);
    // To test we stream to a stringstream, retrieve as a string,
    // remove spaces, then test the result.
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,6]");
  }
};

#endif
