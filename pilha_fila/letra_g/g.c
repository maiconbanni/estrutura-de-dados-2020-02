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
    
    (g) implemente uma função que receba três filas, f, impares e pares, e separe todos os valores
        guardados em f de tal forma que os valores pares são colocados na fila pares e os valores
        ímpares na impares. Ao final da execução desta função, f permanecerá com todos os seus
        elementos. O protótipo desta função é o seguinte: void separa_filas(TFila * f, TFila *par,
        TFila * impar).
*/

#include <stdio.h>
#include <stdlib.h>
#include "TF.h"

void separa_filas (TF *f, TF *par, TF *impar);

int main()
{
    TF *f = TF_inicializa();
    TF *fPar = TF_inicializa();
    TF *fImpar = TF_inicializa();

    int n = -1;
    while(1){
      scanf("%d", &n);
      if(n < 0) break;
      TF_insere(f, n);
    }
    printf("Fila Original: \n");
    TF_imprime(f);
    separa_filas(f, fPar, fImpar);
    printf("Fila Original após Separa: \n");
    TF_imprime(f);
    printf("Elementos Impares: \n");
    TF_imprime(fImpar);
    printf("Elementos Pares \n");
    TF_imprime(fPar);

    TF_libera(f);
    TF_libera(fPar);
    TF_libera(fImpar);
    return 0;
}

void separa_filas (TF *f, TF *fPar, TF *fImpar) {
    TF *fAux = TF_inicializa();
    if(TF_vazia(f)) return ;

    while(!TF_vazia(f)) {
        int element = TF_retira(f);
        TF_insere(fAux, element);
        if(element % 2)
            TF_insere(fImpar, element);
        else
            TF_insere(fPar, element);
    }

    while(!TF_vazia(fAux)) {
        int element = TF_retira(fAux);
        TF_insere(f, element);
    }

    TF_libera(fAux);
}