#include "FilaEstatica.h"

FilaE* cria_fila_fe(){
    FilaE* f = (FilaE*)malloc(sizeof(FilaE));
    f->inicio = 0;
    f->fim = 0;
    f->tam = 0;
    return f;
}
void push_fe(FilaE* f, char* x){
    strcpy(f->v[f->fim], x);
    f->fim = (f->fim + 1)%(MAXN/2);
    f->tam++;
    return;
}
char* pop_fe(FilaE* f){
    char* aux;
    aux = f->v[f->inicio];
    f->inicio = (f->inicio + 1)%(MAXN/2);
    f->tam--;
    return aux;
}
int fila_vazia_fe(FilaE *f){
    if(f->tam == 0) return 1;
    return 0;
}
void libera_fila(FilaE *f){
    free(f);
}
