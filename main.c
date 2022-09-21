#include <stdio.h>
#include <stdlib.h>
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

    scanf("%d %d", &N, &K);
    PilhaE** potes = cria_pilha_pe(K);
    for(i = 0; i < N; i++){
        scanf("%s", teste[i]);
        push_pe(potes[i%K], teste[i]);
    }

    for(i = 0; i < N; i++){
        printf("Time %d: %s\n",i, potes[i%K]);
    }

    printf("\nPote 1:\n");
    desenha_pe(potes[0]);
    printf("\nPote 2:\n");
    desenha_pe(potes[1]);

    printf("\n--POTES--\n");
    for(i = 0; i < 3 ; i++){
        for(j = 0; j < K; j++)
            printf(" | %s | ", pop_pe(potes[j]));
        printf("\n");
    }



    return 0;
}
