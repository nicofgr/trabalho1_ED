#include "PilhaEstatica.h"

PilhaE** cria_pilha_pe(int K){
    int i = 0;
    PilhaE** pilhas = (PilhaE**)malloc(K*sizeof(PilhaE*));
    for(i = 0; i < K; i++){
        pilhas[i] = (PilhaE*)malloc(sizeof(PilhaE));
        pilhas[i]->topo = -1;
    }
    return pilhas;
}

void push_pe(PilhaE *p, char* x){
    if(p->topo < (MAX-2)){
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

