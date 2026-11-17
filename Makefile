CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
SRCS     = $(wildcard exp*.cpp)
BINS     = $(SRCS:.cpp=)

all: $(BINS)
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
clean:
	rm -f $(BINS) students.csv
