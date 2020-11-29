#include <limits.h>
#include "./TP.h"

int maior(TP *p){
  if(TP_vazia(p)) return INT_MIN;
  int resp = TP_pop(p), prox;
  TP *aux = TP_inicializa();
  while(!TP_vazia(p)){
    prox = TP_pop(p);
    if(resp < prox){
      TP_push(aux, resp);
      resp = prox;
    }
    else TP_push(aux, prox);
  }
  while(!TP_vazia(aux)) TP_push(p, TP_pop(aux));
  TP_libera(aux);
  return resp;
}

void ordena(TP *p){
  if(TP_vazia(p)) return;
  TP *aux = TP_inicializa();
  while(!TP_vazia(p)) TP_push(aux, TP_pop(p));
  while(!TP_vazia(aux)){
    int x = maior(aux);
    TP_push(p, x);
  }
  TP_libera(aux);
}

int main(void){
    TP *p = TP_inicializa();
    printf("p:\n");
    int n;
    while(1){
      scanf("%d", &n);
      if(n < 0) break;
      TP_push(p, n);
    }
    TP_imprime(p);
    printf("\n");

    ordena(p);

    printf("p:\n");
    TP_imprime(p);
    printf("\n");
    TP_libera(p);

  return 0;
}

#include "TLSE.h"

TLSE* TLSE_insere(TLSE *l, int elem){
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

void TLSE_imp_rec(TLSE *l){
  if(l){
    printf("%d ", l->info);
    TLSE_imp_rec(l->prox);
  }
}

void TLSE_imp_rec_rev(TLSE *l){
  if(l){
    TLSE_imp_rec_rev(l->prox);
    printf("%d ", l->info);
  }
}

void TLSE_libera(TLSE *l){
  TLSE *p = l, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
  } 
}

void TLSE_lib_rec(TLSE *l){
  if(l){
    TLSE_lib_rec(l->prox);
    printf("liberando o elemento %d...\n", l->info);
    free(l);
  }
}

TLSE* TLSE_retira(TLSE *l, int elem){
  TLSE *p = l, *ant = NULL;
  while((p) && (p->info != elem)){
    ant = p;
    p = p->prox;
  }
  if(!p) return l;
  if(!ant) l = l->prox;
  else ant->prox = p->prox;
  free(p);
  return l;
}

TLSE* TLSE_busca(TLSE *l, int elem){
  TLSE *p = l;
  while((p) && (p->info != elem)) p = p->prox; 
  return p;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct lse{
  int info;
  struct lse *prox;
} TLSE;

TLSE* TLSE_insere(TLSE *l, int elem);
void TLSE_imprime(TLSE *l);
void TLSE_libera(TLSE *l);
TLSE* TLSE_retira(TLSE *l, int elem);
TLSE* TLSE_busca(TLSE *l, int elem);

void TLSE_imp_rec(TLSE *l);
void TLSE_imp_rec_rev(TLSE *l);
void TLSE_lib_rec(TLSE *l);

#include "TP.h"

TP *TP_inicializa(void){
  TP *p = (TP *)malloc(sizeof(TP));
  p->topo = NULL;
  return p;
}
	
int TP_vazia(TP *p){
  return (p->topo == NULL);
}
	
void TP_push(TP *p,int elem){
  p->topo = TLSE_insere(p->topo, elem);
  /*
  TLSE *novo = (TLSE *)malloc(sizeof(TLSE));
  novo->info = elem;
  novo->prox = p->topo;
  p->topo = novo;
  */
}

int TP_pop(TP *p){
  if (!TP_vazia(p)){
    TLSE *aux = p->topo;
    int x = aux->info;
    p->topo = aux->prox;
    free(aux);
    return x;
  }
  else{ // pilha vazia
    exit(1);
  }
}

void TP_libera(TP *p){
  TLSE_libera(p->topo);
  /*
  TLSE *q = p->topo,*r ;
  while(q){
    r = q;
    q = q->prox;
    free(r);
  }
  */
  free(p);
}

void TP_imprime(TP *p){
  TP *aux = TP_inicializa();
  int ind = 1;
  while (!TP_vazia(p)){
    int x = TP_pop(p);
    printf("%d -> %d\n", ind++, x);
    TP_push(aux,x);
  }
  while(!TP_vazia(aux)) TP_push(p, TP_pop(aux));
  TP_libera(aux);
}

#include "TLSE.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct pilha{
  TLSE *topo;
}TP;	


void TP_push(TP *p, int elem);
int TP_pop(TP *p);
int TP_vazia(TP *p);
TP *TP_inicializa(void);
void TP_libera(TP *p);
void TP_imprime(TP *p);

#include "TP.h"

TP *TP_inicializa (void){
  TP *p = (TP *) malloc(sizeof (TP));
  p->topo = 0;
  p->n = 1;
  p->vet = (int *) malloc(sizeof(int) * p->n);
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
  free(p->vet);
  free(p);
}

void TP_push(TP *p, int x){
  if(p->topo == p->n){
    p->n *= 2;
    p->vet = realloc(p->vet, p->n * sizeof(int));
  }
  p->vet[p->topo++] = x;
}

void TP_imprime(TP *p){
  int i;
  for(i = p->topo - 1; i >= 0; i--)
    printf("%d -> %d\n", p->topo - i, p->vet[i]);
}

#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
  int topo, n;
  int *vet;
}TP;	


void TP_push(TP *p, int elem);
int TP_pop(TP *p);
int TP_vazia(TP *p);
TP *TP_inicializa(void);
void TP_libera(TP *p);
void TP_imprime(TP *p);

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


#include <limits.h>
#include "TF.h"

int menor(TF *f);

void ordena(TF *f){
  if(TF_vazia(f)) return;
  TF *aux = TF_inicializa();
  while(!TF_vazia(f))
    TF_insere(aux, TF_retira(f));
  while(!TF_vazia(aux)){
    int x = menor(aux);
    TF_insere(f, x);
  }
  TF_libera(aux);
}

int menor(TF *f){
  if(TF_vazia(f)) return INT_MAX;
  int resp = TF_retira(f), prox;
  TF *aux = TF_inicializa();
  while(!TF_vazia(f)){
    prox = TF_retira(f);
    if(resp > prox){
      TF_insere(aux, resp);
      resp = prox;
    }
    else TF_insere(aux, prox); 
  }
  while(!TF_vazia(aux))
    TF_insere(f, TF_retira(aux));
  TF_libera(aux);
  return resp;
}

int main(void){
  TF *f = TF_inicializa();
  printf("f:\n");
  int n;
  while(1){
    scanf("%d", &n);
    if(n < 0) break;
    TF_insere(f, n);
  }
  TF_retira(f);
  TF_retira(f);
  TF_insere(f, 300);
  TF_insere(f, 200);
  TF_insere(f, 100);
  TF_insere(f, 700);
  TF_insere(f, 900);
  TF_insere(f, 800);
  TF_insere(f, 500);
  TF_insere(f, 400);
  TF_imprime(f);
  printf("\n");
  ordena(f);
  TF_imprime(f);
  printf("\n");    
  TF_libera(f);
  return 0;
}

#include "TF.h"

TF *TF_inicializa (void){
  TF *f = (TF *) malloc(sizeof (TF));
  f->tam = 1;
  f->vet = (int *) malloc(sizeof(int) * f->tam);
  f->n = f->ini = 0;
  return f;
}

int incr (int ind, int n){
  return (ind + 1) % n;
}

int TF_vazia (TF *f){
  return f->n == 0;
}

int TF_retira (TF *f){
  if(TF_vazia(f)) exit(1);
  int resp = f->vet[f->ini];
  f->ini = incr(f->ini, f->tam);
  f->n--;
  return resp;
}

void TF_libera (TF *f){
  free(f->vet);
  free(f);
}

void TF_insere (TF *f, int x){
  if(f->n == f->tam){
    f->tam *= 2;
    f->vet = realloc(f->vet, f->tam * sizeof(int));
  }
  int fim = (f->ini + f->n++) % f->tam;
  f->vet[fim] = x;
}

void TF_imprime(TF *f){
  int ind = f->ini, i;
  for(i = 0; i < f->n; i++){
    printf("%d -> %d\n", i + 1, f->vet[ind]);
    ind = incr(ind, f->tam);
  }
}

#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
  int n, ini, tam;
  int *vet;
}TF;

void TF_insere(TF *f, int elem);
int TF_vazia(TF *f);
void TF_libera(TF *f);
TF *TF_inicializa(void);
int TF_retira(TF *f);
void TF_imprime(TF *f);

#include <stdio.h>
#include <stdlib.h>

#define MAX_TAM 100

typedef struct fila{
  int n, ini;
  int vet[MAX_TAM];
}TF;

void TF_insere(TF *f, int elem);
int TF_vazia(TF *f);
void TF_libera(TF *f);
TF *TF_inicializa(void);
int TF_retira(TF *f);
void TF_imprime(TF *f);

#include "TF.h"

TF *TF_inicializa (void){
  TF *f = (TF *) malloc(sizeof (TF));
  f->n = f->ini = 0;
  return f;
}

int incr (int ind, int n){
  return (ind + 1) % n;
}

int TF_vazia (TF *f){
  return f->n == 0;
}

int TF_retira (TF *f){
  if(TF_vazia(f)) exit(1);
  int resp = f->vet[f->ini];
  f->ini = incr(f->ini, MAX_TAM);
  f->n--;
  return resp;
}

void TF_libera (TF *f){
  free(f);
}

void TF_insere (TF *f, int x){
  if(f->n == MAX_TAM) exit(1);
  int fim = (f->ini + f->n++) % MAX_TAM;
  f->vet[fim] = x;
}

void TF_imprime(TF *f){
  int ind = f->ini, i;
  for(i = 0; i < f->n; i++){
    printf("%d -> %d\n", i + 1, f->vet[ind]);
    ind = incr(ind, MAX_TAM);
  }
}