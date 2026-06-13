CXX := clang++
CXXFLAGS := -Wall -std=c++11 -pedantic -pedantic-errors -fsanitize=address,undefined -fno-omit-frame-pointer -fno-elide-constructors 

SOURCES := $(wildcard *.cc)

TARGET := $(patsubst %.cc,%,$(SOURCES))

.PHONY: all

all: $(TARGET)

%:%.cc
	$(CXX) $(CXXFLAGS) $< -o $@


.PHONY: clean
clean:
	rm -r $(TARGET) 
