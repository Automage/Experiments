/* Pranav Nair, heap.h
 * Created 16/4/19
 */

#ifndef BASICINTERPRETER_HEAP_H
#define BASICINTERPRETER_HEAP_H

#include "symbol.h"

#define HEAP_SIZE (100)

//Probably have to replace void* with specific types, overload for each
void heap_alloc(type_t, void*, char*);

#endif BASICINTERPRETER_HEAP_H
