
CXX = g++  # the compiler
CXXFLAGS = -std=c++17 -Wall

all: run_library

clean:
	rm Library.o run_library

run_library: Library.o run_library.cpp
	$(CXX) $(CXXFLAGS) run_library.cpp Library.o -o run_library

Library.o: Library.cpp
	$(CXX) $(CXXFLAGS) -c Library.cpp
