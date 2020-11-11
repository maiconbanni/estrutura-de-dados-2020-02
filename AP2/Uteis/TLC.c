#include "TLC.h"

TLC* retira(TLC* l, int x) {
  if (!l) return l;

  // primeiro elemento aponta pra ele mesmo
  if (l->info == x && l == l->prox) {
    free(l);
    return NULL;
  }

  TLC *head = l, *ant = l, *p = l->prox;

  while (p != head && p->info != x) {
    ant = p;
    p = p->prox;
  }

  if (p == l && p->info != x)
    return l;

  if (p == l) {
    l = l->prox;
  }

  ant->prox = p->prox;
  free(p);
  return l;
}

void libera(TLC* l) {
  if (!l) return;

  if (l->prox == l) {
    free(l);
    return;
  }

  TLC *p = l->prox, *q;

  while (p != l) {
    q = p;
    p = p->prox;
    free(q);
  }
  free(l);
}

TLC* inserir_inicio(TLC* l, int x){
  TLC *novo = (TLC*) malloc(sizeof(TLC));
  novo->info = x;
  // primeiro elemento
  if (!l) {
    novo->prox = novo;
    return novo;
  }

  novo->prox = l;
  
  TLC* p = l->prox;
  // acha o final da lista e coloca ele apontando para o novo
  while (p->prox != l) {
    p = p->prox;
  }
  p->prox = novo;

  return novo;
}

TLC* inserir_fim(TLC *l, int x){
  TLC* novo = (TLC*) malloc (sizeof(TLC));
  novo->info= x;
  
  if(!l){
    novo->prox = novo;
    return novo;
  }
  
  TLC *p = l->prox, *ant = l;
  
  while(p != l){
    ant = p;
    p = p->prox;
  }
  
  novo->prox = l;
  ant->prox = novo;
  
  return l;
}

void imprimir(TLC* l) {
  if (!l) return;
  printf("%d - ",l->info);
  TLC *p = l->prox;
  while (p != l ){
    printf("%d - ",p->info);
    p = p->prox;
  }
}

TLC* inicializa() {
  return NULL;
}