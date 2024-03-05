#include <stdio.h>
#include "array.h"

int main() {

// 1) criar e destruiu um array;

    Array* array = array_create(5);
    array_destroy(array);

//2 Preencher e imprimir um array:
    Array* array = array_create(3);
    array_set(array, 0, 10);
    array_set(array, 1, 20);
    array_set(array, 2, 30);
    array_print(array);

//3 Acesso a elementos do array:
    Array* array = array_create(4);
    array_set(array, 0, 10);
    array_set(array, 1, 20);
    array_set(array, 2, 30);
    array_set(array, 3, 40);

    int value = array_get(array, 3);

}