# -* MakeFile -*-
#  Usage:
#  make		# compile all binary
#  make clean	# remove All binaries and objects

.PHONY : all clean

CC = gcc
CFLAGS = -Wall -g
RM = -rm -vf *.o ${BIN}

SRC := $(filter-out exercise_5.c, $(wildcard *.c))
BIN := $(SRC:%.c=%)

all: exercise_5.o ${BIN}

%: %.c
	@echo "Creating object.."
	$(CC) $(CFLAGS) -c $<
	@echo "Linking.."
	$(CC) $(CFLAGS) $@.o exercise_5.o -o $@

exercise_5.o: exercise_5.c exercise_5.h
	@echo "creating object.."
	$(CC) -c exercise_5.c

${BIN}.o: exercise_5.o

clean:
	@echo "Cleaning up..."
	@$(RM)
