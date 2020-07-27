# -* MakeFile -*-
#  Usage:
#  make		# compile all binary
#  make clean	# remove All binaries and objects

.PHONY : all clean

CC = gcc
CFLAGS = -Wall -g
RM = -rm -vf *.o ${BIN} ex4.7 ex4.8 ex4.9

EXERCISE = exercise_4.c ex4.7.c ex4.8.c ex4.9.c
SRC := $(filter-out $(EXERCISE), $(wildcard *.c))
BIN := $(SRC:%.c=%)

all: exercise_4.o ${BIN} ex4.7 ex4.8 ex4.9

%: %.c
	@echo "Creating object.."
	$(CC) $(CFLAGS) -c $<
	@echo "Linking.."
	$(CC) $(CFLAGS) $@.o exercise_4.o -lm -o $@

exercise_4.o: exercise_4.c exercise_4.h
	@echo "Creating object.."
	$(CC) -c exercise_4.c

ex4.7: ex4.7.c
	$(CC) $(CFLAGS) $< -o $@

ex4.8: ex4.8.c
	$(CC) $(CFLAGS) $< -o $@

ex4.9: ex4.9.c
	$(CC) $(CFLAGS) $< -o $@

${BIN}.o: exercise_4.o

clean:
	@echo "Cleaning up..."
	@$(RM)
