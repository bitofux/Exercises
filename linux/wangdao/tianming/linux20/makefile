SRC := $(wildcard *.c)
BIN := $(patsubst %.c, %, $(SRC))

all: $(BIN)

%: %.c
	$(CC) -std=c11 -Wall -Wextra $< -o $@ -g

clean:
	rm -f $(BIN)
