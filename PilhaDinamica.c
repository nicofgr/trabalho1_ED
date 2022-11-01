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

/*Salva a string em um auxiliar dinamico e retorna o endereco*/
char* pop_pilha(Pilha *p){
    Nodo* aux = p->topo;
    char* temp = malloc(MAX*sizeof(char));
    p->topo = p->topo->prox;
    strcpy(temp, aux->info);
    free(aux);
    return temp;
}

/*Conta os nodos ate o nulo*/
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
/*Libera cada nodo alocado*/
void libera_pilha(Pilha *p){
    while(p->topo != NULL){
        Nodo* aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
    }
    free(p);
}
/*Funcao para testes pode ser habilitado no main*/
void teste_pilha(){
    printf("+++Usando pilha dinamica+++\n");
}

