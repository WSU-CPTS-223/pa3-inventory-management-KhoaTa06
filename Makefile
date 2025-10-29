# Compliler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -g

TARGET = main

SOURCE = main.cpp parser.cpp product.cpp 

# Rule to build the executable
$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET)

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)

# Test
test: tests.cpp tests.hpp hash_table.hpp
	$(CXX) $(CXXFLAGS) -o tests tests.cpp
	./tests
