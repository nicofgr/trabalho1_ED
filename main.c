#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#include "PilhaEstatica.h"
#include "PilhaDinamica.h"
//#include "FilaEstatica.h"
#include "FilaDinamica.h"

#define MAXRAND 8 //Nro maximo para o gerador aleatorio usado nas disputas

int main(){
    srand(time(NULL));
    int i = 0, j = 0; //Variaveis auxiliares
    int N = 0; //Nro de times;
    int K = 0; //Nro de potes;

    ///TESTE DE ESTRUTURAS ATIVAS
    //teste_pilha();
    //teste_fila();

    ///----LEITURA POTES----
    scanf("%d %d", &N, &K);     //Le nro de times e potes 
    Pilha** potes = (Pilha**)malloc(K*sizeof(Pilha*));      //Aloca um vetor de potes (pilhas)
    for(i = 0; i < K; i++)
        potes[i] = cria_pilha();      //Aloca os potes no vetor
    for(i = 0; i < N; i++){     //Le os jogadores escritos pelo usuario e distribui nos potes
        char pais[MAX];
        scanf("%s", pais);
        push_pilha(potes[i%K], pais);
    }

    ///----FILA INICIAL----
    /*  Cria uma fila e "enche" ela com os
        competidores retirados dos potes.
    */
    Fila* fila = cria_fila();
    for(i = 0; i < N; i++){     //Loop para percorrer os potes
        char* cptdr1;
        char* cptdr2;
        cptdr1 = pop_pilha(potes[i%K]);
        i++;
        cptdr2 = pop_pilha(potes[i%K]);
        push_fila(fila, cptdr1, cptdr2);
        free(cptdr1);
        free(cptdr2);
    }

    ///----LIMPEZA POTES----
    for(i = 0; i < K; i++){
        libera_pilha(potes[i]);
    }
    free(potes);

    
    //----MEDE ESPACAMENTO----
    /*  Mede o espacamento necessario para
         alinhar a fila
    */
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

    /*----DESENHA FILA INICIAL----
        Desenha os times nas telas levando
        em conta o espacamento medido
     */
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

    ///----JOGOS----
    /*  Realiza as competicoes retirando os
        competidores das filas, colocando o
        perdedor no placar e mandando o 
        vencedor para o final da fila
    */
    Pilha* placar = cria_pilha();
    for(j = 0; tam_fila(fila) >= 1; j++){  //Contagem dos dias
        if(tam_fila(fila) == 1) printf("\nGrande final: \n");  //Verifica se esta no ultimo jogo
        else printf("\nDia %d:\n", j+1);
        char venc[2][MAX];  //Vencedores das duas partidas do dia
        int ultimaPartida = 0;
        for(i = 0; i < 2; i++){  //Duas competicoes pode dia (tarde e noite)
            char cmptdr[2][MAX]; //Dois competidores
            int val1 = rand()%MAXRAND;
            int val2 = rand()%MAXRAND;
            while(val1 == val2){
                val2 = rand()%MAXRAND;
            }
            pop_fila(fila, cmptdr[0], cmptdr[1]);  //Recebe os competidores da fila

            int tam = strlen(cmptdr[0]);  //Arruma o espacamento pro terminal
            for(j = 0; j < (maior-tam); j++) printf(" ");
            printf("     %s %d x %d %s\n", cmptdr[0], val1, val2, cmptdr[1]);

            //COMPETICAO
            if(val1 > val2){
                strcpy(venc[i], cmptdr[0]);  //Vencedor 0
                push_pilha(placar, cmptdr[1]); //Perdedor pro placar
            }else{
                strcpy(venc[i], cmptdr[1]);  //Vencedor 1
                push_pilha(placar, cmptdr[0]);  //Perdedor pro placar
            }
            if(tam_fila(fila) == 0 && i == 0){  //Se acabou a fila em um turno
                ultimaPartida = 1; //Estava na ultima partida
                break;
            }
        }
        if(ultimaPartida){  //Se estava na ultima partida
            push_pilha(placar, venc[0]); //Manda o vencedor pro placar
            break;
        }
        push_fila(fila, venc[0], venc[1]); //Manda os vencedores da partida pro fim da fila
    }

    ///----LIMPA FILA----
    libera_fila(fila);
    //free(fila);

    ///----PLACAR----
    /*  Desenha o placar retirando os nomes
        de uma pilha (placar)
    */
    char* nomes;
    nomes = pop_pilha(placar);  //Tira da pilha
    printf("\n  Campeao: %s\n", nomes);
    free(nomes);
    nomes = pop_pilha(placar);  //Tira da pilha
    printf("     Vice: %s\n", nomes);
    free(nomes);
    for(i = 0; !pilha_vazia(placar); i++){
        nomes = pop_pilha(placar);  //Tira da pilha
        if(i+3 < 10) printf(" ");  //Espacamento para acima de 10
        printf("%do lugar: %s\n",i+3, nomes);
        free(nomes);
    }

    ///----LIMPA RESTANTE----
    libera_pilha(placar);

    return 0;
}
