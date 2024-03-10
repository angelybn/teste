#include <stdio.h>
#include "stack_array.h"

int main() {
    // Criando uma pilha original
    Stack *original_stack = stack_create(5);

    // Inserindo elementos na pilha original
    stack_push(original_stack, 10);
    stack_push(original_stack, 20);
    stack_push(original_stack, 30);
    stack_push(original_stack, 40);
    stack_push(original_stack, 50);

    // Imprimindo a pilha original
    printf("Original Stack: ");
    stack_print(original_stack);

    // Copiando a pilha original para uma nova pilha
    Stack* copied_stack = copy(original_stack);

    // Imprimindo a pilha copiada
    printf("Copied Stack: ");
    stack_print(copied_stack);

    // Liberando a memória alocada para as pilhas
    stack_destroy(original_stack);
    stack_destroy(copied_stack);

    return 0;
}