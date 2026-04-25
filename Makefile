CXX = g++

# Compiler flags: 
# -Wall -Wextra : turns on warnings to help catch bugs
# -O3           : highly optimizes the code for speed (crucial for big matrices!)
# -std=c++11    : ensures standard C++11 compliance
CXXFLAGS = -Wall -Wextra -O3 -std=c++11

TARGETS = part1 part2

all: $(TARGETS)

part1: part1.cpp
	$(CXX) $(CXXFLAGS) -o part1 part1.cpp

part2: part2.cpp
	$(CXX) $(CXXFLAGS) -o part2 part2.cpp

clean:
	rm -f $(TARGETS)