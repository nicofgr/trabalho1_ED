#include "FuncoesAuxiliares.h"


void desenha_pe(PilhaE* p){
    int i = 0;
    if(!pilha_vazia_pe(p)){
        for(i = p->topo; i >= 0; i--)
            printf(" %d\n", p->v[i]);
        printf("\n");
        return;
    }
    printf("\nA pilha esta vazia!");
    return;
}

void desenha_fe(FilaE* f){
    int i = 0;
    if(!fila_vazia_fe(f)){
        for(i = f->fim-1; i != f->inicio-1; i--)
            printf(" %d\n", f->v[(f->inicio + i)%MAX]);
        printf("\n");
        return;
    }
    printf("\nA fila esta vazia!");
    return;

}
