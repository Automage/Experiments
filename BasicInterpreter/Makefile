objects=core.o heap.o symbol.o

CLFAGS= -Wall -Werror -std=c99

pni: $(objects)
	gcc -o pni $(CFLAGS) $(objects)

core.o: core.h heap.h

heap.o: heap.h symbol.h

symbol.o: symbol.h
