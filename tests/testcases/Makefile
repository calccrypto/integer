CXX?=g++
CXXFLAGS=-std=c++11 -Wall -g -c -I../googletest/googletest/include -I../..

include testcases.mk

.PHONY: clean

all: $(TEST_TARGETS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(TEST_TARGETS)