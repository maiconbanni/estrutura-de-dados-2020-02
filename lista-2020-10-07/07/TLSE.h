#include <stdio.h>
#include <stdlib.h>

typedef struct lse {
  int info;
  struct lse *prox;
} TLSE;

typedef struct aluno {
  int mat;
  float cr;
  struct aluno *prox;
} TAluno;

TLSE* TLSE_insere(TLSE *l, int elem);
void TLSE_imprime(TLSE *l);
void TLSE_libera(TLSE *l);
TLSE* TLSE_retira(TLSE *l, int elem);
TLSE* TLSE_busca(TLSE *l, int elem);

void TLSE_imp_rec(TLSE *l);
void TLSE_imp_rec_rev(TLSE *l);
void TLSE_lib_rec(TLSE *l);
TLSE* TLSE_busca_rec(TLSE *l, int elem);
TLSE* TLSE_retira_rec(TLSE *l, int elem);

/* Minhas Funçõs */
void inverte_l(TLSE *l);
TLSE* inverte_nl(TLSE *l);
TLSE* desloca(TLSE* l, int n);
TAluno * copia (TAluno *l);
TAluno* insere_aluno(TAluno* l, int mat, float cr);
void imprime_aluno(TAluno *l);
TLSE* rto(TLSE* l, int elem);
TLSE* i_p ( TLSE *l);
void* i_pv ( TLSE *l);
