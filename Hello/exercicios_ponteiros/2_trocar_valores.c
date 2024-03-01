#include <stdio.h>

void incrementoPorReferencia(int *pointer){
    int controle = *pointer;
    *pointer = controle + 1;
}

int main(){
    int a = 10;

    printf("Valor original: a = %d\n", a);

incrementoPorReferencia(&a);
    printf("Valor modificado: a = %d\n", a);
 
return 0;
}