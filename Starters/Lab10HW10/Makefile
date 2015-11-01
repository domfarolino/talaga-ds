CC=g++
CFLAGS=-c -Wall -ggdb -I.
LDFLAGS=
SOURCES=bstsandbox.cpp
EXECUTABLE=bstsandbox
TESTS=Random_test.h
SCAPETESTS=Scape_test.h
AVLTESTS=AVL_test.h
TESTSSOURCES=Random_test.h RandomBST.h Scape_test.h Scapegoat.h AVL_test.h AVL.h

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
	rm -f scapetestrunner*
	rm -f avltestrunner*
	rm -f *runner.cpp
	
# CXX Testing	
CXXLOCATION = ../../cxxtest
CXXTESTGEN = $(CXXLOCATION)/bin/cxxtestgen

test: testrunner scaperunner avlrunner
	./testrunner
	./scapetestrunner
	./avltestrunner
	
random: testrunner
	./testrunner

testrunner: testrunner.cpp 
	g++ -I. -ggdb -Wall -I$(CXXLOCATION)/ -o testrunner testrunner.cpp
	

testrunner.cpp: $(HEADERS) $(TESTSSOURCES) $(SOURCES)
	$(CXXTESTGEN) --error-printer -o testrunner.cpp $(TESTS)
	
	
scape: scaperunner
	./scapetestrunner

scaperunner: scaperunner.cpp 
	g++ -I. -ggdb -Wall -I$(CXXLOCATION)/ -o scapetestrunner scaperunner.cpp
	

scaperunner.cpp: $(HEADERS) $(TESTSSOURCES) $(SOURCES)
	$(CXXTESTGEN) --error-printer -o scaperunner.cpp $(SCAPETESTS)
	
avl: avlrunner
	./avltestrunner

avlrunner: avlrunner.cpp 
	g++ -I. -ggdb -Wall -I$(CXXLOCATION)/ -o avltestrunner avlrunner.cpp
	

avlrunner.cpp: $(HEADERS) $(TESTSSOURCES) $(SOURCES)
	$(CXXTESTGEN) --error-printer -o avlrunner.cpp $(AVLTESTS)
	

