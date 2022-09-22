#include "FilaEstatica.h"

Fila* cria_fila(){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->inicio = 0;
    f->fim = 0;
    f->tam = 0;
    return f;
}
void push_fila(Fila* f, char* x){
    strcpy(f->v[f->fim], x);
    f->fim = (f->fim + 1)%(MAXN/2);
    f->tam++;
    return;
}
void pop_fila(Fila* f, char* dest){
    strcpy(dest, f->v[f->inicio]);
    f->inicio = (f->inicio + 1)%(MAXN/2);
    f->tam--;
}
int fila_vazia(Fila *f){
    if(f->tam == 0) return 1;
    return 0;
}
void libera_fila(Fila *f){
    free(f);
}
int tam_fila(Fila *f){
    return f->tam;
}
