#include <stdio.h>

int main(){
    int A, B, soma, subtr, mult, divis;

    printf("Digite o primeiro valor:\n");
    scanf("%d", &A);
    printf("Digite o segundo valor:\n");
    scanf("%d", &B);

    soma = A + B;
    subtr = A - B;
    mult = A * B;
    divis = A / B;

    printf("Resultados:\n");
    printf("Soma: %d.\n", soma);
    printf("Subtração: %d.\n", subtr);
    printf("Multipli: %d.\n", mult);
    printf("Divisão: %d.\n", divis);
}