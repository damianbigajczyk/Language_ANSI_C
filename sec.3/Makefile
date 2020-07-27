# -*- MakeFile -*-

CC = gcc
CFLAGS = -WALL -g

main: main.o exercise_3.o
	$(CC) main.o exercise_3.o -o main

main.o: main.c
	$(CC) -c main.c

exercise_3.o: exercise_3.c exercise_3.h
	$(CC) -c exercise_3.c

clean:
	rm -v *.o
	rm -v main

