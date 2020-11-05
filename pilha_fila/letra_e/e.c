/*
    Considere a existência de um tipo abstrato pilha de números inteiros, cuja a interface é
    definida no arquivo pilha.h da seguinte forma:
    typedef struct pilha TPilha;
    TPilha * inicializa (void);
    void push (TPilha *p, int elem);
    int pop (TPilha *p);
    void libera (TPilha *p);
    int vazia (TPilha *p);

    Leve em consideração, também, a existência de um tipo abstrato fila de números inteiros, cuja
    a interface é definida no arquivo fila.h da seguinte forma:
        typedef struct fila TFila;
        TFila* inicializa (void);
        void insere (TFila *f, int elem);
        int retira (TFila *f);
        void libera (TFila *f);
        int vazia (TFila *f);
    Usando somente estas operações, escreva:
    
    (e) escreva uma função que receba uma pilha e retire todos os elementos pares desta pilha. A
        função deve obedecer o seguinte protótipo: void retira_pares (TPilha *p);
*/

#include <stdio.h>
#include <stdlib.h>
#include "TP.h"

void retira_pares (TP *p);

int main() {
    TP *p = TP_inicializa();

    int n = -1;
    while(1){
      scanf("%d", &n);
      if(n < 0) break;
      TP_push(p, n);
    }

    printf("Pilha Original: \n");
    TP_imprime(p);
    retira_pares(p);
    printf("Impares: \n");
    TP_imprime(p);
    TP_libera(p);
    return 0;
}

void retira_pares (TP *p) {
    TP *pImpar = TP_inicializa();

    while(!TP_vazia(p)) {
        int element = TP_pop(p);
        if(element % 2) TP_push(pImpar, element);
    }

    while(!TP_vazia(pImpar)) {
        int element = TP_pop(pImpar);
        TP_push(p, element);
    }
    TP_libera(pImpar);
}