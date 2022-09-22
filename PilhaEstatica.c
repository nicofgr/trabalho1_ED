#include "PilhaEstatica.h"

Pilha* cria_pilha(){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}

void push_pilha(Pilha *p, char* x){
    if(p->topo < (MAXN-2)){
        p->topo++;
        strcpy(p->v[p->topo], x);
    }
}
void pop_pilha(Pilha *p, char* dest){
    if(p->topo >= 0){
        strcpy(dest, p->v[p->topo]);
        p->topo--;
        return;
    }
    return;
}
int pilha_vazia(Pilha *p){
    if(p->topo == -1) return 1;
    return 0;
}

void libera_pilha(Pilha *p){
    free(p);
}

int tam_pilha(Pilha *p){
    return p->topo;
}

