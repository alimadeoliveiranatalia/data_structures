#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct No
{
    int info;
    struct No* proximo;
};

struct Lista
{
    int info;
    struct Lista* prox;
}


void imprimir(Lista* i){
    Lista* p;
    printf("Elementos: \n"); 
}