#include "TLDE.h"

TLDE* TLDE_insere_inicio(TLDE *l, int elem){
  TLDE *novo = (TLDE *) malloc(sizeof(TLDE));
  novo->ant = NULL;
  novo->prox = l;
  novo->info = elem;
  if(l) l->ant = novo;
  return novo;
}

TLDE* TLDE_insere_fim(TLDE *l, int elem){
  TLDE *novo = (TLDE *) malloc(sizeof(TLDE));
  novo->info = elem;
  novo->prox = NULL;
  
  if(l == NULL) {
    l = novo;
  } else {
	TLDE *auxiliar = l;
    while(auxiliar->prox != NULL) auxiliar = auxiliar->prox;
    novo->ant = auxiliar;
    auxiliar->prox = novo;
  }
  return l;
}

TLDE* TLDE_insere_ordenado(TLDE *l, int elem){
  TLDE *p = l, *atual;
  TLDE *novo = (TLDE *) malloc(sizeof(TLDE));
  novo->ant = NULL;
  novo->info = elem;
  novo->prox = NULL;

  if(l == NULL) {
    printf("lista vazia...\n");
    l = novo;
    return l;
  }

  if (novo->info <= p->info){
    printf("Elemento na cabeça da Lista...\n");
    novo->prox = l;
    l->ant = novo;
    l = novo;
    return l;
  }
  // Andando com P até a posição onde precisa ser inserida
  while(p && p->info < elem){
    atual = p;
    p = p->prox;
  }

  atual->prox = novo;
  novo->ant = atual;
  novo->prox = p;
  return l;
}

void TLDE_imprime(TLDE *l){
  TLDE *p = l;
  while(p){
    printf("%d ", p->info);
    p = p->prox;
  } 
}

void TLDE_libera(TLDE *l){
  TLDE *p = l, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
  } 
}

TLDE* TLDE_retira(TLDE *l, int elem){
  TLDE *p = TLDE_busca(l, elem);
  if(!p) return l;
  if(p == l) l = l->prox;
  else p->ant->prox = p->prox;
  if(p->prox) p->prox->ant = p->ant;
  free(p);
  return l;
}

TLDE* TLDE_busca(TLDE *l, int elem){
  TLDE *p = l;
  while(p){
    if(p->info == elem) return p;
    p = p->prox;
  } 
  return NULL;
}

void TLDE_ordena(TLDE *l) {
  if(l == NULL || l->prox == NULL) return;
  TLDE *atual = l;
  TLDE *proximo = l->prox;
  while(atual) {
    while(proximo) {
      if(atual->prox > proximo->prox) {
        int aux = atual->info;
        atual->info = proximo->info;
        proximo->info = aux; 
      }
      proximo = proximo->prox;
    }
    atual = atual->prox;
  }
}