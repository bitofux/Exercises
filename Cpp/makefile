SOURCES := $(wildcard *.cc)
TARGETS := $(patsubst %.cc,%,$(SOURCES))

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wpedantic

all: $(TARGETS)

%: %.cc
	$(CXX) $(CXXFLAGS) $< -o $@

clean: 
	$(RM) $(TARGETS)
.PHONY: all clean


