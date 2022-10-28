#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#include "PilhaEstatica.h"
#include "PilhaDinamica.h"
//#include "FilaEstatica.h"
#include "FilaDinamica.h"

#define MAXRAND 8

int main(){
    srand(time(NULL));
    int i = 0, j = 0;
    int N = 0; //Nro de times;
    int K = 0; //Nro de potes;
    char teste[MAX];

    ///TESTES INCLUDE ATIVOS
    teste_pilha();
    teste_fila();

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
    Fila* fila = cria_fila();;
    for(i = 0; i < N; i++){
        char cptdr1[MAX];
        char cptdr2[MAX];
        pop_pilha(potes[i%K], cptdr1);
        i++;
        pop_pilha(potes[i%K], cptdr2);
        push_fila(fila, cptdr1, cptdr2);
    }

    ///LIMPEZA POTES
    for(i = 0; i < K; i++){
        libera_pilha(potes[i]);
    }
    free(potes);

    ///DESENHA FILA INICIAL
    int maior = 0;
    for(i = 0; i < tam_fila(fila); i++){
        for(j = 0; j < 2; j++){
            char temp1[MAX];
            char temp2[MAX];
            int tam1, tam2;
            pop_fila(fila, temp1, temp2);
            push_fila(fila,temp1, temp2);
            tam1 = strlen(temp1);
            tam2 = strlen(temp1);
            if(tam1 > maior) maior = tam1;
            if(tam2 > maior) maior = tam2;
        }
    }

    printf("\nFila inicial:\n");
    for(i = 0; i < tam_fila(fila); i++){
        char prim[MAX];
        char segn[MAX];
        int tam;
        pop_fila(fila, prim, segn);
        tam = strlen(prim);
        for(j = 0; j < (maior-tam); j++) printf(" ");
        printf("     %s x %s \n", prim, segn);
        push_fila(fila,prim, segn);
    }

    ///JOGOS
    Pilha* placar = cria_pilha();
    for(j = 0; tam_fila(fila) >= 1; j++){
        if(tam_fila(fila) == 1) printf("\nGrande final: \n");
        else printf("\nDia %d:\n", j+1);
        char venc[2][MAX];
        int ultimaPartida = 0;
        for(i = 0; i < 2; i++){
            char cmptdr[2][MAX];
            int val1 = rand()%MAXRAND;
            int val2 = rand()%MAXRAND;
            while(val1 == val2) val2 = rand()%MAXRAND;;
            pop_fila(fila, cmptdr[0], cmptdr[1]);
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
            if(tam_fila(fila) == 0 && i == 0){
                ultimaPartida = 1;
                break;
            }
        }
        if(ultimaPartida){
            push_pilha(placar, venc[0]);
            break;
        }
        push_fila(fila, venc[0], venc[1]);
    }

    ///LIMPA FILA
    libera_fila(fila);
    //free(fila);

    ///PLACAR
    char nomes[MAX];
    pop_pilha(placar, nomes);
    printf("\n  Campeao: %s\n", nomes);
    pop_pilha(placar, nomes);
    printf("     Vice: %s\n", nomes);
    for(i = 0; !pilha_vazia(placar); i++){
        pop_pilha(placar, nomes);
        if(i+3 < 10) printf(" ");
        printf("%do lugar: %s\n",i+3, nomes);
    }

    ///LIMPA RESTANTE
    libera_pilha(placar);

    //getch();

    return 0;
}
