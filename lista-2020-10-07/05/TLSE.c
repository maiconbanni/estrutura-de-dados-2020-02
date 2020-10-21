#include "./TLSE.h"
#include "string.h"
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

TLSE* TLSE_retira_rec(TLSE *l, int elem){
  if(!l) return l;
  if(l->info == elem){
    TLSE *p = l;
    l = l->prox;
    free(p);
  }
  else l->prox = TLSE_retira_rec(l->prox, elem);
  return l;
}

TLSE* TLSE_busca(TLSE *l, int elem){
  TLSE *p = l;
  while((p) && (p->info != elem)) p = p->prox; 
  return p;
}

TLSE* TLSE_busca_rec(TLSE *l, int elem){
  if((!l) || (l->info == elem)) return l;
  return TLSE_busca_rec(l->prox, elem);
}

/* Minhas Funções */

// void inverte_l(TLSE *l){
//     TLSE *anterior = NULL;
//     TLSE *proximo = NULL;
//     TLSE *atual = l;
//     while (atual != NULL) {
//       proximo = atual->prox;
//       atual->prox = anterior;
//       anterior = atual;
//       atual = proximo;
//     }
//     l = anterior;
//  }

void inverte_l(TLSE *l){
    TLSE* lista = l;
    int qtd = 0;

    while(lista) {
      qtd++;
      lista = lista->prox;
    }

    lista = l; // retornando o ponteiro para o Inicio da Lista
    int valores[qtd];
    for( int i = qtd -1; i >= 0; i--) {
      valores[i] = lista->info;
      lista = lista->prox;
    }

    lista = l; // retornando o ponteiro para o Inicio da Lista
    for (int i = 0;  i < qtd; i++) {
      lista->info = valores[i];
      lista = lista->prox;
    }
    l = lista;
}

TLSE* inverte_nl(TLSE *l){
  TLSE *li = NULL;
  while (l) {
    li = TLSE_insere(li, l->info);
    l = l->prox;
  }
  return li;
}

TLSE* desloca(TLSE* l, int n) {
  TLSE* lista = NULL;
  TLSE* auxiliar = NULL;
  int info = 0;
  
  // deslocamento impar para direita
  if (n%2 == 0) {
    lista = l->prox;
    info = l->info;
    while(lista) {
      auxiliar = TLSE_insere(auxiliar, lista->info);
      lista = lista->prox;
    }
    lista = NULL;
    lista = TLSE_insere(lista, info);
    while(auxiliar) {
      lista = TLSE_insere(lista, auxiliar->info);
      auxiliar = auxiliar->prox;
    }
  } else { // deslocamento par para esquerda
    lista = l;
    while(lista) {
      if(lista->prox != NULL ) {
        auxiliar = TLSE_insere(auxiliar, lista->info);
      } else {
        info = lista->info;
      }
      lista = lista->prox;
    }
    lista = NULL;
    while(auxiliar) {
      lista = TLSE_insere(lista, auxiliar->info);
      auxiliar = auxiliar->prox;
    }
    lista = TLSE_insere(lista, info);
  }
  return lista;
}

TAluno* insere_aluno(TAluno* l, int mat, float cr) {
  TAluno* novo = (TAluno*) malloc(sizeof(TAluno));
  novo->mat = mat;
  novo->cr  = cr;
  novo->prox = l;
  return novo;
}

TAluno* copia(TAluno* l) {
  TAluno *c = NULL;
  TAluno *auxiliar = l;
  if(auxiliar) {
    c = copia(auxiliar->prox);
    c = insere_aluno(c, auxiliar->mat, auxiliar->cr);
  }
  return c;
}

void imprime_aluno(TAluno *l){
  TAluno *p = l;
  while(p){
    printf("mat[%d] e cr[%f] \n", p->mat, p->cr);
    p = p->prox;
  } 
}

TLSE* rto (TLSE* l, int elem) {
  TLSE *c = NULL;
  TLSE *auxiliar = l;
  if(auxiliar) {
    c = rto(auxiliar->prox, elem);
    if(auxiliar->info != elem) c = TLSE_insere(c, auxiliar->info);
  } else {
    TLSE_libera(l);
  }
  return c;
}