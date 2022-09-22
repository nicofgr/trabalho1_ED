#include "PilhaEstatica.h"

PilhaE* cria_pilha_pe(){
    PilhaE* p = (PilhaE*)malloc(sizeof(PilhaE));
    p->topo = -1;
    return p;
}

void push_pe(PilhaE *p, char* x){
    if(p->topo < (MAXN-2)){
        p->topo++;
        strcpy(p->v[p->topo], x);
    }
}

char* pop_pe(PilhaE* p){
    if(p->topo >= 0){
        p->topo--;
        return (p->v[p->topo + 1]);
    }
    return "n/a";
}

int pilha_vazia_pe(PilhaE *p){
    if(p->topo == -1) return 1;
    return 0;
}

void libera_pilha(PilhaE *p){
    free(p);
}

