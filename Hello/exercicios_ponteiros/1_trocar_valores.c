#include <stdio.h>

void trocarValores(int *ptrA, int *ptrB) { 
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
}

int main() {
    int a = 5, b = 10;

    printf("Valor original: a = %d, b = %d\n", a, b);

    // Chamando a função para trocar os valores
    trocarValores(&a, &b);

    printf("Valor modificado: a = %d, b = %d\n", a, b);

    return 0;
}