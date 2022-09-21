#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "PilhaEstatica.h"
//#include "PilhaDinamica.h"
//#include "FilaEstatica.h"
//#include "FilaDinamica.h"
#include "FuncoesAuxiliares.h"

int main()
{
    int i = 0, j = 0;
    int N = 0; //Nro de times;
    int K = 0; //Nro de potes;
    char teste[5][100];

    ///LEITURA
    scanf("%d %d", &N, &K);
    PilhaE** potes = cria_pilha_pe(K);
    for(i = 0; i < N; i++){
        scanf("%s", teste[i]);
        push_pe(potes[i%K], teste[i]);
    }

    ///TESTES
    for(i = 0; i < K; i++){
        printf("\nPote %d:\n", i);
        desenha_pe(potes[i]);
    }
    desenha_potes(potes, K);

    ///FILA INICIAL
    FilaE* fila = cria_fila_fe();
    //Para sabermos em qual elemento o ultimo time foi colocado, fazemos N%K
    for(i = 0; i < N; i++){
        char x[MAX];
        char y[MAX];
        strcpy(x, pop_pe(potes[i%K]));
        i++;
        strcpy(y, pop_pe(potes[i%K]));
        push_fe(fila,x,y);
    }

    ///TESTES
    desenha_fila(fila);

    printf("\nDia %d:\n", 1);
    char** temp = (char**)malloc(2*sizeof(char*));
    temp[0] = (char*)malloc(MAX*sizeof(char));
    temp[1] = (char*)malloc(MAX*sizeof(char));
    temp = pop_fe(fila);
    //strcpy(temp, pop_fe(fila));
    printf("Testando o temp: %s e %s", temp[0], temp[1]);

    return 0;
}
