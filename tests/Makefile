CXX?=g++
CXXFLAGS=-std=c++11 -Wall -g -D_POSIX_C_SOURCE=200809L -I../../googletest/googletest/include -I..
LDFLAGS=-L../../googletest/build/lib -lgtest -lgtest_main -lpthread
TARGET=tests

# DIGIT_T and DOUBLE_DIGIT_T can be defined by the user
DIGIT_T?=uint8_t
DOUBLE_DIGIT_T?=uint64_t
CXXFLAGS+=-DINTEGER_DIGIT_T=$(DIGIT_T) -DINTEGER_DOUBLE_DIGIT_T=$(DOUBLE_DIGIT_T)

include objects.mk

all: $(TARGET)

.PHONY: clean clean-all

../integer.o: ../integer.h ../integer.cpp
	$(CXX) $(CXXFLAGS) -c ../integer.cpp -o $@

$(INTEGER_TESTCASES_OBJECTS): %.o : %.cpp ../integer.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): ../integer.o $(INTEGER_TESTCASES_OBJECTS)
	$(CXX) $(CXXFLAGS) ../integer.o $(INTEGER_TESTCASES_OBJECTS) $(LDFLAGS) -o $(TARGET)

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(INTEGER_TESTCASES_OBJECTS) $(TARGET)

clean-all: clean
	rm -f ../integer.o
