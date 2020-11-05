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
    
    (a) uma função que, dada uma fila f, retorne uma pilha, contendo todos os elementos de f, e
        obedecendo a ordem de entrada dos inteiros na fila f, isto é, o primeiro inteiro que sair da fila f
        deve ser o primeiro inteiro a sair da pilha. Não é possível alterar a ordem dos elementos da fila
        de entrada. A função deve obedecer o seguinte protótipo: TPilha* f2p (TFila *f);
*/

#include <stdio.h>
#include <stdlib.h>
#include "TF.h"
#include "TP.h"

TP* f2p (TF *f);

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
    TP *p = f2p(f);
    printf("Fila Após a função f2p: \n");
    TF_imprime(f);
    printf("pilha \n");
    TP_imprime(p);

    TF_libera(f);
    TP_libera(p);
    return 0;
}

TP* f2p (TF *f)
{
    TP *p = TP_inicializa();
    if(TF_vazia(f))
        return p;

    TF *fAux = TF_inicializa();
    TP *pAux = TP_inicializa();

    while(!TF_vazia(f)) {
        int element = TF_retira(f);
        TF_insere(fAux, element);
    }

    while(!TF_vazia(fAux)) {
        int element = TF_retira(fAux);
        TP_push(p, element);
        TF_insere(f, element);
    }

    TF_libera(fAux);
    TP_libera(pAux);
    return p;
}