# This is a comment line
CC=g++
# CFLAGS will be the options passed to the compiler
CFLAGS=-c -Wall

all: lab13

lab13: lab13.o
	$(CC) lab13.o -o lab13

lab13.o: lab13.cpp
	$(CC) $(CFLAGS) lab13.cpp

clean:
	rm -rf *.o lab13
