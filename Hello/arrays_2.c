#include <stdio.h>

int main(){

    int v[5];
    int i;

    for(i=0;i<5;i++){
        printf("Insira um dado:\n");
        scanf("%d", &v[i]); // deixa o usuario inserir 5 numeros
    }

    printf("Dados inseridos:\n");
    for(i=0;i<5;i++){
        printf("%d", v[i]);
    }

}