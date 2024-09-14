# Define the compiler and flags
CXX = g++
CXXFLAGS = -Wall -g

# List your source files
SRCS = main.cpp player.cpp enemy.cpp gameFunctions.cpp

# Define the output file
TARGET = main

# Build the project
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Clean the project (removes the compiled binary)
clean:
	rm -f $(TARGET)

