CC=g++
CFLAGS=-c -Wall -ggdb -I.
LDFLAGS=
SOURCES=prefixsandbox.cpp Prefix.cpp suggest.cpp
EXECUTABLE=prefixsandbox
TESTS=Prefix_test.h
TESTSSOURCES=Prefix.cpp

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
	rm -rf coverage
	rm -f suggest
	
# CXX Testing	
CXXLOCATION = ../../cxxtest
CXXTESTGEN = $(CXXLOCATION)/bin/cxxtestgen

test: testrunner 
	./testrunner
	

testrunner: testrunner.cpp $(OBJECTS)
	g++ -I. -ggdb -Wall -I$(CXXLOCATION)/ -o testrunner testrunner.cpp Prefix.o
	

testrunner.cpp: $(HEADERS) $(TESTSSOURCES) $(SOURCES) $(TESTS)
	$(CXXTESTGEN) --error-printer -o testrunner.cpp $(TESTS)
	
coverage: testrunner
	rm -rf coverage
	mkdir coverage
	kcov --include-pattern=HW coverage ./testrunner
	firefox coverage/testrunner/index.html &
	
suggest: suggest.cpp $(OBJECTS)
	g++ -ggdb -Wall -O3 -o suggest suggest.cpp Prefix.o
	
	
	
