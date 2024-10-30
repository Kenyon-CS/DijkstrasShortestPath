# Makefile for main.cpp

# Compiler to use
CXX = g++

# Compiler flags:
# -std=c++11 : Use the C++11 standard
# -Wall      : Enable all compiler's warning messages
# -Wextra    : Enable some extra warning flags
# -pedantic  : Enforce strict ISO C++ compliance
# -O2        : Optimize the code for better performance
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -O2

# Target executable name
TARGET = Dijkstras

# Source files
SRC = main.cpp

# Object files (if you have multiple sources, list them here)
OBJ = $(SRC:.cpp=.o)

# Default target when 'make' is run without arguments
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Rule to clean up generated files
clean:
	rm -f $(TARGET) $(OBJ)

# Phony targets are not actual files
.PHONY: all clean
