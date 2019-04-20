/* Pranav Nair, core.c
 * Created: 20/4/19
 */

#include "heap.h"

/*
 * Holds pointers to memory locations containing values.
 */
void *variable_heap[HEAP_SIZE];

/*
 * Keeps track of the index of the first unoccupied element in the variable
 * heap.
 */
int current_location = 0;

/*
 * Allocates memory for a given type, value, and symbol on the variable heap.
 * Adds symbol to the symbol table and appends pointer to the heap.
 */
void allocMem(type var_type, void* value_ptr, char* symbol) {
  //Placeholder
  return;
}
