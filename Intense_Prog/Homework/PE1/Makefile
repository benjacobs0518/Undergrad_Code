CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: target1

target1: Point.o main.cpp
	$(CXX) $(CXXFLAGS) main.cpp Point.o -o main

Point.o: Point.cpp
	$(CXX) $(CXXFLAGS) -c Point.cpp

clean:
	rm Point.o main
