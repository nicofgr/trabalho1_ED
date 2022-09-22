#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include "PilhaEstatica.h"
//#include "PilhaDinamica.h"
//#include "FilaEstatica.h"
//#include "FilaDinamica.h"
#include "FuncoesAuxiliares.h"

int main(){
    srand(time(NULL));
    int i = 0, j = 0;
    int N = 0; //Nro de times;
    int K = 0; //Nro de potes;
    char teste[MAX];

    ///LEITURA POTES
    scanf("%d %d", &N, &K);
    PilhaE** potes = (PilhaE**)malloc(K*sizeof(PilhaE*));
    for(i = 0; i < K; i++){
        potes[i] = cria_pilha_pe();
    }
    for(i = 0; i < N; i++){
        scanf("%s", teste);
        push_pe(potes[i%K], teste);
    }

    ///TESTES
    for(i = 0; i < K; i++){
        printf("\nPote %d:\n", i);
        desenha_pe(potes[i]);
    }
    desenha_potes(potes, K);

    ///FILA INICIAL
    FilaE** fila = (FilaE**)malloc(2*sizeof(FilaE*));
    fila[0] = cria_fila_fe();
    fila[1] = cria_fila_fe();
    for(i = 0; i < N; i++){
        char x[MAX];
        char y[MAX];
        strcpy(x, pop_pe(potes[i%K]));
        i++;
        strcpy(y, pop_pe(potes[i%K]));
        push_fe(fila[0],x);
        push_fe(fila[1],y);
    }
    ///LIMPEZA POTES
    for(i = 0; i < K; i++){
        libera_pilha(potes[i]);
    }
    free(potes);

    ///TESTES
    //desenha_fe(fila[0]);
    //desenha_fe(fila[1]);
    desenha_fila(fila);

    ///JOGOS
    PilhaE* placar = cria_pilha_pe();
    for(j = 0; fila[0]->tam > 1; j++){
        printf("\nDia %d:", j+1);
        char venc[2][MAX];
        for(i = 0; i < 2; i++){
            char cmptdr[2][MAX];
            int val1;
            int val2;
            val1 = rand()%7;
            do{ val2 = rand()%7; }while(val1 == val2);
            strcpy(cmptdr[0], pop_fe(fila[0]));
            strcpy(cmptdr[1], pop_fe(fila[1]));
            printf("\n\t%s %d x %d %s", cmptdr[0], val1, val2, cmptdr[1]);
            if(val1 > val2){
                strcpy(venc[i], cmptdr[0]);
                push_pe(placar, cmptdr[1]);
            }else{
                strcpy(venc[i], cmptdr[1]);
                push_pe(placar, cmptdr[0]);
            }
        }
        printf("\n");
        push_fe(fila[0], venc[0]);
        push_fe(fila[1], venc[1]);
    }

    printf("\nGrande final: ");
    char cmptdr[2][MAX];
    int val1;
    int val2;
    val1 = rand()%7;
    do{ val2 = rand()%7; }while(val1 == val2);
    strcpy(cmptdr[0], pop_fe(fila[0]));
    strcpy(cmptdr[1], pop_fe(fila[1]));
    printf("\n\t%s %d x %d %s", cmptdr[0], val1, val2, cmptdr[1]);
    if(val1 > val2){
        push_pe(placar, cmptdr[1]);
        push_pe(placar, cmptdr[0]);
    }else{
        push_pe(placar, cmptdr[0]);
        push_pe(placar, cmptdr[1]);
    }

    ///LIMPA FILA
    libera_fila(fila[0]);
    libera_fila(fila[1]);
    libera_fila(fila);

    ///PLACAR
    printf("\n\n Campeao: %s", pop_pe(placar));
    printf("\n    Vice: %s", pop_pe(placar));
    for(i = 0; placar->topo >= 0; i++){
        printf("\n%do lugar: %s",i+3, pop_pe(placar));
    }

    ///LIMPA RESTANTE
    libera_pilha(placar);

    return 0;
}
