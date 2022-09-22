#ifndef FILAESTATICA_H_INCLUDED
#ifndef FILADINAMICA_H_INCLUDED
#define FILADINAMICA_H_INCLUDED

#define MAX 30
#define MAXN 50
#define MAXK 20

#include<string.h>

#ifndef PILHADINAMICA_H_INCLUDED
typedef struct Nodo{
    char info[MAX];
    struct Nodo* prox;
}Nodo;
#endif

typedef struct Fila{
    Nodo* inicio;
    Nodo* fim;
    int tam;
}Fila;

Fila* cria_fila();
void push_fila(Fila *f, char* x);
pop_fila(Fila *f, char* dest);
int tam_fila(Fila *f);
int fila_vazia(Fila *f);
void libera_fila(Fila *f);
void teste_fila();

#endif // FILADINAMICA_H_INCLUDED
#endif // FILAESTATICA_H_INCLUDED

