#include <stdio.h>
#include <stdlib.h>

typedef struct lse {
  int info;
  struct lse *prox;
} TLSE;

void busca_e_insere (int x, int y, TLSE *le) {
   TLSE *p, *q, *nova;
   nova = malloc (sizeof (TLSE));
   nova->info = x;
   p = le;
   q = le->prox;
   while (q != NULL && q->info != y) {
      p = q;
      q = q->prox;
   }
   nova->prox = q;
   p->prox = nova;
}

void TLSE_insere(TLSE *l, int elem){
    TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
    novo->prox = l;
    novo->info = elem;
}

TLSE* TLSE_insere_ordenado(TLSE *l, int elem){
  TLSE *p = l, *ant = NULL;
  TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
  novo->info = elem;
  while(p && p->info < elem) {
    ant = p;
    p = p->prox;
  }
  if(ant == NULL) { // !ant
    novo->prox = l;
    l = novo;
  } else {
    novo->prox = ant->prox;
    ant->prox = novo;
  }
  return l;
}

TLSE* TLSE_insere_fim(TLSE *l, int elem){
    TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
    novo->prox = NULL;
    novo->info = elem;
    
    if(l == NULL) {
        l = novo;
    } else {
		  TLSE *auxiliar = l;
		  while(auxiliar->prox != NULL) auxiliar = auxiliar->prox;
		  auxiliar->prox = novo;
	}
  return l;
}

TLSE* TLSE_insere_(TLSE *l, int elem){
  TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
  novo->prox = l;
  novo->info = elem;
  return novo;
}

void TLSE_imprime(TLSE *l){
  TLSE *p = l;
  while(p){
    printf("%d ", p->info);
    p = p->prox;
  } 
}

int main (void) {
    TLSE *l = NULL;
    int x;
    do {
        scanf("%d", &x);
        if(x < 0) break;
        l = TLSE_insere_ordenado(l, x);
    } while(1);
    printf("Lista Original: ");
    TLSE_imprime(l);    
    printf("\n");
    return 0;
}