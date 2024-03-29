#include "stack.h"
#include "element.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    Element element;
    struct Node* next;
} Node;

struct Stack {
    Node* top;
    int size;
};

Stack* stack_create() {
    Stack* stack = malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;

    return stack;
}

void stack_destroy(Stack* stack) {
    Node* cur = stack->top;

    while(cur != NULL){
        Node* trash = cur;
        cur = cur->next;
        free(trash);
    }
    free(stack);
}

bool stack_push(Stack* stack, Element element){
    Node* newNode = malloc(sizeof(Node));

    newNode->element = element;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;

    return true;
}

Element stack_pop(Stack* stack){
    if(stack_isEmpty(stack)){
        return ELEMENT_NULL;
    }

    Node* trash = stack->top;
    Element value = trash->element;

    stack->top = trash->next;
    free(trash);
    stack->size--;

    return value;
}

Element stack_peek(Stack* stack) {
    if(stack_isEmpty(stack)) {
        return ELEMENT_NULL;
    }
    return stack->top->element;
}
bool stack_isEmpty(Stack* stack) {
    return stack->top == NULL;
}

bool stack_is_full(Stack* stack){
    return false;
}

int stack_size(Stack* stack){
    return stack->size;
}

void stack_print(Stack* stack){
    Node* cur = stack->top;

    while(cur != NULL){
        element_print(cur->element);
        printf(" ");
        cur = cur->next;
    }
    printf("\n");
}

