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
    
    (f) escreva uma função que, dada uma pilha p, retorne uma fila, contendo todos os elementos
        de p, e obedecendo a ordem de entrada dos inteiros em p, isto é, o primeiro inteiro que sair da
        pilha p deve ser o primeiro inteiro a sair da fila. Não é possível alterar a ordem dos elementos
        da pilha de entrada. A função deve obedecer o seguinte protótipo: TFila* p2f (TPilha *p);
*/

#include <stdio.h>
#include <stdlib.h>
#include "TF.h"
#include "TP.h"

TF* p2f (TP *p);

int main()
{
    TP *p = TP_inicializa();

    int n = -1;
    while(1){
      scanf("%d", &n);
      if(n < 0) break;
      TP_push(p, n);
    }
    printf("Pilha Original: \n");
    TP_imprime(p);
    TF *f = p2f(p);
    printf("Pilha Após a função p2f: \n");
    TP_imprime(p);
    printf("Fila \n");
    TF_imprime(f);

    TF_libera(f);
    TP_libera(p);
    return 0;
}

TF * p2f (TP *p)
{
    TF *f = TF_inicializa();
    if(TP_vazia(p)) return f;

    TP *pAux = TP_inicializa();
    while(!TP_vazia(p)) {
        int element = TP_pop(p);
        TP_push(pAux, element);
        TF_insere(f, element);
    }

    while(!TP_vazia(pAux)) {
        int element = TP_pop(pAux);
        TP_push(p, element);
    }

    TP_libera(pAux);
    return f;
}