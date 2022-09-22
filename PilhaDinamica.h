#ifndef PILHAESTATICA_H_INCLUDED
#ifndef PILHADINAMICA_H_INCLUDED
#define PILHADINAMICA_H_INCLUDED

#define MAX 30
#define MAXN 50
#define MAXK 20

#include<string.h>

typedef struct Nodo{
    char info[MAX];
    struct Nodo* prox;
}Nodo;

typedef struct Pilha{
    Nodo* topo;
}Pilha;

Pilha* cria_pilha();
void push_pilha(Pilha *p, char* x);
void pop_pilha(Pilha *p, char* dest);
int tam_pilha(Pilha *p);
int pilha_vazia(Pilha *p);
void libera_pilha(Pilha *p);
void teste_pilha();


#endif // PILHADINAMICA_H_INCLUDED
#endif // PILHAESTATICA_H_INCLUDED
