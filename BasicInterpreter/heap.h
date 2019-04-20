/* Pranav Nair, memory.h
 * Created 16/4/19
 */

#define HEAP_SIZE (100)

/*
 * All possible types a variable can be stored as.
 */

typedef enum type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    LONG
} type;

void allocMem(type, void*, char*);

