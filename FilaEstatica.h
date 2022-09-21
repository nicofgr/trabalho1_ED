#ifndef FILAESTATICA_H_INCLUDED
#define FILAESTATICA_H_INCLUDED
#define MAX 100
#define MAXN 50
#define MAXK 20

#include<string.h>

typedef struct FilaE{
    char v[MAXN/2][2][MAX];
    int inicio;
    int fim;
    int tam;
}FilaE;

FilaE* cria_fila_fe();
void push_fe(FilaE *f, char* x, char* y);
char** pop_fe(FilaE *f);
int fila_vazia_fe(FilaE *f);
void libera_fila_fe(FilaE *f);


#endif // FILAESTATICA_H_INCLUDED
