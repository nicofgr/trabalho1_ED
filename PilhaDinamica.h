#ifndef PILHADINAMICA_H_INCLUDED
#define PILHADINAMICA_H_INCLUDED

#define MAX 31
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
char* pop_pilha(Pilha *p);
int tam_pilha(Pilha *p);
int pilha_vazia(Pilha *p);
void libera_pilha(Pilha *p);
void teste_pilha();

#endif // PILHADINAMICA_H_INCLUDED
