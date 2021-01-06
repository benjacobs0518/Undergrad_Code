# defines the variables that will be reused
CXX = g++
CXXFLAGS = -std=c++17 -Wall

#runs for make all, makes targets needed to bring the exectuated up to date
all: main

#runs for "make main"
main: pe3_references.o
	$(CXX) $(CXXFLAGS) -o main pe3_references.o

main.o: pe3_references.cpp
	$(CXX) $(CXXFLAGS) -c pe3_references.cpp

# runs "make clean"
clean:
	rm pe3_references.o main
