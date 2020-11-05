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
    
    (b) uma função que, dada uma fila f, retorne uma nova fila, com todos os elementos de f,
        porém invertida em relação a fila f. Não é possível alterar a ordem dos elementos da fila de
        entrada. A função deve obedecer o seguinte protótipo: TFila* inv_fila (TFila *f);
*/

#include <stdio.h>
#include <stdlib.h>
#include "TF.h"
#include "TP.h"

TF * inv_fila (TF *f);

int main()
{
    TF *f = TF_inicializa();

    int n = -1;
    while(1){
      scanf("%d", &n);
      if(n < 0) break;
      TF_insere(f, n);
    }
    printf("Fila Original: \n");
    TF_imprime(f);
    TF *nFila = inv_fila(f);
    printf("Fila Original após a função inv_fila: \n");
    TF_imprime(f);
    printf("Fila Invertida \n");
    TF_imprime(nFila);

    TF_libera(f);
    TF_libera(nFila);
    return 0;
}

TF * inv_fila (TF *f) {
    if(TF_vazia(f)) return f;
    TF *fInv = TF_inicializa();
    TP *p1 = TP_inicializa();
    TP *p2 = TP_inicializa();

    while(!TF_vazia(f)) {
        int element = TF_retira(f);
        TP_push(p1, element);
    }

    while(!TP_vazia(p1)) {
        int element = TP_pop(p1);
        TF_insere(fInv, element);
        TP_push(p2, element);
    }

    while(!TP_vazia(p2)) {
        int element = TP_pop(p2);
        TF_insere(f, element);
    }

    TP_libera(p1);
    TP_libera(p2);
    return fInv;
}