CC = gcc
CFLAGS = -Wall -g -std=c99

objects = myavl.o avl.o aux.o

all: myavl

myavl: $(objects)

myavl.o: myavl.c

avl.o: avl.c avl.h aux.o

aux.o: aux.c aux.h

clean:
	rm -f $(objects)
purge:	clean
	rm myavl
