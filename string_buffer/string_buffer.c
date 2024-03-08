#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string_buffer.h"

#include "inc/array_dinamico.h"

struct StringBuffer {
    ArrayDinamico* data;
};


StringBuffer* string_buffer_create(){
    StringBuffer* sb = malloc(sizeof(StringBuffer));

    sb->data = array_dinamico_create();

    return sb;
}

void string_buffer_destroy(StringBuffer* string_buffer) {
    array_dinamico_destroy(string_buffer->data);
    free(string_buffer);
}


void string_buffer_append(StringBuffer* string_buffer, char* string){
    for(int i = 0; i < strlen(string); i++) {
        array_dinamico_add(string_buffer->data, string[i]);
    }
}

char* string_buffer_to_string(StringBuffer* string_buffer){
    //calcula o tamanho da string, incluindo o caractere nulo
    int size = array_dinamico_size(string_buffer->data)+1;

    //aloca dinamicamente memória para a string
    char* string = malloc(sizeof(char) * size);

    //copia os caracteres do buffer para a string
    for(int i = 0; i < size - 1; i++){
        string[i] = array_dinamico_get(string_buffer->data, i);
    }

    //adiciona o caractere nulo ao final da string
    string[size - 1] = '\0';

    // retorna o ponteiro para a string criada
    return string;
}