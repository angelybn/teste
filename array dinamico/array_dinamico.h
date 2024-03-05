#ifndef ARRAY_DINAMICO
#define ARRAY_DINAMICO

#include "element.h"

typedef struct ArrayDinamico ArrayDinamico;

ArrayDinamico* array_create();
void array_dinamico_destroy(ArrayDinamico* array);
void array_dinamico_print(ArrayDinamico* array);
void array_dinamico_set(ArrayDinamico* array, int index, Element value);
void array_dinamico_add(ArrayDinamico* array, Element value);
int array_dinamico_get(ArrayDinamico* array, int index);
int array_dinamcio_size(ArrayDinamico* array);
int array_dinamico_capacity(ArrayDinamico* array);

#endif