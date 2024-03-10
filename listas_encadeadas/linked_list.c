#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    Element element;
    struct Node* next;
} Node;

struct LinkedList {
    Node* head;
    int size;
};

LinkedList* list_create() {
    LinkedList* list = malloc(sizeof(LinkedList));

    list->head = NULL;
    list->size = 0;

    return list;
}

void list_destroy(LinkedList* list) {
    Node* cur = list->head;

    while (cur != NULL) {
        Node* trash = cur;

        cur = cur->next;
        free(trash);
    }
    free(list);
}

void list_insertFirst(LinkedList* list, Element element) {
    Node* newNode = malloc(sizeof(Node));

    newNode->element = element;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void list_insertAfter(LinkedList* list, int pos, Element element) {
    if (list->head == NULL || pos < 0) {
        list_insertFirst(list, element);
    } else {
        Node* cur = list->head;
        int i = 0;

        while (i < pos && cur->next != NULL) {
            cur = cur->next;
            i++;
        }

        Node* newNode = malloc(sizeof(Node));

        newNode->element = element;
        newNode->next = cur->next;
        cur->next = newNode;
        list->size++;
    }    
}

void list_print(LinkedList* list) {
    Node* cur = list->head;

    while (cur != NULL) {
        element_print(cur->element);
        cur = cur->next;
        if (cur != NULL) {
            printf(" -> ");
        }        
    }
    printf("\n");
}

bool list_removeFirst(LinkedList* list) {
    if (list->head == NULL) {
        return false;
    }

    Node* trash = list->head;

    list->head = list->head->next;
    free(trash);
    list->size--;

    return true;
}

bool list_removeAt(LinkedList* list, int pos) {
    // caso 0: posicao invalida
    if (pos < 0 || pos >= list->size) {
        return false;
    }

    // caso 1: lista vazia
    if (list == NULL) {
        return false;
    }

    // caso 2: remocao na cabeca
    if (pos == 0) {
        return list_removeFirst(list);
    } else { // caso 3: remocao na cauda
        Node* prev = list->head;
        int i = 0;

        while (i < pos - 1) {
            prev = prev->next;
            i++;
        }

        Node* trash = prev->next;

        prev->next = prev->next->next;
        free(trash);  
        list->size--;

    }

    return true;    
}

//*****************************************************************

int list_get(LinkedList* list, int position) {
    if (list == NULL || position < 0 || position >= list->size) {
        // Lista vazia ou posição inválida, retorne um valor adequado (por exemplo, -1)
        return -1;
    }

    Node* cur = list->head;
    int i = 0;

    while (i < position) {
        cur = cur->next;
        i++;
    }

    return cur->element;
}
////1
void list_printElements(LinkedList* l1, LinkedList* l2) {
    if (l1 == NULL || l2 == NULL) {
        printf("Invalid input lists.\n");
        return;
    }

    Node* cur2 = l2->head;

    while (cur2 != NULL) {
        int pos = cur2->element;

        // Verifica se a posição é válida na primeira lista
        if (pos >= 0 && pos < list_size(l1)) {
            Element element = list_get(l1, pos);
            element_print(element); 
        } else {
            printf("Invalid position: %d\n", pos);
        }
        cur2 = cur2->next;
    }

    printf("\n");
}
///////2
bool list_equals(LinkedList* l1, LinkedList* l2) {
    if (l1->size != l2->size) {
        return false; // Se os tamanhos das listas forem diferentes, elas não são iguais
    } else {
        Node* cur1 = l1->head;
        Node* cur2 = l2->head;

        // Percorre ambas as listas enquanto compara os elementos
        while (cur1 != NULL && cur2 != NULL) {
            // Verifica se os elementos atuais são iguais
            if (cur1->element != cur2->element) {
                return false; // Se um par de elementos não for igual, as listas não são iguais.
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        // Se ambos os ponteiros chegarem ao final sem problemas, as listas são iguais.
        return true;
    }
}
/////3
int list_isSorted(LinkedList* list) {

    Node* cur = list->head;

    int isIncreasing = 1; // Assume que a lista está em ordem crescente
    int isDecreasing = 1; // Assume que a lista está em ordem decrescente

    while (cur->next != NULL) {
        int current = cur->element;
        int next = cur->next->element;

        if (current > next) {
            isIncreasing = 0; // Lista não está em ordem crescente
        } else if (current < next) {
            isDecreasing = 0; // Lista não está em ordem decrescente
        }

        cur = cur->next;
    }

    if (isIncreasing)
        return 1; // A lista está em ordem crescente
    else if (isDecreasing)
        return 2; // A lista está em ordem decrescente
    else
        return 0; // A lista não está ordenada
}

/////4
void list_removeDuplicates(LinkedList* list) {

    Node* cur1 = list->head;

    while (cur1 != NULL) {
        Node* cur2 = cur1;

        while (cur2->next != NULL) {
            if (cur1->element == cur2->next->element) {
                // Duplicata encontrada, removemos o nó duplicado
                Node* duplicate = cur2->next;
                cur2->next = cur2->next->next;
                free(duplicate);
                list->size--;
            } else {
                cur2 = cur2->next;
            }
        }

        cur1 = cur1->next;
    }
}
/////5
int list_search(LinkedList *list, Element value){
    Node* cur = list->head;
    int pos = 0;

    while(cur != NULL){
        if (cur->element == value) {
            return pos;
        }
        cur = cur->next;
        pos++;
    }
    return -1;
}

