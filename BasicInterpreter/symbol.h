/* Pranav Nair, symbol.h
 * Created: 20/4/19
 */

#ifndef BASICINTERPRETER_SYMBOL_H
#define BASICINTERPRETER_SYMBOL_H

/*
 * All possible types a variable can be stored as.
 */

typedef enum type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    LONG
} type_t;

/*
 * Symbol table element
 */

typedef struct symbol{
    char *symbol;
    type_t type;
    void **memory;
} symbol_t;

/*
 * Symbol table functions
 */

symbol_t *create_symbol(char *, type_t, void **);

#endif //BASICINTERPRETER_SYMBOL_H
