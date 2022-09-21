#include "FuncoesAuxiliares.h"


void desenha_pe(PilhaE* p){
    int i = 0;
    if(!pilha_vazia_pe(p)){
        for(i = p->topo; i >= 0; i--)
            printf(" %s\n", p->v[i]);
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

void desenha_potes(PilhaE** potes, int K){
    int i = 0, j = 0;
    int maior = 0;

    for(i = 0; i < K; i++){
        if(potes[i]->topo > maior) maior = potes[i]->topo;
    }
    printf("\n--POTES--\n");
    for(i = maior; i >= 0 ; i--){
        for(j = 0; j < K; j++){
            if(i <= potes[j]->topo)
                printf(" | %s | ", potes[j]->v[i]);
            else
                printf(" |n/a| ");
        }
        printf("\n");
    }
}

void desenha_fila(FilaE* fila){
    int i = 0;
    printf("\n--FILA--\n");
    for(i = 0; i < fila->tam; i++){
        printf("  %s x %s  ", fila->v[i][0],fila->v[i][1]);
        printf("\n");
    }
}
