#include "./TLSE.h"

int main (void) {
    TLSE *l1 = NULL;
    TLSE *l2 = NULL;
    TLSE *l3 = NULL;
    TLSE *l4 = NULL;

    l1 = TLSE_insere_inicio(l1, 4);
    l1 = TLSE_insere_inicio(l1, 3);
    l1 = TLSE_insere_inicio(l1, 2);
    l1 = TLSE_insere_inicio(l1, 2);
    l1 = TLSE_insere_inicio(l1, 7);
    l1 = TLSE_insere_inicio(l1, 6);
    l1 = TLSE_insere_inicio(l1, 1);
    l1 = TLSE_insere_inicio(l1, 12);
    l1 = TLSE_insere_inicio(l1, 15);

    printf("Lista Inserindo no Inicio: ");
    TLSE_imprime(l1);
    printf("\n");

    l2 = TLSE_insere_fim(l2, 4);
    l2 = TLSE_insere_fim(l2, 3);
    l2 = TLSE_insere_fim(l2, 2);
    l2 = TLSE_insere_fim(l2, 2);
    l2 = TLSE_insere_fim(l2, 7);
    l2 = TLSE_insere_fim(l2, 6);
    l2 = TLSE_insere_fim(l2, 1);
    l2 = TLSE_insere_fim(l2, 12);
    l2 = TLSE_insere_fim(l2, 15);

    printf("Lista Inserindo no Final: ");
    TLSE_imprime(l2);
    printf("\n");

    l3 = TLSE_insere_ordenado(l3, 4);
    l3 = TLSE_insere_ordenado(l3, 3);
    l3 = TLSE_insere_ordenado(l3, 2);
    l3 = TLSE_insere_ordenado(l3, 2);
    l3 = TLSE_insere_ordenado(l3, 7);
    l3 = TLSE_insere_ordenado(l3, 6);
    l3 = TLSE_insere_ordenado(l3, 1);
    l3 = TLSE_insere_ordenado(l3, 12);
    l3 = TLSE_insere_ordenado(l3, 15);

    printf("Lista Inserindo de forma ordenada: ");
    TLSE_imprime(l3);
    printf("\n");

    printf("Listas Unidas: ");
    l4 = union_all(l1, l2);
    TLSE_imprime(l4);
    printf("\n");

    printf("Listas Unidas sem duplicidade: ");
    TLSE_retira_duplicados(l4, 2);
    TLSE_imprime(l4);
    printf("\n");

    printf("Listas Invertida: ");
    l4 = inverte(l4);
    TLSE_imprime(l4);
    printf("\n");
    
    printf("Lista Misc: ");
    misc(l4, 1);
    TLSE_imprime(l4);
    printf("\n");
    
    // Liberando as Listas
    TLSE_libera(l1);
    TLSE_libera(l2);
    TLSE_libera(l3);
    TLSE_libera(l4);

    return 0;
}