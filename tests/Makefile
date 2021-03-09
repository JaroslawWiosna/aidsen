CXXFLAGS=-I../ -std=c++17 -Wall -fno-exceptions -ggdb -O0 -fprofile-arcs -ftest-coverage
LIBS=-lgcov -coverage -lc -lm

.PHONY: run
run: rpn
	./rpn "2 3 +"
	./rpn "5 6 + 10 *"

.PHONY: coverage
coverage: run
	lcov --rc lcov_branch_coverage=1 --directory . --capture --output-file coverage.info
	lcov --rc lcov_branch_coverage=1 --list coverage.info
	genhtml --branch-coverage -o html-coverage coverage.info 
#	python -m webbrowser html-coverage/index.html

rpn: rpn.cpp ../aidsen.hpp
	$(CXX) $(CXXFLAGS) -o rpn rpn.cpp $(LIBS)

