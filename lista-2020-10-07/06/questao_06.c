#include "./TLSE.h"

/*
    Q6) Considerando a definição de lista de Q1, escreva uma função em C que, dada uma
    lista l qualquer, retorne, numa lista de saída, os elementos ímpares e os elementos pares
    da lista l, na ordem em que os elementos aparecem em l. Ao final da execução desta
    função, a lista resultante terá todos os elementos da lista l (primeiro os ímpares, depois os
    pares, na ordem em que eles aparecem em l), e a lista l continuará contendo os seus
    elementos. O protótipo da função é o seguinte: TLSE* i_p ( TLSE *l).
*/

int main (void) {
    TLSE *l = NULL;
    int x;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLSE_insere(l, x);
    } while(1);
    printf("Lista Original: ");
    TLSE_imprime(l);
    printf("\n");
    printf("Lista impar/par: ");
    l = i_p (l);
    TLSE_imprime(l);
    printf("\n");
    return 0;
}