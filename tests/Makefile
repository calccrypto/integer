CXX?=g++
CXXFLAGS=-std=c++11 -Wall -g -D_POSIX_C_SOURCE=200809L -I../../googletest/googletest/include -I..
LDFLAGS=-L../../googletest/build/lib -lgtest -lgtest_main -lpthread
TARGET=test

# DIGIT_T and DOUBLE_DIGIT_T can be defined by the user
DIGIT_T?=uint8_t
DOUBLE_DIGIT_T?=uint64_t
CXXFLAGS+=-DINTEGER_DIGIT_T=$(DIGIT_T) -DINTEGER_DOUBLE_DIGIT_T=$(DOUBLE_DIGIT_T)

include testcases/objects.mk

all: $(TARGET)

.PHONY: testcases run clean clean-all

testcases:
	$(MAKE) -C testcases

../integer.o: ../integer.h ../integer.cpp
	$(CXX) $(CXXFLAGS) -c ../integer.cpp -o $@

$(TARGET): ../integer.o testcases
	$(CXX) $(CXXFLAGS) ../integer.o $(addprefix testcases/, $(INTEGER_TESTCASES_OBJECTS)) $(LDFLAGS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

clean-all:
	rm -f ../integer.o
	$(MAKE) clean -C testcases
