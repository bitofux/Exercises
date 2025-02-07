B := $(A) 
A = 10
# D = 5
D ?= $(A)
E = 20
VERSION = $(shell gcc --version | head -n 1)
E += $(A)
all: 
	@echo "B = $(B)"
	echo "E = $(E)"
	echo "D = $(D)"
	@echo "$(VERSION)"
