#include <stdio.h>

void multiplicacaoPorReferencia(int *p1, int *p2){
       *p1 = (*p1) * (*p2); 
}

int main(){
    int a = 10; 
    int b = 3;

    printf("Valor das variáveis: a = %d, b = %d\n", a, b);

    multiplicacaoPorReferencia(&a,&b);
    printf("Valor depois da função: a = %d, b = %d\n", a, b);
}