#include "PilhaEstatica.h"

PilhaE* cria_pilha_pe(){
    PilhaE* p = (PilhaE*)malloc(sizeof(PilhaE));
    p->topo = -1;
    return p;
}

void push_pe(PilhaE *p, int x){
    if(p->topo < (MAX-2)){
        p->topo++;
        p->v[p->topo] = x;
    }
}

int pop_pe(PilhaE *p){
    if(p->topo >= 0){
        p->topo--;
        return p->v[p->topo + 1];
    }
    return 0;
}

int pilha_vazia_pe(PilhaE *p){
    if(p->topo == -1) return 1;
    return 0;
}

