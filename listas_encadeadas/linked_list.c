#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

    typedef struct Node {
        Element* element;
        struct Node* next;
    } Node;

    struct LinkedList{
        Node* head;
        int size;
    }

LinkedList* list_create(){
    LinkedList* list = malloc(sizeof(LinkedList));

    list->head = NULL; //VERIFICAR
    list->size = 0;  
}

void list_destroy(LinkedList* list){
    Node* cur = list->head;

    while(cur!= NULL){
        Node* trash = cur;

        cur = cur->next;
        free(trash);
    }
    free(list);
}

void list_insertFirst(LinkedList* list, Element element){
    Node* newNode = malloc(sizeof(Node));

    newNode->element = element;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void list_insertAfter(LinkedList* list, int pos, Element element){
    if(list->head == NULL || pos < 0){
        list_insertFirst(list, element);
    } else {

        Node* cur = list->head;
        int = 0;

        while(i < pos && cur->next != NULL){
            cur = cur->next;
            i++;
        }
        Node* newNode = malloc(sizeof(Node));

        newNode->element = element;
        newNode->next= cur->next;
        cur->next = newNode;
        list->size++;
        }
 }


bool list_removeFirst(LinkedList* list, list){
    if(list->head == NULL){
        return false;
    } 
    Node* trash = list->head;

    list->head = list->head->next;
    list->size--;

    return true;
}

bool list_removeAt(LinkedList* list, int pos){
    //posicao invalida

    if(pos < 0 || pos >=list->size){
        return false;
    }
    //lista vazia
    if(list == NULL){
        return false;
    }
    //remoção na cabeça
    if (pos == 0){
        return list_removeFirst(list);
    } else {//remover na cauda

    Node* prev = list->head;
    int = 0;

    while(i < pos - 1){
        prev = prev->next;
        i++;
    }
    
    Node* trash = prev->next;
    prev->next = prev->next->next;
    free(trash);
    list=>size--;
    }
}
void list_print(LinkedList* list){
    Node*cur = list->head;

    while(cur != NULL){
        element_print(element);
        cur = cur->next;

    } if(cur != NULL){
        printf("->");
    }
}