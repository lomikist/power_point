# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -g -Iinc -Wall -Wextra -O2

# Directories
SRCDIR = src
INCDIR = inc
OBJDIR = obj

# Source and object files
SRC = main.cpp $(SRCDIR)/parser.cpp
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)

# Output binary
TARGET = a.out

# Default target
all: $(TARGET)

# Create the binary
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Create object files
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure the object directory exists
$(OBJDIR):
	mkdir -p $(OBJDIR)/$(SRCDIR)

# Clean up object files and binary
clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: all clean

