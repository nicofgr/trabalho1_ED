#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include "PilhaEstatica.h"
//#include "PilhaDinamica.h"
//#include "FilaEstatica.h"
//#include "FilaDinamica.h"
#include "FuncoesAuxiliares.h"

int main()
{
    srand(time(NULL));
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

    ///JOGOS
    PilhaE** placar = cria_pilha_pe(1);
    for(j = 0; fila->tam > 1; j++){
        printf("\nDia %d:", j+1);
        char venc[2][MAX];
        for(i = 0; i < 2; i++){
            char cmptdr[2][MAX];
            int val1;
            int val2;
            val1 = rand()%7;
            do{ val2 = rand()%7; }while(val1 == val2);
            pop_fe(fila, cmptdr[0], cmptdr[1]);
            printf("\n\t%s %d x %d %s", cmptdr[0], val1, val2, cmptdr[1]);
            if(val1 > val2){
                strcpy(venc[i], cmptdr[0]);
                push_pe(placar[0], cmptdr[1]);
            }else{
                strcpy(venc[i], cmptdr[1]);
                push_pe(placar[0], cmptdr[0]);
            }
        }
        //printf("\nVencedores: %s e %s", venc[0], venc[1]);
        printf("\n");
        push_fe(fila, venc[0], venc[1]);
    }

    char venc[MAX];
    printf("\nGrande final: ");
    char cmptdr[2][MAX];
    int val1;
    int val2;
    val1 = rand()%7;
    do{ val2 = rand()%7; }while(val1 == val2);
    pop_fe(fila, cmptdr[0], cmptdr[1]);
    printf("\n\t%s %d x %d %s", cmptdr[0], val1, val2, cmptdr[1]);
    if(val1 > val2){
        push_pe(placar[0], cmptdr[1]);
        push_pe(placar[0], cmptdr[0]);
    }else{
        push_pe(placar[0], cmptdr[0]);
        push_pe(placar[0], cmptdr[1]);
    }

    ///PLACAR
    printf("\n\n Campeao: %s", pop_pe(placar[0]));
    printf("\n    Vice: %s", pop_pe(placar[0]));
    for(i = 0; placar[0]->topo >= 0; i++){
        printf("\n%do lugar: %s",i+3, pop_pe(placar[0]));
    }

    //desenha_fila(fila);

    return 0;
}
