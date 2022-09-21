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

    ///TESTES PARA VERIFICAR A PILHA
    for(i = 0; i < K; i++){
        printf("\nPote %d:\n", i);
        desenha_pe(potes[i]);
    }
    desenha_potes(potes, K);

    ///FILA
    FilaE* fila = cria_fila_fe();
    //Para sabermos em qual elemento o ultimo time foi colocado, fazemos N%K
    for(i = 0; i < N; i++){
        char x[MAX];
        char y[MAX];
        strcpy(x, pop_pe(potes[i%K]));
        i++;
        strcpy(y, pop_pe(potes[i%K]));
        printf("\nCopiado: %s e %s", x, y);
        push_fe(fila,x,y);
        printf("\nAQUI-2");
    }

    desenha_fila(fila);

    return 0;
}
