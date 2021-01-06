CXX = g++ -g
CXXFLAGS	= -std=c++11 -Wall

all: ElectoralMap

clean:
	rm ElectoralMap ElectoralMap.o District.o Election.o TextUI.o

ElectoralMap: main.cpp ElectoralMap.o District.o Election.o TextUI.o
	$(CXX) $(CXXFLAGS) main.cpp ElectoralMap.o District.o Election.o TextUI.o -o ElectoralMap

ElectoralMap.o: ElectoralMap.cpp
	$(CXX) $(CXXFLAGS) -c ElectoralMap.cpp

District.o: District.cpp
	$(CXX) $(CXXFLAGS) -c District.cpp

Election.o: Election.cpp
	$(CXX) $(CXXFLAGS) -c Election.cpp

TextUI.o: TextUI.cpp
	$(CXX) $(CXXFLAGS) -c TextUI.cpp
