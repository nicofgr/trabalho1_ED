#include "FilaEstatica.h"

FilaE* cria_fila_fe(){
    FilaE* f = (FilaE*)malloc(sizeof(FilaE));
    f->inicio = 0;
    f->fim = 0;
    f->tam = 0;
    return f;
}
void push_fe(FilaE* f, char* x, char* y){
    strcpy(f->v[f->fim][0], x);
    strcpy(f->v[f->fim][1], y);
    f->fim = (f->fim + 1)%(MAXN/2);
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
