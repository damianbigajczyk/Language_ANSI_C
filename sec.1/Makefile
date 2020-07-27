# -* MakeFile -*-

CC = gcc
CFLAGS = -Wall -g

SRCS := $(wildcard *.c)
BINS := $(SRCS:%.c=%)

all: ${BINS}

clean: 
	@echo "Cleaning up..."
	rm -v ${BINS}
