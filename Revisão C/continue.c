#include <stdio.h>

int main(){

    int i;
    for(i=1; i<=10; i++){

        if(i == 5){ //ignora a impressão do 5.
            continue;
        }
    printf("%d", i);
    }
} 