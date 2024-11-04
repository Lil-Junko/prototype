CXX = g++
CXXFLAGS = -Wall -g

# Source files
SRCS = main.cpp proto.cpp

# Header files
HDRS = proto.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable
TARGET = main

run: $(TARGET)
	./$(TARGET)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean