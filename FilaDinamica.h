#ifndef FILADINAMICA_H_INCLUDED
#define FILADINAMICA_H_INCLUDED

#define MAX 30
#define MAXN 50
#define MAXK 20

#include<string.h>

typedef struct NodoFila{
    char info[2][MAX];
    struct NodoFila* prox;
}NodoFila;

typedef struct Fila{
    NodoFila* inicio;
    NodoFila* fim;
    int tam;
}Fila;

Fila* cria_fila();
void push_fila(Fila* f, char* cptdr1, char* cptdr2);
void pop_fila(Fila* f, char* dest1, char* dest2);
int tam_fila(Fila *f);
int fila_vazia(Fila *f);
void libera_fila(Fila *f);
void teste_fila();

#endif // FILADINAMICA_H_INCLUDED

