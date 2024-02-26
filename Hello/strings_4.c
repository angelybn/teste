#include <stdio.h>
#include <string.h>
#include <locale.h>

#define N 50

int main(){
    setlocale(LC_ALL, "Portuguese");

    char s1[N] = {"Logica de "};
    char s2[N] = {"Programação"};

    strcat(s1,s2);

    printf("Depois do strcat:\n");
    puts(s1);
    puts(s2);
}