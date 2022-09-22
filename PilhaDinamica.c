#include "PilhaDinamica.h"

Pilha* cria_pilha(){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}
void push_pilha(Pilha *p, char* x){
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(novo->info, x);
    novo->prox = p->topo;
    p->topo = novo;
}
void pop_pilha(Pilha *p, char* dest){
    Nodo* aux = p->topo;
    p->topo = p->topo->prox;
    strcpy(dest, aux->info);
    free(aux);
}
int tam_pilha(Pilha *p){
    int tam = 0;
    Nodo* aux = p->topo;
    for(tam = 0; aux != NULL; tam++) aux = aux->prox;
    return tam;
}
int pilha_vazia(Pilha *p){
    if(!tam_pilha(p)) return 1;
    return 0;
}
void libera_pilha(Pilha *p){
    while(p->topo != NULL){
        Nodo* aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
    }
    free(p);
}
