#include <stdio.h>
#include <stdlib.h>
//#include "PilhaEstatica.h"
//#include "PilhaDinamica.h"
//#include "FilaEstatica.h"
//#include "FilaDinamica.h"
#include "FuncoesAuxiliares.h"

int main()
{
    ///TESTE PILHA ESTATICA
    printf("--Pilha Estatica--\n");
    PilhaE* p = cria_pilha_pe();
    push_pe(p, 1);
    push_pe(p, 2);
    push_pe(p, 3);
    pop_pe(p);
    push_pe(p, 4);
    desenha_pe(p);

    ///TESTE FILA ESTATICA
    printf("--Fila Estatica--\n");
    FilaE* f = cria_fila_fe();
    push_fe(f, 1);
    push_fe(f, 2);
    push_fe(f, 3);
    pop_fe(f);
    push_fe(f, 4);
    desenha_fe(f);

    return 0;
}
