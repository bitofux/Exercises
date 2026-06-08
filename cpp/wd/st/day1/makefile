CXX := g++
CXXFLAGS := -Wall  -std=c++11 -g

SOURCES := $(wildcard *.cc)

TARGET := $(patsubst %.cc,%,$(SOURCES))

.PHONY: all

all: $(TARGET)

%:%.cc
	$(CXX) $(CXXFLAGS) $< -o $@


.PHONY: clean
clean:
	rm -r $(TARGET) *.dSYM
