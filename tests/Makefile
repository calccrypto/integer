CXX?=g++
CXXFLAGS=-std=c++11 -Wall -g -Igoogletest/googletest/include -I..
LDFLAGS=-Lgoogletest/googlemock/gtest -lgtest -lpthread
TARGET=test

# DIGIT_T and DOUBLE_DIGIT_T can be defined by the user
DIGIT_T?=uint8_t
DOUBLE_DIGIT_T?=uint64_t
CXXFLAGS+=-DINTEGER_DIGIT_T=$(DIGIT_T) -DINTEGER_DOUBLE_DIGIT_T=${DOUBLE_DIGIT_T}

TESTCASES=  testcases/constructor.o   \
            testcases/assignment.o    \
            testcases/typecast.o      \
            testcases/accessors.o     \
            testcases/and.o           \
            testcases/or.o            \
            testcases/xor.o           \
            testcases/inverse.o       \
            testcases/leftshift.o     \
            testcases/rightshift.o    \
            testcases/logical.o       \
            testcases/gt.o            \
            testcases/gte.o           \
            testcases/lt.o            \
            testcases/lte.o           \
            testcases/equals.o        \
            testcases/notequals.o     \
            testcases/add.o           \
            testcases/sub.o           \
            testcases/mult.o          \
            testcases/div.o           \
            testcases/mod.o           \
            testcases/fix.o           \
            testcases/unary.o         \
            testcases/functions.o

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
	rm -f $(TARGET) ../integer.o $(TESTCASES)
