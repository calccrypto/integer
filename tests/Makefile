CXX?=g++
CXXFLAGS=-std=c++11 -Wall -g -Igoogletest/googletest/include -I..
LDFLAGS=-Lgoogletest/googlemock/gtest -lgtest -lpthread
TARGET=test

# DIGIT_T and DOUBLE_DIGIT_T can be defined by the user
DIGIT_T?=uint8_t
DOUBLE_DIGIT_T?=uint64_t
CXXFLAGS+=-DINTEGER_DIGIT_T=$(DIGIT_T) -DINTEGER_DOUBLE_DIGIT_T=$(DOUBLE_DIGIT_T)

TESTCASES  =
TESTCASES += testcases/constructor.o
TESTCASES += testcases/assignment.o
TESTCASES += testcases/typecast.o
TESTCASES += testcases/accessors.o
TESTCASES += testcases/and.o
TESTCASES += testcases/or.o
TESTCASES += testcases/xor.o
TESTCASES += testcases/invert.o
TESTCASES += testcases/leftshift.o
TESTCASES += testcases/rightshift.o
TESTCASES += testcases/logical.o
TESTCASES += testcases/gt.o
TESTCASES += testcases/gte.o
TESTCASES += testcases/lt.o
TESTCASES += testcases/lte.o
TESTCASES += testcases/equals.o
TESTCASES += testcases/notequals.o
TESTCASES += testcases/add.o
TESTCASES += testcases/sub.o
TESTCASES += testcases/mult.o
TESTCASES += testcases/div.o
TESTCASES += testcases/mod.o
TESTCASES += testcases/fix.o
TESTCASES += testcases/unary.o
TESTCASES += testcases/functions.o

all: $(TARGET)

.PHONY: clean clean-all

$(TESTCASES): %.o : %.cpp ../integer.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

../integer.o: ../integer.cpp
	$(CXX) $(CXXFLAGS) -c ../integer.cpp -o $@

$(TARGET): test.cpp ../integer.o $(TESTCASES)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

clean-all:
	rm -f ../integer.o $(TESTCASES)
