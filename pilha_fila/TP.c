#include "TP.h"

TP *TP_inicializa (void){
  TP *p = (TP *) malloc(sizeof (TP));
  p->topo = 0;
  return p;
}

int TP_vazia (TP *p){
  return p->topo == 0;
}

int TP_pop(TP *p){
  if(TP_vazia(p)) exit(1);
  int resp = p->vet[--p->topo];
  return resp;
}

void TP_libera(TP *p){
  free(p);
}

void TP_push(TP *p, int x){
  if(p->topo == MAX_TAM) exit(1);
  p->vet[p->topo++] = x;
}

void TP_imprime(TP *p){
  int i;
  for(i = p->topo - 1; i >= 0; i--)
    printf("%d -> %d\n", p->topo - i, p->vet[i]);
}
