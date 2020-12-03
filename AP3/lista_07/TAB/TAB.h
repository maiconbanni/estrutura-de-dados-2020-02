#include <stdio.h>
#include <stdlib.h>

typedef struct ab {
    int info;
    int cor;
    struct ab *esq, *dir;
} TAB;

TAB* TAB_cria(int x, TAB* e, TAB* d);
void TAB_imprime(TAB *t);
void TAB_libera(TAB* t);
TAB* TAB_busca(TAB* t, int e);
TAB* TAB_insere(TAB* t, int x);
TAB* TAB_retira(TAB *t, int e);

TAB* retira_pares (TAB* arv);
TAB* retira_impares (TAB* arv);
void TAB_imprime_preorder(TAB* t);
void TAB_imprime_inorder(TAB* t);
void TAB_imprime_postorder(TAB* t);
void TAB_imprime_largura(TAB* t);

TAB* findParent  (TAB* t, int val);
TAB* copia  (TAB* t);
TAB* espelho(TAB* t);
TAB* maior  (TAB *t);
TAB* menor  (TAB *t);
int igual   (TAB* a1, TAB* a2);
int mesmos_nos   (TAB* a1, TAB* a2);
int altura  (TAB* t);
int count  (TAB* t);
int nf(TAB *t);
int ni(TAB *t);
TAB* colore (TAB* raiz);
int estbin(TAB *a);
int estritamente_bin(TAB *a);
int zigzag (TAB *a);
void imprime_folhas(TAB* a);
int soma_nos (TAB* p);
void imprime_nivel (TAB* a, int nivel, int valor);
TAB *v2abb(int *v, int n);
int existInTree(TAB* t, int info);
TAB* inserir_invertido(TAB* t, int x);
TAB* buscaSetPai (TAB* raiz, int info, TAB **pai);
