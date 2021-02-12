#-*- MakeFile -*-

CC = gcc
CFLAGS = -Wall -g

all: ex6.1 ex6.2 ex6.3 ex6.4 ex6.5

ex6.1: ex6.1.o exercise_6.o
	$(CC) $(CFLAGS) ex6.1.o exercise_6.o -o ex6.1

ex6.1.o: ex6.1.c
	$(CC) $(CFLAGS) -c ex6.1.c

ex6.2: ex6.2.o exercise_6.o tree.o
	$(CC) $(CFLAGS) ex6.2.o exercise_6.o tree.o -o ex6.2

ex6.2.o: ex6.2.c
	$(CC) $(CFLAGS) -c ex6.2.c

ex6.3: ex6.3.o exercise_6.o
	$(CC) $(CFLAGS) ex6.3.o exercise_6.o -o ex6.3

ex6.3.o: ex6.3.c
	$(CC) $(CFLAGS) -c ex6.3.c

ex6.4: ex6.4.o exercise_6.o tree.o
	$(CC) $(CFLAGS) ex6.4.o exercise_6.o tree.o -o ex6.4

ex6.4.o: ex6.4.c
	$(CC) $(CFLAGS) -c ex6.4.c

ex6.5: ex6.5.o exercise_6.o
	$(CC) $(CFLAGS) ex6.5.o exercise_6.o -o ex6.5

ex6.5.o: ex6.5.c
	$(CC) $(CFLAGS) -c ex6.5.c

exercise_6.o: exercise_6.c exercise_6.h
	$(CC) $(CFLAGS) -c exercise_6.c

tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c tree.c
clean:
	@echo "Cleaning up..."
	rm -v ex6.1 ex6.2 ex6.3 ex6.4 ex6.5 *.o
