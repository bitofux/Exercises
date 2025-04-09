CC := gcc-14
C_STANDARD ?= -std=c11
CFLAGS := -Wall -Wextra -Wpedantic $(C_STANDARD)

SOURCES = $(wildcard *.c)
TARGETS = $(patsubst %.c,%,$(SOURCES))

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) $(TARGETS)
.PHONY:all clean
