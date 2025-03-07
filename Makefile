CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

# Compile llrec-test.o from llrec-test.cpp
llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec-test.cpp -o llrec-test.o

# Compile llrec.o from llrec.cpp
llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec.cpp -o llrec.o

# Link the final executable
llrec-test: llrec-test.o llrec.o
	$(CXX) $(CXXFLAGS) llrec-test.o llrec.o -o llrec-test

clean:
	rm -f *.o llrec-test *~

.PHONY: clean
