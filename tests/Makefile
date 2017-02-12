CXX?=g++
CXXFLAGS+=-std=c++11 -Wall -g -Igoogletest/googletest/include -I..
LDFLAGS+=-Lgoogletest/googlemock/gtest -lgtest -lpthread
TARGET=test

include testcases/testcases.mk

all: testcases $(TARGET)

.PHONY: testcases clean clean-all

testcases:
	$(MAKE) -C testcases $(TEST_TARGETS)

../integer.o: ../integer.h ../integer.cpp
	$(MAKE) clean -C testcases
	$(CXX) $(CXXFLAGS) -c  ../integer.cpp -o ../integer.o

$(TARGET): test.cpp ../integer.o $(addprefix testcases/, $(TEST_TARGETS))
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

clean-all: clean
	$(MAKE) clean -C testcases
	rm -f ../integer.o
