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

/*Aloca em um auxiliar e retorna o ponteiro da memoria alocada
  ATENCAO: Ponteiro deve ser liberado no main*/
char* pop_pilha(Pilha *p){
    if(p->topo >= 0){
        char* aux = malloc(MAX*sizeof(char));
        strcpy(aux, p->v[p->topo]);
        p->topo--;
        return aux;
    }
    return NULL;
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

//Pode ser usado no main para verificacao no terminal
void teste_pilha(){
    printf("--Usando pilha estatica--\n");
}

