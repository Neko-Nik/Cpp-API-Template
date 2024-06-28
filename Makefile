# Compiler and flags
CXX = c++
CXXFLAGS = -std=c++11 -I./include

# Target executable
TARGET = ./build/main_api

# Source files
SRCS = main.cpp utils/base_endpoints.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build the target
all: $(TARGET)

# Rule to link the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets to prevent conflicts with files of the same name
.PHONY: all clean
