#ifndef PILHAESTATICA_H_INCLUDED
#define PILHAESTATICA_H_INCLUDED

#define MAX 30
#define MAXN 50
#define MAXK 20

#include<string.h>

typedef struct Pilha{
    char v[MAXN][MAX];
    int topo;
}Pilha;

Pilha* cria_pilha();
void push_pilha(Pilha *p, char* x);
void pop_pilha(Pilha *p, char* dest);
int tam_pilha(Pilha *p);
int pilha_vazia(Pilha *p);
void libera_pilha(Pilha *p);
void teste_pilha();


#endif // PILHAESTATICA_H_INCLUDED
