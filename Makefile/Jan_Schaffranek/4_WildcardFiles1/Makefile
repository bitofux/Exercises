DEBUG = 1

CXX_STANDARD = c++11
CXX_WARNINGS = -Wall -Wextra -Wpedantic
CXX = g++
CXXFLAGS = $(CXX_WARNINGS) -std=$(CXX_STANDARD)

COMPILER_CALL = $(CXX) $(CXXFLAGS)
EXECUTABLE_NAME = mainDebug


ifeq ($(DEBUG),1)
	CXXFLAGS += -g -O0
	EXECUTABLE_NAME = mainDebug
else
	CXXFLAGS += -O3
	EXECUTABLE_NAME = mainRelease
endif

main: main.o mylib.o
	$(COMPILER_CALL) mylib.o main.o -o $(EXECUTABLE_NAME)

%.o: %.cc
	$(COMPILER_CALL) -c $< -o $@

execute:
	./$(EXECUTABLE_NAME)

clean:
	$(RM) *.o
	$(RM) $(EXECUTABLE_NAME)

