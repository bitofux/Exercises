SRC := $(wildcard *.c)
BIN := $(patsubst %.c, %, $(SRC))

CFLAGS = -I lib/ -L lib/ -lheader
all: $(BIN)

%: %.c
	$(CC) -std=c11 -Wall -Wextra -D_POSIX_C_SOURCE=199309L $< -o $@ -g $(CFLAGS)

clean:
	rm -f $(BIN)
