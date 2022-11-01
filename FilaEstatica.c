#include "FilaEstatica.h"

Fila* cria_fila(){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->inicio = 0;
    f->fim = 0;
    f->tam = 0;
    return f;
}

void push_fila(Fila* f, char* cptdr1, char* cptdr2){
    strcpy(f->v[f->fim][0], cptdr1);
    strcpy(f->v[f->fim][1], cptdr2);
    f->fim = (f->fim + 1)%(MAXN/2);
    f->tam++;
    return;
}

void pop_fila(Fila* f, char* dest1, char* dest2){
    strcpy(dest1, f->v[f->inicio][0]);
    strcpy(dest2, f->v[f->inicio][1]);
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

//Pode ser usado no main para verificacao no terminal
void teste_fila(){
    printf("---Usando fila  estatica---\n");
}
