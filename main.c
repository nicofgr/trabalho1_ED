#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#include "PilhaEstatica.h"
#include "PilhaDinamica.h"
//#include "FilaEstatica.h"
#include "FilaDinamica.h"
//#include "FuncoesAuxiliares.h"

#define MAXRAND 8

int main(){
    srand(time(NULL));
    int i = 0, j = 0;
    int N = 0; //Nro de times;
    int K = 0; //Nro de potes;
    char teste[MAX];

    ///LEITURA POTES
    scanf("%d %d", &N, &K);
    Pilha** potes = (Pilha**)malloc(K*sizeof(Pilha*));
    for(i = 0; i < K; i++){
        potes[i] = cria_pilha();
    }
    for(i = 0; i < N; i++){
        scanf("%s", teste);
        push_pilha(potes[i%K], teste);
    }

    ///FILA INICIAL
    Fila** fila = (Fila**)malloc(2*sizeof(Fila*));
    fila[0] = cria_fila();
    fila[1] = cria_fila();
    for(i = 0; i < N; i++){
        char x[MAX];
        char y[MAX];
        pop_pilha(potes[i%K], x);
        i++;
        pop_pilha(potes[i%K], y);
        push_fila(fila[0],x);
        push_fila(fila[1],y);
    }

    ///LIMPEZA POTES
    for(i = 0; i < K; i++){
        libera_pilha(potes[i]);
    }
    free(potes);

    ///DESENHA FILA INICIAL
    int maior = 0;
    for(i = 0; i < tam_fila(fila[0]); i++){
        for(j = 0; j < 2; j++){
            char temp[MAX];
            int tam;
            pop_fila(fila[j], temp);
            push_fila(fila[j],temp);
            tam = strlen(temp);
            if(tam > maior) maior = tam;
        }
    }

    printf("\nFila inicial:\n");
    for(i = 0; i < tam_fila(fila[0]); i++){
        char prim[MAX];
        char segn[MAX];
        int tam;
        pop_fila(fila[0], prim);
        pop_fila(fila[1], segn);
        tam = strlen(prim);
        for(j = 0; j < (maior-tam); j++) printf(" ");
        printf("     %s x %s \n", prim, segn);
        push_fila(fila[0],prim);
        push_fila(fila[1],segn);
    }

    ///JOGOS
    Pilha* placar = cria_pilha();
    for(j = 0; tam_fila(fila[0]) >= 1; j++){
        if(tam_fila(fila[0]) == 1) printf("\nGrande final: \n");
        else printf("\nDia %d:\n", j+1);
        char venc[2][MAX];
        int ultimaPartida = 0;
        for(i = 0; i < 2; i++){
            char cmptdr[2][MAX];
            int val1 = rand()%MAXRAND;
            int val2 = rand()%MAXRAND;
            while(val1 == val2) val2 = rand()%MAXRAND;;
            pop_fila(fila[0], cmptdr[0]);
            pop_fila(fila[1], cmptdr[1]);
            int tam = strlen(cmptdr[0]);
            for(j = 0; j < (maior-tam); j++) printf(" ");
            printf("     %s %d x %d %s\n", cmptdr[0], val1, val2, cmptdr[1]);
            if(val1 > val2){
                strcpy(venc[i], cmptdr[0]);
                push_pilha(placar, cmptdr[1]);
            }else{
                strcpy(venc[i], cmptdr[1]);
                push_pilha(placar, cmptdr[0]);
            }
            if(tam_fila(fila[0]) == 0 && i == 0){
                ultimaPartida = 1;
                break;
            }
        }
        if(ultimaPartida){
            push_pilha(placar, venc[0]);
            break;
        }
        push_fila(fila[0], venc[0]);
        push_fila(fila[1], venc[1]);
    }

    ///LIMPA FILA
    libera_fila(fila[0]);
    libera_fila(fila[1]);
    free(fila);

    ///PLACAR
    char nomes[MAX];
    pop_pilha(placar, nomes);
    printf("\n  Campeao: %s", nomes);
    pop_pilha(placar, nomes);
    printf("\n     Vice: %s", nomes);
    for(i = 0; !pilha_vazia(placar); i++){
        pop_pilha(placar, nomes);
        printf("\n %do lugar: %s",i+3, nomes);
    }

    ///LIMPA RESTANTE
    libera_pilha(placar);

    return 0;
}
