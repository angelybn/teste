#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    Element element;
    struct Node* next;
};

struct LinkedList {
    Node* head;
    int size;
}

//primeira coisa que fzemos é criar a lista

LinkedList* list_create(){
    //alocar memória para a lista
    LinkedList* list = malloc(sizeof(LinkedList));

    list->head = NULL; //quando eu aponto pra nulo, obrigo ele a ser o 1° nó da lista
    list->size = 0;

    return list;
}

void list_destroy(LinkedList* list){
    Node* cur = list->head;

    while (cur != NULL){
        Node* trash = cur;

        cur = cur->next;
        free(trash);
    }
    free(list);
}

void list_insertFirst(LinkedList* list, Element element){
    //aloco memória para meu novo nó
    Node* newNode = malloc(sizeof(Node));

    newNode->element = element;
    newNode->next = list->head;
    list->head = newNode; // imagina o desenho de um ciclo/circulo
    list->size++;
}

void list_insertAfter(LinkedList* list, int pos, Element element){
    if(list->head == NULL || pos < 0){
        list_insertFirst(list, element);
    } else {
        Node* cur = list->head; //faço um ponteiro para percorrer todos os nós do meu array
        int i = 0;
    //laço para percorrer o array
    while(i < pos && cur->next != NULL) {
        cur = cur->next;
        i++;
    }
        Node* newNode = malloc(sizeof(Node));

        newNode->element = element; //atribuo o valor digitado pelo usuário no meu elemento da lista
        newNode->next = cur->next; //meu newNode precisa apontar para onde anteriormente o cur->next apontava
        cur->next = newNode; //current->next passa agora a apontar para o NewNode que acabou de entrar na minha lista
        list->size++;
    }

}