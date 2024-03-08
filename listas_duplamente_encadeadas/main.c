#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include "element.h"

int main() {
    // Criação e inicialização da lista
    DLinkedList* list = dlist_create();

    // Inserção de elementos na lista
    dlist_insertLast(list, 1);
    dlist_insertLast(list, 2);
    dlist_insertLast(list, 3);
    dlist_insertLast(list, 4);
    dlist_insertLast(list, 5);

    // Impressão da lista original
    printf("Lista original: ");
    dlist_printForward(list);

    // Inverter a lista
     DLinkedList* list_reverse = reverse(list);

    // Impressão da lista invertida
    printf("Lista invertida: ");
    dlist_printForward(list_reverse);

    return 0;
}