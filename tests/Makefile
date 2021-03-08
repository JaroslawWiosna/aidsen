CXXFLAGS=-I../ -std=c++17 -Wall -fno-exceptions -ggdb -O0
LIBS=-lc

.PHONY: run
run: rpn
	./rpn "2 3 * 10 +"

rpn: rpn.cpp ../aidsen.hpp
	$(CXX) $(CXXFLAGS) -o rpn rpn.cpp $(LIBS)

