#####VARIABLES#####
###################
DEBUG ?= 0
RM = rm -rf
CXXFLAGS = -Wall -Wextra -Wpedantic  -O0  -std=c++20
CXX = g++-14
COMPILER_CALL = $(CXX) $(CXXFLAGS)

CPP_SOURCES = $(wildcard *.cc)
EXECUTE_NAME = $(patsubst %.cc,%,$(CPP_SOURCES))

ifeq ($(DEBUG),0)
	CXXFLAGS += -g0
else
	CXXFLAGS += -g2
endif
#####TARGETS#####
#################
all: build

build: $(EXECUTE_NAME)

%: %.cc
	$(COMPILER_CALL) $< -o $@

clean:
	$(RM) $(EXECUTE_NAME) *.dSYM
.PHONY: all build clean

