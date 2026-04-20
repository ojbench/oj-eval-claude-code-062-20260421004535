CXX = g++
CXXFLAGS = -std=c++14 -O2 -Wall

all: code

code: main.cpp MemoryRiver.hpp
	$(CXX) $(CXXFLAGS) main.cpp -o code

clean:
	rm -f code test.dat
