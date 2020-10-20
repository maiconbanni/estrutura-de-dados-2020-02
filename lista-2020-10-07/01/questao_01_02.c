#include "./TLSE.h"

/*
    Q1) Considerando as seguintes declarações de lista encadeada:
    typedef struct lista { int info; struct lista *prox; } TLSE;
    Escreva uma função em C que, dada uma lista l qualquer, inverta os elementos de l.
    O protótipo da função de inversão é o seguinte: void inverte (TLSE* l);

    Q2) Refaça a Q1, escrevendo uma função em C que, dada uma lista l qualquer, inverta os
    elementos de l em uma outra lista de saída. Portanto, a lista de entrada não pode ser
    alterada. O protótipo da função de inversão é o seguinte: TLSE* inverte (TLSE* l).

*/

int main (void) {
    TLSE *l = NULL;
    TLSE *li = NULL;
    int x;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLSE_insere(l, x);
    } while(1);
    printf("Lista Original: ");
    TLSE_imprime(l);    
    printf("\n");    
    inverte_l(l);
    printf("Inverte l: ");
    TLSE_imprime(l);
    printf("\n");
    li = inverte_nl(l);
    printf("Inverte nl: ");
    TLSE_imprime(li);
    printf("\n");
    return 0;
}