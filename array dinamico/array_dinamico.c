#include <stdio.h>
#include <stdlib.h>

#include "array_dinamico.h"

#define INITIAL_CAPACITY 10

typedef struct ArrayDinamico{
    Element* array;
    int size;
    int capacity;
};

void array_dinamico_resize(ArrayDinamico* array, int new_capacity);

ArrayDinamico* array_dinamico_create(){
    ArrayDinamico* array = malloc(sizeof(ArrayDinamico));
    array->array = malloc(sizeof(Element)*new_capacity);

    array->size = 0;
    array->capacity = INITIAL_CAPACITY;

    return array;
}

void array_dinamico_resize(ArrayDinamico* array, int new_capacity){
    Element *new_array = realloc(array->array, sizeof(Element) * new_capacity);

    if(new_array != NULL){
        array->array = new_array;
        array->capacity = new_capacity;
    }
}

void array_dinamico_add(ArrayDinamico* array, Element value){
    if(array->size == array->capacity){
        array_dinamico_resize(array, array->capacity * 2);
    }
    array->array[array->size] = value;
    array->size++;
}
