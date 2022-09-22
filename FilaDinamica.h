#ifndef FILADINAMICA_H_INCLUDED
#define FILADINAMICA_H_INCLUDED

#define MAX 100
#define MAXN 50
#define MAXK 20

#include<string.h>
#include "PilhaDinamica.h"
/**
typedef struct Nodo{
    char info[MAX];
    struct Nodo* prox;
}Nodo;
**/
typedef struct Fila{
    Nodo* inicio;
    Nodo* fim;
    int tam;
}Fila;

Fila* cria_fila();
void push_fila(Fila *f, char* x);
//char* pop_fila(Fila *f);
pop_fila(Fila *f, char* dest);
int tam_fila(Fila *f);
int fila_vazia(Fila *f);
void libera_fila(Fila *f);

#endif // FILADINAMICA_H_INCLUDED
