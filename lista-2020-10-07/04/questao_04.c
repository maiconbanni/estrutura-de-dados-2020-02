#include "./TLSE.h"

/*
    Q3) Considerando a declaração da Q1, escreva uma função em C que, dada uma lista l
    qualquer, desloque uma vez os elementos de l, de acordo com n. Se n é ímpar, o
    elemento que está na última posição passa a ser o primeiro quando a lista é deslocada.
    Senão, o elemento que está na primeira posição passa a ser o último. O protótipo desta
    função é o seguinte: TLSE* desloca (TLSE* l, int n).
*/

int main (void) {
    TAluno *l = NULL;
    TAluno *c = NULL;
    int x;
    l = insere_aluno(l, 1, 10);
    l = insere_aluno(l, 2, 9);
    l = insere_aluno(l, 3, 8);
    l = insere_aluno(l, 4, 7);
    l = insere_aluno(l, 5, 6);
    printf("Lista Original: ");
    imprime_aluno(l);
    printf("\n");    
    c = copia(l);
    printf("Copia: ");
    imprime_aluno(c);
    return 0;
}