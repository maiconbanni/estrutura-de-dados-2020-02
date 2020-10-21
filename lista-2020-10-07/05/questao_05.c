#include "./TLSE.h"

/*
    Q5) Considerando a definição de lista de Q1, escreva uma função em C que remova
    todas as ocorrências de um elemento numa lista. Seu protótipo O protótipo desta função é
    o seguinte: TLSE* rto (TLSE* l, int elem)
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
    printf("Lista após a remoção: ");
    l = rto (l, 0);
    TLSE_imprime(l);
    printf("\n");
    return 0;
}