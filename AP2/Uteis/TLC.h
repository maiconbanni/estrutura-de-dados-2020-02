#include <stdio.h>
#include <stdlib.h>

// Identica a lista encadeada, mas com o "último" elemento apontando para o "primeiro".
typedef struct lc {
  int info;
  struct lc *prox;
} TLC;

TLC* inicializa();
TLC* inserir_inicio(TLC* l, int x);
TLC* inserir_fim(TLC* l, int x);
TLC* retira(TLC* l, int x);

void libera(TLC* l);
void imprimir(TLC* l);
