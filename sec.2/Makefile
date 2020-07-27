# -*- MakeFile -*-

CC = gcc
CFLAGS = -Wall -g

main: main.o exercise_2.o
	$(CC) main.o exercise_2.o -o main

main.o: main.c
	$(CC) -c main.c

exercise_2.o: exercise_2.c exercise_2.h
	$(CC) -c exercise_2.c
clean:
	rm -f *.o
	rm -f main

