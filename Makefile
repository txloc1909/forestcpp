# example taken from: https://stackoverflow.com/a/52036564

CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -pedantic -std=c++17

SOURCES := $(wildcard *.cpp)
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))
DEPENDS := $(patsubst %.cpp,%.d,$(SOURCES))

# .PHONY means these rules get executed even if files of those names exists
.PHONY: all clean run

all: main run

clean:
	rm $(OBJECTS) $(DEPENDS) main

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

-include $(DEPENDS)

%.o: %.cpp Makefile
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

run: main
	./main
