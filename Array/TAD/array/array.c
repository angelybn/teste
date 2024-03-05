#include <stdlib.h>
#include <stdio.h>
#include "array.h"


struct Array {
    Element* array;
    int size;
};

Array* array_create(int size) {
    Array* array = malloc(sizeof(Array));

    array->array = malloc(sizeof(Element)*size);
    array->size = size;

    return array;
}

void array_destroy(Array* array){
    free(array->array);
    free(array);
}

void array_print(Array* array){
    for(i = 0; i < array->size; i++){
        element_print(array->array[i]);
    }
}

void array_set(Array* array, int index, Element value){
    if(index < 0 || index >= array->) {
        return;
    }
    array->array[index] = value;
}

int array_get(Array* array, int index){
      if(index < 0 || index >= array->) {
        return ERROR_CODE;
    }
    return array->array[index];
}

int array_size(Array* array){
    return array->size;
}