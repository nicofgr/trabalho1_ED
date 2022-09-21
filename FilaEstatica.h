#ifndef FILAESTATICA_H_INCLUDED
#define FILAESTATICA_H_INCLUDED
#define MAX 100

typedef struct FilaE{
    int v[MAX];
    int inicio;
    int fim;
    int tam;
}FilaE;

FilaE* cria_fila_fe();
void push_fe(FilaE *p, int x);
int pop_fe(FilaE *p);
int fila_vazia_fe(FilaE *p);
void libera_fila_fe(FilaE *p);


#endif // FILAESTATICA_H_INCLUDED
