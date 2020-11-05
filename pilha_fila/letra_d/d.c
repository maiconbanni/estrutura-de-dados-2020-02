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
    
    (d) escreva uma função que, dadas duas filas f1 e f2, retorne uma fila, contendo todos os
        elementos de f1 seguidos pelos elementos de f2, e obedecendo a ordem de entrada dos
        inteiros nas filas de entrada. Além disso, as filas de entrada devem permanecer inalteradas. A
        função deve obedecer ao seguinte protótipo: TFila* Junta_Filas (TFila *f1, TFila *f2);
*/

#include <stdio.h>
#include <stdlib.h>
#include "TF.h"

TF * Junta_Filas (TF *f1, TF *f2);

int main()
{
    TF *fila1 = TF_inicializa();
    TF *fila2 = TF_inicializa();

    int n = -1;
    while(1){
      scanf("%d", &n);
      if(n < 0) break;
      TF_insere(fila1, n);
    }

    while(1){
      scanf("%d", &n);
      if(n < 0) break;
      TF_insere(fila2, n);
    }

    printf("Fila 1 Original: \n");
    TF_imprime(fila1);
    
    printf("Fila 2 Original: \n");
    TF_imprime(fila2);
    
    TF *fUnion = Junta_Filas(fila1, fila2);
    printf("Listas Unidas: \n");
    TF_imprime(fUnion);

    printf("Fila 1 Pos Union: \n");
    TF_imprime(fila1);
    
    printf("Fila 2 Pos Union: \n");
    TF_imprime(fila2);

    TF_libera(fila1);
    TF_libera(fila2);
    TF_libera(fUnion);
    return 0;
}

TF * Junta_Filas (TF *f1, TF *f2) {
    TF *fUnion = TF_inicializa();
    TF *fAux = TF_inicializa();

    while(!TF_vazia(f1)) {
        int element = TF_retira(f1);
        TF_insere(fAux, element);
        TF_insere(fUnion, element);
    }

    while(!TF_vazia(fAux)) {
        int element = TF_retira(fAux);
        TF_insere(f1, element);
    }

    while(!TF_vazia(f2)) {
        int element = TF_retira(f2);
        TF_insere(fAux, element);
        TF_insere(fUnion, element);
    }

    while(!TF_vazia(fAux)) {
        int element = TF_retira(fAux);
        TF_insere(f2, element);
    }

    TF_libera(fAux);
    return fUnion;
}