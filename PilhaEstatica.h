#ifndef PILHAESTATICA_H_INCLUDED
#define PILHAESTATICA_H_INCLUDED
#define MAX 100

typedef struct PilhaE{
    int v[MAX];
    int topo;
}PilhaE;

PilhaE* cria_pilha_pe();
void push_pe(PilhaE *p, int x);
int pop_pe(PilhaE *p);
int pilha_vazia_pe(PilhaE *p);

#endif // PILHAESTATICA_H_INCLUDED
