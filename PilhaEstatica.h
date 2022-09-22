#ifndef PILHAESTATICA_H_INCLUDED
#define PILHAESTATICA_H_INCLUDED
#define MAX 100
#define MAXN 50
#define MAXK 20

#include<string.h>

typedef struct PilhaE{
    char v[MAXN][MAX];
    int topo;
}PilhaE;

//PilhaE** cria_pilha_pe(int K);
PilhaE* cria_pilha_pe();
void push_pe(PilhaE *p, char* x);
char* pop_pe(PilhaE *p);
int pilha_vazia_pe(PilhaE *p);
void libera_pilha(PilhaE *p);

#endif // PILHAESTATICA_H_INCLUDED
