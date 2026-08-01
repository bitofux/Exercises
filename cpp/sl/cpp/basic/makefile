SRC := $(wildcard *.cc)
BIN := $(patsubst %.cc, %, $(SRC))

all: $(BIN)

%: %.cc
	$(CXX) -std=c++11 -Wall -Wextra $< -o $@ -g

clean:
	rm -f $(BIN)
