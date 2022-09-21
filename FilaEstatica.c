#include "FilaEstatica.h"

FilaE* cria_fila_fe(){
    FilaE* f = (FilaE*)malloc(sizeof(FilaE));
    f->inicio = 0;
    f->fim = 0;
    f->tam = 0;
}
void push_fe(FilaE *f, int x){
    f->fim = (f->fim + 1)%MAX;
    f->v[f->fim] = x;
    f->tam++;
    return;
}
int pop_fe(FilaE *f){
    int x = f->v[f->inicio];
    f->inicio = (f->inicio + 1)%MAX;
    f->tam--;
    return x;
}
int fila_vazia_fe(FilaE *f){
    if(f->tam == 0) return 1;
    return 0;
}
