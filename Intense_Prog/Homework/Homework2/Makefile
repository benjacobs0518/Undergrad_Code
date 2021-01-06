CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: main test

clean:
		rm main test

main: Counter.hpp main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main

test: Counter.hpp test.cpp
	$(CXX) $(CXXFLAGS) test.cpp -o test
