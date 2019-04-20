objects = core.o heap.o

CLFAGS = -Wall -Werror -std=c99

pni: core.o
	gcc -o pni $(CFLAGS) $(objects)

core.o: core.h heap.h

heap.o: heap.h
