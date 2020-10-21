#include "./TLSE.h"

/*
    Q7) Refaça Q6, alterando a lista passada como parâmetro. O protótipo desta função é o
    seguinte: void* i_p ( TLSE *l).
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
    l = i_pv (l);
    TLSE_imprime(l);
    printf("\n");
    return 0;
}