#include "FilaDinamica.h"

Fila* cria_fila(){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->fim = NULL;
    f->inicio = NULL;
    f->tam = 0;
    return f;
}
void push_fila(Fila* f, char* cptdr1, char* cptdr2){
    NodoFila* novo = (NodoFila*)malloc(sizeof(NodoFila));
    strcpy(novo->info[0], cptdr1);
    strcpy(novo->info[1], cptdr2);
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
void pop_fila(Fila* f, char* dest1, char* dest2){
    NodoFila* aux = f->inicio;
    f->inicio = f->inicio->prox;
    strcpy(dest1, aux->info[0]);
    strcpy(dest2, aux->info[1]);
    free(aux);
    f->tam--;
}
int tam_fila(Fila* f){
    return f->tam;
}
int fila_vazia(Fila* f){
    if(f->tam == 0) return 1;
    return 0;
}
void libera_fila(Fila* f){
    while(!fila_vazia(f)){
        pop_fila(f, NULL);
    }
    free(f);
}
void teste_fila(){
    printf("+++Usando fila  dinamica+++\n");
}
