CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: llrec.cpp llrec.h llrec-test.cpp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ llrec-test.cpp

#stack.o: stack.h stack_test.cpp
#	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ stack_test.cpp

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 