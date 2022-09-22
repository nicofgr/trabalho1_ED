#include "FilaDinamica.h"

Fila* cria_fila(){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->fim = NULL;
    f->inicio = NULL;
    f->tam = 0;
    return f;
}
void push_fila(Fila *f, char* x){
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(novo->info, x);
    if(f->tam == 0){
        f->inicio = novo;
        f->fim = novo;
    }else{
        f->fim->prox = novo;
        f->fim = novo;
    }
    f->fim->prox = NULL;
    f->tam++;
}
pop_fila(Fila *f, char* dest){
    Nodo* aux = f->inicio;
    f->inicio = f->inicio->prox;
    strcpy(dest, aux->info);
    free(aux);
    f->tam--;
}
int tam_fila(Fila *f){
    return f->tam;
}
int fila_vazia(Fila *f){
    if(f->tam == 0) return 1;
    return 0;
}
void libera_fila(Fila *f){
    while(!fila_vazia(f)){
        pop_fila(f, NULL);
    }
    free(f);
}
