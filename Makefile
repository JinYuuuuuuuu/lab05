# Makefile for the heap project

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Build target
TARGET = examheap

# Object files
OBJS = heap.o examheap.o

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX)	$(CXXFLAGS)	-o	$(TARGET)	$(OBJS)

heap.o: heap.cpp heap.h
	$(CXX)	$(CXXFLAGS)	-c heap.cpp

examheap.o: examheap.cpp heap.h
	$(CXX)	$(CXXFLAGS)	-c	examheap.cpp

# Clean rule
clean:
	rm -f $(TARGET) $(OBJS)
