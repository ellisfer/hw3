CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test.o: llrec-test.o  llrec.o
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec-test.cpp llrec-test.o

llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) $(DEFS) -c llrec.cpp -o llrec.o

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) $(DEFS) llrec-test.o llrec.o -o llrec-test

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 