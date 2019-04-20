/* Pranav Nair, symbol.c
 * Created: 20/4/19
 *
 * Module that handles symbol table functionality
 */

#include "symbol.h"

#include <assert.h>
#include <string.h>
#include <stdlib.h> //change with malloc.h

/*
 * Allocate memory for new symbol_element struct, and return pointer to it.
 */

symbol_t *create_symbol(char *symbol, type_t var_type, void **memory) {

  assert(symbol);
  assert(memory);
  assert(*memory);

  symbol_t *new = malloc(sizeof(symbol_t));
  assert(new);

  new->type = var_type;
  new->memory = memory;

  new->symbol = malloc(strlen(symbol) + 1);
  strncpy(new->symbol, symbol, strlen(symbol) + 1);

  return new;

}
