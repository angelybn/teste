#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main() {
    // Criar e inicializar duas listas
    LinkedList* list1 = list_create();


    // Inserir alguns elementos nas duas listas
    list_insertFirst(list1, 100);
    list_insertFirst(list1, 90);
    list_insertFirst(list1, 80);
    list_insertFirst(list1, 70);
    list_insertFirst(list1, 60);
     list_print(list1);
     printf("\n");
    reverse(list1);
    list_print(list1);

    // Liberar memória alocada
    list_destroy(list1);
   

    return 0;
}

