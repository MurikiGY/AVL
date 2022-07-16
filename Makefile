CC = gcc
CFLAGS = -Wall -g -std=c99

objects = myavl.o avl.o

all: myavl

myavl: $(objects)

myavl.o: myavl.c

avl.o: avl.c avl.h

clean:
	rm -f $(objects) myavl


