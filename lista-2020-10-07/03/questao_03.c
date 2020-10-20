#include "./TLSE.h"

/*
    Q3) Considerando a declaração da Q1, escreva uma função em C que, dada uma lista l
    qualquer, desloque uma vez os elementos de l, de acordo com n. Se n é ímpar, o
    elemento que está na última posição passa a ser o primeiro quando a lista é deslocada.
    Senão, o elemento que está na primeira posição passa a ser o último. O protótipo desta
    função é o seguinte: TLSE* desloca (TLSE* l, int n).
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
    l = desloca(l,1);
    printf("Deslocamento impar para direita: ");
    TLSE_imprime(l);
    printf("\n");
    l = desloca(l,0);
    printf("Deslocamento par a esquerda: ");
    TLSE_imprime(l);
    printf("\n");
    return 0;
}