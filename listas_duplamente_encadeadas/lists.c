#include "lists.h"

#include <stdlib.h>
#include <stdio.h>


typedef struct Node {
    Element element;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct DLinkedList {
    Node* first;
    Node* last;
    int size;
} DLinkedList;


DLinkedList *dlist_create() {
    DLinkedList *list = malloc(sizeof(DLinkedList));

    list->first = NULL;
    list->last = NULL;
    list->size = 0;

    return list;
}

void dlist_destroy(DLinkedList *list) {
    Node* cur = list->first;

    while (cur != NULL) {
        Node* trash = cur;
        cur = cur->next;
        free(trash);
    }
    free(list);
}

Node* create_node(Element element) {
    Node* newNode = malloc(sizeof(Node));

    newNode->element = element;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}
void dlist_printForward(DLinkedList *list) {
    Node* cur = list->first;

    while (cur != NULL) {
        element_print(cur->element);
        cur = cur->next;
        if (cur != NULL) {
            printf(" -> ");
        }
    }
    printf("\n");
}

void dlist_printReverse(DLinkedList *list) {
    Node* cur = list->last;

    while (cur != NULL) {
        element_print(cur->element);
        cur = cur->prev;
        if (cur != NULL) {
            printf(" -> ");
        }
    }
    printf("\n");
}

void dlist_insertFirst(DLinkedList *list, Element element) {
    Node* newNode = create_node(element);

    if (list->first != NULL) { // caso: lista não vazia
        newNode->next = list->first;
        list->first->prev = newNode;
        list->first = newNode;
    } else { // caso: lista vazia
        list->first = newNode;
        list->last = newNode;
    }
list->size++;
}

void dlist_insertLast(DLinkedList *list, Element element) {
    Node* newNode = create_node(element); // Cria um novo nó com o elemento fornecido.

    if (list->last != NULL) { // Verifica se a lista não está vazia.
        list->last->next = newNode; // O último nó atual aponta para o novo nó.
        newNode->prev = list->last; // O novo nó aponta para o último nó atual.
        list->last = newNode; // O novo nó é agora o último nó da lista.
    } else { // Caso a lista esteja vazia.
        list->first = newNode; // O novo nó é o primeiro e o último nó da lista.
        list->last = newNode;
    }

    list->size++; // Incrementa o tamanho da lista.
}

void dlist_insertAt(DLinkedList *list, int index, Element element) {
    if (index <= 0) {
        dlist_insertFirst(list, element); // Insere o elemento no início da lista.
    } else if (index >= list->size) {
        dlist_insertLast(list, element); // Insere o elemento no final da lista.
    } else {
        Node* cur = list->first;

        for (int i = 0; i < index; i++) {
            cur = cur->next; // Percorre a lista até a posição desejada.
        }

        Node* newNode = create_node(element); // Cria um novo nó com o elemento fornecido.

        newNode->next = cur; // O próximo ponteiro do novo nó aponta para o nó atual.
        newNode->prev = cur->prev; // O ponteiro anterior do novo nó aponta para o nó anterior ao nó atual.
        cur->prev->next = newNode; // O próximo ponteiro do nó anterior ao nó atual aponta para o novo nó.
        cur->prev = newNode; // O ponteiro anterior do nó atual aponta para o novo nó.

        list->size++; // Incrementa o tamanho da lista.
    }
}
void dlist_removeFirst(DLinkedList *list) {
    if (list->first == NULL) {
        return;
    }

    Node *trash = list->first;
    list->first = list->first->next;

    if (list->first != NULL) {
        list->first->prev = NULL;
    } else {
        list->last = NULL;
    }

    free(trash);
    list->size--;
}

void dlist_removeLast(DLinkedList *list) {
    if (list->last == NULL) {
        return; // Retorna se a lista estiver vazia.
    }

    Node* trash = list->last; // Armazena uma referência ao último nó da lista.

    list->last = list->last->prev; // Atualiza o ponteiro last para apontar para o nó anterior ao último.

    if (list->last != NULL) {
        list->last->next = NULL; // Se o novo último nó não for nulo, seu ponteiro next deve ser nulo.
    } else {
        list->first = NULL; // Se não houver mais nós na lista, tanto o primeiro quanto o último são nulos.
    }

    free(trash); // Libera a memória do nó anteriormente no final da lista.
    list->size--; // Decrementa o tamanho da lista.
}

void dlist_removeAt(DLinkedList *list, int index) {
    if (index <= 0) {
        dlist_removeFirst(list); // Remove o primeiro nó da lista.
    } else if (index >= list->size - 1) {
        dlist_removeLast(list); // Remove o último nó da lista.
    } else {
        Node* cur = list->first;

        for (int i = 0; i < index; i++) {
            cur = cur->next; // Percorre a lista até o nó na posição index.
        }

        // Remove o nó atual, conectando o nó anterior ao próximo nó.
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;

        // Libera a memória alocada para o nó removido.
        free(cur);

        // Decrementa o tamanho da lista.
        list->size--;
    }
}


DLinkedList* reverse(DLinkedList* l) {
    DLinkedList* reversedList = dlist_create(); // Cria uma nova lista para armazenar os elementos invertidos.

    Node* current = l->last; // Começa a percorrer a lista a partir do último nó.

    // Percorre a lista original do final para o início e insere os elementos invertidos na nova lista.
    while (current != NULL) {
        dlist_insertLast(reversedList, current->element);
        current = current->prev;
    }

    return reversedList;
}