#include <stdio.h>
#include <stdlib.h>

typedef struct lde{
  int info;
  struct lde *ant, *prox;
} TLDE;

TLDE* TLDE_insere(TLDE *l, int elem){
  TLDE *novo = (TLDE *) malloc(sizeof(TLDE));
  novo->ant = NULL;
  novo->prox = l;
  novo->info = elem;
  if(l) l->ant = novo;
  return novo;
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

TLDE* TLDE_busca(TLDE *l, int elem){
  TLDE *p = l;
  while(p){
    if(p->info == elem) return p;
    p = p->prox;
  } 
  return NULL;
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

void cross(TLDE *l1, TLDE *l2, int x) {
  TLDE *aux_l1 = l1;
  TLDE *aux_l2 = l2;
  while(aux_l1) {
    if(aux_l1->info != x) {
        aux_l1 = aux_l1->prox;
    } else {
      TLDE *sobrou_l1 = aux_l1->prox;
      TLDE *sobrou_l2;
      while(aux_l2 && aux_l2->info != x) aux_l2 = aux_l2->prox;
      if(aux_l2) sobrou_l2 = aux_l2->prox;
      if(sobrou_l1) sobrou_l1->ant = aux_l2;
      if(sobrou_l2) sobrou_l2->ant = aux_l1;
      if(aux_l2) {
          aux_l2->prox = sobrou_l1;
          aux_l2 = aux_l2->prox;
      }
      aux_l1->prox = sobrou_l2;
      aux_l1 = aux_l1->prox;
    }
  }
}

int main(void){
  int x;
  TLDE *l1 = NULL;
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l1 = TLDE_insere(l1, x);
  }while(1);
  
  TLDE *l2 = NULL;
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l2 = TLDE_insere(l2, x);
  }while(1);

  scanf("%d", &x);
  cross(l1, l2, x);
  TLDE_imprime(l1);
  printf("\n");
  TLDE_imprime(l2);
  printf("\n");
  
  TLDE_libera(l1);
  TLDE_libera(l2);  
  return 0;
}