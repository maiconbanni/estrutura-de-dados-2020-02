#include "./TLSE.h"

/*
    Q9) Considerando a definição de lista de Q1, escreva uma função em C que, dadas duas
    listas, faça a concatenação das mesmas ao final de l1. O protótipo da função é o seguinte:
    TLSE* junta_listas (TLSE* l1, TLSE* l2).
*/

int main (void) {
    TLSE *l1 = NULL;
    TLSE *l2 = NULL;
    TLSE *uniao = NULL;

    l1 = TLSE_insere(l1, 1);
    l1 = TLSE_insere(l1, 2);
    l1 = TLSE_insere(l1, 3);

    l2 = TLSE_insere(l2, 4);
    l2 = TLSE_insere(l2, 5);
    l2 = TLSE_insere(l2, 6);

    printf("Lista 1: ");
    TLSE_imprime(l1);
    printf("\n");
    printf("Lista 2: ");
    TLSE_imprime(l2);
    printf("\n");
    
    uniao = junta_listas(l1, l2);
    printf("Junção l1 + l2: ");
    TLSE_imprime(uniao);
    printf("\n");
    
    return 0;
}