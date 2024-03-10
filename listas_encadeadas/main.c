#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main() {
    // Criando e inicializando a lista
    LinkedList* my_list = list_create();
    
    // Inserindo alguns elementos na lista
    list_insertFirst(my_list, 10);
    list_insertFirst(my_list, 20);
    list_insertFirst(my_list, 30);
    list_insertFirst(my_list, 40);

    // Chame a função list_search para encontrar um elemento na lista
    int index = list_search(my_list, 20);
    if (index != -1) {
        printf("Element 20 found at index: %d\n", index);
    } else {
        printf("Element 20 not found in the list\n");
    }

    // Destrua a lista após o uso para evitar vazamentos de memória
    list_destroy(my_list);

    return 0;
}

