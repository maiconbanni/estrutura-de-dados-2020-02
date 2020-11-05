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
    
    (c) uma função que, dada uma fila f, retorne uma nova fila contendo os elementos pares de f,
        e modifique a fila original (f) para que ela possua somente os elementos ímpares,
        respeitando a ordem de entrada em f. A função deve obedecer o seguinte protótipo:
        TFila* sep_fila (TFila *f);
*/

#include <stdio.h>
#include <stdlib.h>
#include "TF.h"

TF * sep_fila (TF *f);

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
    TF *fPar = sep_fila(f);
    printf("Elementos Impares: \n");
    TF_imprime(f);
    printf("Elementos Pares \n");
    TF_imprime(fPar);

    TF_libera(f);
    TF_libera(fPar);
    return 0;
}

TF * sep_fila (TF *f) {
    if(TF_vazia(f)) return f;
    TF *fPares = TF_inicializa();
    TF *fImpares = TF_inicializa();

    while(!TF_vazia(f)) {
        int element = TF_retira(f);
        if(element % 2)
            TF_insere(fImpares, element);
        else
            TF_insere(fPares, element);
    }

    while(!TF_vazia(fImpares)) {
        int element = TF_retira(fImpares);
        TF_insere(f, element);
    }

    TF_libera(fImpares);
    return fPares;
}