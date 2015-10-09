CC=g++
CFLAGS=-c -Wall -ggdb -I.
LDFLAGS=
SOURCES=listsandbox.cpp 
EXECUTABLE=listsandbox
TESTS=MyStack_test.h MyQueue_test.h
TESTFILES = LList.h MyStack.h MyQueue.h

OBJECTS=$(SOURCES:.cpp=.o)


FLAGS   = -Iinclude

all: $(SOURCES) $(EXECUTABLE)
	

# These next lines do a bit of magic found from http://stackoverflow.com/questions/2394609/makefile-header-dependencies
# Essentially it asks the compiler to read the .cpp files and generate the needed .h dependencies.
# This way if any .h file changes the correct .cpp files will be recompiled
depend: .depend

.depend: $(SOURCES)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ >> ./.depend;

include .depend
# End .h file magic

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o $(EXECUTABLE)
	rm -f ./.depend
	rm -f testrunner*
	rm -f labtestrunner*
	
# CXX Testing	
CXXLOCATION = ../../cxxtest
CXXTESTGEN = $(CXXLOCATION)/bin/cxxtestgen

test: testrunner
	./testrunner

testrunner: testrunner.cpp 
	g++ -I. -I$(CXXLOCATION)/ -o testrunner testrunner.cpp
	

testrunner.cpp: $(HEADERS) $(SOURCES) $(TESTFILES)
	$(CXXTESTGEN) --error-printer -o testrunner.cpp $(TESTS)
	
labtest: labtestrunner
	./testrunnerl

labtestrunner: labtestrunner.cpp 
	g++ -I. -I$(CXXLOCATION)/ -o testrunnerl labtestrunner.cpp
	

labtestrunner.cpp: $(HEADERS) $(SOURCES) $(TESTFILES)
	$(CXXTESTGEN) --error-printer -o labtestrunner.cpp LList_test.h 


