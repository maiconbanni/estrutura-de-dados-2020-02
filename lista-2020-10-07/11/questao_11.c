#include "./TLSE.h"

/*
Q11) Considerando a declaração da Q1, escreva uma função em C que, dada uma lista l
qualquer, ordene os elementos de l em uma outra lista de saída. Portanto, a lista de
entrada não pode ser alterada. O protótipo da função desta função é o seguinte: TLSE *
ordena (TLSE* l).
*/

int main (void) {
    TLSE *l = NULL;
    TLSE *uniao = NULL;

    l = TLSE_insere(l, 4);
    l = TLSE_insere(l, 3);
    l = TLSE_insere(l, 2);
    l = TLSE_insere(l, 2);
    l = TLSE_insere(l, 7);
    l = TLSE_insere(l, 6);
    l = TLSE_insere(l, 1);
    l = TLSE_insere(l, 12);
    l = TLSE_insere(l, 15);
    l = TLSE_insere(l, 112);
    l = TLSE_insere(l, 70);
    l = TLSE_insere(l, 60);

    printf("Lista: ");
    TLSE_imprime(l);
    printf("\n");
    printf("Lista Ordenada: ");
    TLSE_imprime(ordena(l));
    printf("\n");   
    return 0;
}