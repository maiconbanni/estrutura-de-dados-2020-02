#include <stdio.h>
#include <stdlib.h>

typedef struct lse {
  int info;
  struct lse *prox;
} TLSE;

TLSE* TLSE_insere_inicio(TLSE *l, int elem);
TLSE* TLSE_insere_fim(TLSE *l, int elem);
TLSE* TLSE_insere_ordenado(TLSE *l, int elem);
TLSE* TLSE_busca(TLSE *l, int elem);
TLSE* TLSE_busca_rec(TLSE *l, int elem);
TLSE* TLSE_retira(TLSE *l, int elem);
TLSE* TLSE_retira_rec(TLSE *l, int elem);

void TLSE_imprime(TLSE *l);
void TLSE_libera(TLSE *l);
void TLSE_imp_rec(TLSE *l);
void TLSE_imp_rec_rev(TLSE *l);
void TLSE_lib_rec(TLSE *l);

/* Funções adicionais */
TLSE* inverte_nl(TLSE *l);
TLSE* desloca(TLSE* l, int n);
TLSE* copia (TLSE *l);
TLSE* rto(TLSE* l, int elem);
TLSE* i_p ( TLSE *l);
TLSE* junta_listas (TLSE* l1, TLSE* l2);
TLSE* TLSE_ordena(TLSE* l);
TLSE* union_all (TLSE* l1, TLSE* l2);
void* i_pv ( TLSE *l);
void* inverte(TLSE *l);
void  inverte_l(TLSE *l);
int   igual (TLSE *l1, TLSE *l2);
int   contrario (TLSE *l1, TLSE *l2);
void TLSE_retira_duplicados(TLSE *l, int elem);
void misc (TLSE *l, int x);