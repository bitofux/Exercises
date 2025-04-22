SOURCES = $(wildcard *.cc)
OBJECTS = $(patsubst %.cc,%.o,$(SOURCES))

CXX = g++-14
CXXFLAGS = -std=c++11 -Wall -Wextra -Wpedantic


main: $(OBJECTS)
	$(CXX) $(CXXFLAGS)  $^ -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) main
.PHONY: clean main
