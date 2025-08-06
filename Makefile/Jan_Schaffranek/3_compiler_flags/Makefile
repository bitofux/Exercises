DEBUG = 1

CXX_STANDARD = c++11
CXX_WARNINGS = -Wall -Wextra -Wpedantic
CXX = g++
CXXFLAGS = $(CXX_WARNINGS) -std=$(CXX_STANDARD)

COMPILER_CALL = $(CXX) $(CXXFLAGS)
EXECUTABLE_NAME = main

ifeq ($(DEBUG),1)
	CXXFLAGS += -g -O0
else
	CXXFLAGS += -O3
endif
main: main.o mylib.o
	$(COMPILER_CALL) mylib.o main.o -o $(EXECUTABLE_NAME)

main.o: 
	$(COMPILER_CALL) -c main.cc

mylib.o:
	$(COMPILER_CALL) -c mylib.cc

execute:
	./$(EXECUTABLE_NAME)

clean:
	$(RM) *.o
	$(RM) main

