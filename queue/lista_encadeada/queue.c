#include "queue.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    Element element;
    struct Node* next;
} Node;

struct Queue {
    Node* front;
    Node* back;
    int size;
};

Queue* queue_create() {
    Queue* queue = malloc(sizeof(Queue));

    queue->front = NULL;
    queue->back = NULL;
    queue->size = 0;

    return queue;
}

void queue_destroy(Queue* queue) {
    while (!queue_isEmpty(queue)) {
        queue_dequeue(queue);
    }
    free(queue);
}

void queue_enqueue(Queue* queue, Element element) {
    Node* newNode = malloc(sizeof(Node));

    newNode->element = element;
    newNode->next = NULL;
    if (queue->front == NULL) { // empty queue
        queue->front = newNode;
        queue->back = newNode;
    } else { // non-empty queue
        queue->back->next = newNode;
        queue->back = newNode;
    }
    queue->size++;
}

Element queue_dequeue(Queue* queue) {
    if (queue_isEmpty(queue)) {
        return ELEMENT_NULL;
    }

    Element res = queue->front->element;
    Node* trash = queue->front;

    queue->front = queue->front->next;
    free(trash);
    queue->size--;

    return res;
}

Element queue_front(Queue* queue) {
    if (queue_isEmpty(queue)) {
        return ELEMENT_NULL;
    }

    return queue->front->element;
}

Element queue_back(Queue* queue) {
    if (queue_isEmpty(queue)) {
        return ELEMENT_NULL;
    }

    return queue->back->element;
}

int queue_size(Queue* queue) {
    return queue->size;
}

bool queue_isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void queue_print(Queue* queue) {
    Node* cur = queue->front;

    while (cur != NULL) {
        element_print(cur->element);
        printf(" ");
        cur = cur->next;
    }
    printf("\n");
}

bool equals(Queue* q1, Queue* q2){
     // Verifica se as filas têm o mesmo tamanho
    if (queue_size(q1) != queue_size(q2)) {
        return false;
    }

    Node* cur1 = q1->front;
    Node* cur2 = q2->front;

    // Percorre ambas as filas simultaneamente e compara os elementos
    while (cur1 != NULL && cur2 != NULL) {
        // Se os elementos forem diferentes, as filas não são iguais
        if (cur1->element != cur2->element) {
            return false;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }

    // Verifica se ambos os ponteiros chegaram ao final da fila
    // Se apenas um dos ponteiros chegou ao final, as filas não são iguais
    if (cur1 != NULL || cur2 != NULL) {
        return false;
    }

    // Se chegamos aqui, os elementos das filas foram iguais em todas as posições
    return true;
}