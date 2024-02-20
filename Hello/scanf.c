#include <stdio.h>

int main(){
    int idade = 0;
    int ano= 1950;

    printf("Valor inicial da idade: %d.\n", idade);

    printf("Digite uma idade e o ano: \n");
    scanf("%d %d", &idade, &ano);

    printf("Idade informada> %d.\n", idade);
    printf("Ano informado> %d.\n", ano);
}