#include <stdio.h>
#include <stdlib.h>

#define MAX_TAM 100

typedef struct pilha{
  int topo;
  int vet[MAX_TAM];
}TP;


void TP_push(TP *p, int elem);
int TP_pop(TP *p);
int TP_vazia(TP *p);
TP *TP_inicializa(void);
void TP_libera(TP *p);
void TP_imprime(TP *p);
