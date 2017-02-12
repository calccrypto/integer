TESTCASES=
TESTCASES += constructor.cpp
TESTCASES += assignment.cpp
TESTCASES += typecast.cpp
TESTCASES += accessors.cpp
TESTCASES += and.cpp
TESTCASES += or.cpp
TESTCASES += xor.cpp
TESTCASES += inverse.cpp
TESTCASES += leftshift.cpp
TESTCASES += rightshift.cpp
TESTCASES += logical.cpp
TESTCASES += gt.cpp
TESTCASES += gte.cpp
TESTCASES += lt.cpp
TESTCASES += lte.cpp
TESTCASES += equals.cpp
TESTCASES += notequals.cpp
TESTCASES += add.cpp
TESTCASES += sub.cpp
TESTCASES += mult.cpp
TESTCASES += div.cpp
TESTCASES += mod.cpp
TESTCASES += fix.cpp
TESTCASES += unary.cpp
TESTCASES += functions.cpp

TEST_TARGETS=$(TESTCASES:.cpp=.o)
