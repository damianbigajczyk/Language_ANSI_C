# -*- MakeFile -*-
#  Usage:
#  make		# compile all binary
#  make clean	# remove All binaries and objects

.PHONY : all clean

CC = gcc
CFLAGS = -Wall -g
RM = -rm -vf *.o ${BIN} sortlines

SRC := $(wildcard ex5.*.c)
BIN := $(SRC:%.c=%)
BASE = exercise_5.o stack.o myctype.o

all: ${BIN} sortlines

ex5.1: ex5.1.o $(BASE)
	$(CC) $(CFLAGS) -o ex5.1 ex5.1.o $(BASE)

ex5.2: ex5.2.o $(BASE)
	$(CC) $(CFLAGS) -o ex5.2 ex5.2.o $(BASE)

ex5.3: ex5.3.o mystring.o
	$(CC) $(CFLAGS) -o ex5.3 ex5.3.o mystring.o

ex5.4: ex5.4.o mystring.o
	$(CC) $(CFLAGS) -o ex5.4 ex5.4.o mystring.o

ex5.5: ex5.5.o mystring.o
	$(CC) $(CFLAGS) -o ex5.5 ex5.5.o mystring.o

ex5.6: ex5.6.o mystring.o
	$(CC) $(CFLAGS) -o ex5.6 ex5.6.o mystring.o

ex5.7: ex5.7.o sort.o $(BASE) mystring.o
	$(CC) $(CFLAGS) -o ex5.7 ex5.7.o sort.o $(BASE) mystring.o

ex5.8: ex5.8.o $(BASE)
	$(CC) $(CFLAGS) -o ex5.8 ex5.8.o $(BASE)

ex5.9: ex5.9.o $(BASE)
	$(CC) $(CFLAGS) -o ex5.9 ex5.9.o $(BASE)

ex5.10: ex5.10.o $(BASE)
	$(CC) $(CFLAGS) -o ex5.10 ex5.10.o $(BASE)

ex5.11: ex5.11.o tab.o myctype.o
	$(CC) $(CFLAGS) -o ex5.11 ex5.11.o tab.o myctype.o

ex5.12: ex5.12.o tab.o
	$(CC) $(CFLAGS) -o ex5.12 ex5.12.o tab.o myctype.o

ex5.13: ex5.13.o
	$(CC) $(CFLAGS) -o ex5.13 ex5.13.o

ex5.14: ex5.14.o $(BASE) sort.o mystring.o
	$(CC) $(CFLAGS) -o ex5.14 ex5.14.o $(BASE) sort.o mystring.o

ex5.15: ex5.15.o $(BASE) sort.o mystring.o
	$(CC) $(CFLAGS) -o ex5.15 ex5.15.o $(BASE) sort.o mystring.o

ex5.16: ex5.16.o $(BASE) sort.o mystring.o
	$(CC) $(CFLAGS) -o ex5.16 ex5.16.o $(BASE) sort.o mystring.o

ex5.17: ex5.17.o $(BASE) sort.o mystring.o
	$(CC) $(CFLAGS) -o ex5.17 ex5.17.o $(BASE) sort.o mystring.o

ex5.18: ex5.18.o dcl.o
	$(CC) $(CFLAGS) -o ex5.18 ex5.18.o dcl.o

ex5.19: ex5.19.o dcl.o
	$(CC) $(CFLAGS) -o ex5.19 ex5.19.o dcl.o

sortlines: sortlines.o $(BASE) sort.o mystring.o
	$(CC) $(CFLAGS) -o sortlines sortlines.o $(BASE) sort.o mystring.o

clean:
	@echo "Cleaning up..."
	@$(RM)

