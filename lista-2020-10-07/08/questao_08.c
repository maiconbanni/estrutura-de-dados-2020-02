#include "./TLSE.h"

/*
    Q8) Considerando as seguintes declarações de uma lista encadeada:

    typedef struct lista{
        int mat;
        char nome[81];
        float cr;
        struct lista *prox;
    } TLista;

    Escreva uma função em C que, dadas duas listas l1 e l2 encadeadas, verifique se l1 e l2
    são iguais. As listas l1 e l2 devem permanecer inalteradas. Esta função retorna 1 se as
    listas são iguais e 0, caso contrário. O protótipo desta função é o seguinte: int igual
    (TLista *l1, TLista *l2).
    OBS: protótipo de função que pode ser útil: int strcmp (char *s, char *t).
    */

int main (void) {
    TLista *l1 = NULL;
    TLista *l2 = NULL;

    l1 = TLista_insere(l1, 1, "Maicon Ribeiro Banni", 10.0);
    l1 = TLista_insere(l1, 2, "Thais Banni", 8.0);
    l1 = TLista_insere(l1, 3, "Álan Banni", 8.0);

    l2 = TLista_insere(l2, 1, "Maicon Ribeiro Banni", 10.0);
    l2 = TLista_insere(l2, 2, "Thais Banni", 8.0);
    l2 = TLista_insere(l2, 3, "Álan Banni", 8.0);

    printf("Lista 1: ");
    TLista_imprime(l1);
    printf("Lista 2: ");
    TLista_imprime(l2);

    printf("Listas Iguais? %s \n", igual(l1, l2) == 1 ? "SIM" : "NÃO");

    return 0;
}