#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define TAM 3

struct tipo_pessoa {
    int idade;
    float peso;
    char nome[50];
};

typedef struct tipo_pessoa tipo_pessoa;

int main() {
    setlocale(LC_ALL, "Portuguese");

    tipo_pessoa lista[TAM];
    int i;

    for (i = 0; i < TAM; i++) {
        printf("Insira os dados (%d):\n", i + 1);
        printf("Nome: ");
        scanf("%49[^\n]%*c", lista[i].nome);
        fflush(stdin);

        printf("Idade: ");
        scanf("%d", &lista[i].idade);
        fflush(stdin);

        printf("Peso: ");
        scanf("%f", &lista[i].peso);
        fflush(stdin);
    }

    printf("Seus dados:\n");
    for (i = 0; i < TAM; i++) {
        printf("---------Pessoa %d--------\n", i + 1);
        printf("\nNome: %s\n", lista[i].nome);
        printf("\nIdade: %d\n", lista[i].idade);
        printf("\nPeso: %.2f\n", lista[i].peso);
    }
    printf("-----------------------------\n");

    return 0;
}
