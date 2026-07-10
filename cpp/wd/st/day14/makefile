CXX := clang++
#CXXFLAGS := -Wall -std=c++11 -pedantic -pedantic-errors -fsanitize=address,undefined -fno-omit-frame-pointer -fno-elide-constructors -llog4cpp -lpthread

CXXFLAGS := -Wall -std=c++11 -pedantic -fsanitize=address,undefined -fno-omit-frame-pointer -fno-elide-constructors -llog4cpp -lpthread -L/usr/local/lib/

SOURCES := $(wildcard *.cc)

TARGET := $(patsubst %.cc,%.out,$(SOURCES))

.PHONY: all

all: $(TARGET)

%.out:%.cc
	$(CXX) $(CXXFLAGS) $< -o $@


.PHONY: clean
clean:
	rm -r $(TARGET) 
