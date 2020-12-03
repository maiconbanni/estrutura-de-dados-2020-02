#include "TAB.h"

void TAB_libera(TAB* t){
  if(t){
    TAB_libera(t->esq);
    TAB_libera(t->dir);
    free(t);
  }
}

TAB* TAB_busca(TAB* t, int e){
  if((!t) || (t->info == e)) return t;
  TAB *resp = TAB_busca(t->esq, e);
  if(resp) return resp;
  return TAB_busca(t->dir, e);
}

void imprime_aux(TAB* a, int andar){
  if(a){
    int j;
    imprime_aux(a->esq, andar + 1);
    for(j = 0; j <= andar; j++) printf("\t");
    printf("%d\n", a->info);
    imprime_aux(a->dir, andar + 1);
  }
}

void TAB_imprime(TAB* a){
  imprime_aux(a, 1);
}

TAB* TAB_cria(int x, TAB* e, TAB* d){
  TAB* a = (TAB*) malloc(sizeof(TAB));
  a->info = x;
  a->esq = e;
  a->dir = d;
  return a;
}

TAB* TAB_insere(TAB* t, int x) {
  if (!t) return TAB_cria(x, NULL, NULL);
  if (t->info > x) t->esq = TAB_insere(t->esq, x);
  if (t->info < x) t->dir = TAB_insere(t->dir, x);
  return t;
}

TAB* TAB_retira(TAB *t, int e){
  if(!t) return t;
  else if(e < t->info) t->esq = TAB_retira(t->esq, e);
  else if(e > t->info) t->dir = TAB_retira(t->dir, e);
  else{
    if((!t->esq) && (!t->dir)){
      free(t);
      t = NULL;
    }
    else if((!t->esq) || (!t->dir)){
      TAB *q = t;
      if(!t->dir) t = t->esq;
      else t = t->dir;
      free(q); 
    }
    else{
      TAB *f = t->esq;
      while(f->dir) f = f->dir;
      t->info = f->info;
      f->info = e;
      t->esq = TAB_retira(t->esq, e);
    }
  }
  return t;  
}

// Profundidade
void TAB_imprime_preorder(TAB* p) {
  if (p != NULL) {
    printf("%d ",p->info);
    TAB_imprime_preorder(p->esq);
    TAB_imprime_preorder(p->dir);
  }
}

// Simetrica
void TAB_imprime_inorder(TAB* p) {
  if (p != NULL) {
    int i = 0;
    TAB_imprime_inorder(p->esq);
    printf("%d ",p->info);
    TAB_imprime_inorder(p->dir);
  }
}

// Pós ordem
void TAB_imprime_postorder(TAB* p) {
  if (p != NULL) {
    TAB_imprime_postorder(p->esq);
    TAB_imprime_postorder(p->dir);
    printf("%d ",p->info);
  }
}

TAB* copia(TAB* t) {
  if (t) {
    TAB* aux = TAB_cria(t->info, NULL, NULL);
    aux->esq = copia(t->esq);
    aux->dir = copia(t->dir);
    return aux;
  } else {
    return NULL;
  }
}

TAB* espelho (TAB *t) {
  if (t) {
    TAB* aux = TAB_cria(t->info, NULL, NULL);
    aux->esq = espelho(t->dir);
    aux->dir = espelho(t->esq);
    return aux;
  } else {
    return NULL;
  }
}

TAB* maior (TAB *t) {
  if (!t || !t->dir) return t;
  return maior(t->dir);
}

TAB* menor (TAB *t) {
  if (!t || !t->esq) return t;
  return menor(t->esq);
}

int igual(TAB* a1, TAB* a2) {
  if (!a1 && !a2) return 1; // Ambas as arvores estão vazias  
  if (!a1 || !a2) return 0; // Apenas uma delas está vazia
  if (a1->info == a2->info) 
    return igual (a1->esq, a2->esq) && igual(a1->dir, a2->dir);
  return 0;
}

TAB* retira_pares (TAB* t) {
  if (!t) return NULL;
  if (t->esq) t->esq = retira_pares(t->esq);
  if (t->dir) t->dir = retira_pares(t->dir);
  if (t->info % 2 == 0) t = TAB_retira(t,t->info);
  return t;
}

TAB* retira_impares (TAB* t) {
  if (!t) return NULL;
  if (t->esq) t->esq = retira_impares(t->esq);
  if (t->dir) t->dir = retira_impares(t->dir);
  if (t->info % 2 != 0) t = TAB_retira(t,t->info);
  return t;
}

// Esta função devolve a altura da árvore 
// binária cuja raiz é r.
int altura(TAB* t) {
  if (!t) return -1;
  else {
    int le, ld;
    le = altura(t->esq);
    ld = altura(t->dir);
    if (le > ld) return le + 1;
    return ld + 1;
  }
}

// Profundidade
int count (TAB* p) {
  if (p != NULL) return count(p->esq) + count(p->dir) + 1;
  else return 0;
}

void TAB_imprime_largura(TAB* t){
  TAB *aux, *arvore[count(t)];
  int inicio = 0, fim = 1;
  arvore[0] = t;

  while(inicio < fim){
    aux = arvore[inicio++];
    printf("%d-%d ", aux->cor, aux->info );
    if(aux->esq != NULL){
      arvore[fim] = aux->esq;
      fim++;
    }
    if(aux->dir != NULL){
      arvore[fim] = aux->dir;
      fim++;
    }
  }
}

// Nós Folha são os nós que não possuem filho
int nf(TAB *t) {
  if (!t) return 0;
  if (!t->esq && !t->dir) return 1;
  return nf(t->esq) + nf(t->dir);
}

// Nós Internos são os nós que possuem algum filho
int ni(TAB *t) {
  if (!t) return 0;
  if (!t->esq && !t->dir) return 0;
  return ni(t->esq) + ni(t->dir) + 1;
}

TAB* colore (TAB* raiz) {
  if (!raiz) return NULL;
  // Marca as folhas com 1
  if (!raiz->esq && !raiz->dir) {
    raiz->cor = 1;
    return NULL;
  }

  colore(raiz->esq);
  colore(raiz->dir);

  if (raiz->esq || raiz->dir) {
    int cor = 1;
    if (raiz->esq) cor = !raiz->esq->cor;
    else if (raiz->dir) cor = !raiz->dir->cor;
    // inverte a cor do pai em relação ao filho
    raiz->cor = cor;
  }
  return raiz;
}

int mesmos_nos(TAB* a1, TAB* a2) {
  if (!a1 && !a2) return 1; // Ambas as arvores estão vazias  
  if (!a1 || !a2) return 0; // Apenas uma delas está vazia
  if (count(a1) == count(a2)) 
    return mesmos_nos (a1->esq, a2->esq) && mesmos_nos(a1->dir, a2->dir);
  return 0;
}

// Verificar se os nós dessa árvore possuem ou zero ou dois filhos
int estbin(TAB *a){
  return (!a->dir && !a->esq) || (a->dir && a->esq && estbin(a->esq) && estbin(a->dir));
}

int estritamente_bin(TAB* a){
  if(!a->dir && !a->esq) return 1;
  if(a->dir && a->esq)   return estritamente_bin(a->esq) && estritamente_bin(a->dir);
  return 0;
}

int zigzag (TAB *a){
  if (!a) return 1;
  int tamanho_esquerda = count(a->esq);
  int tamanho_direita  = count(a->dir);
  if(tamanho_esquerda > 1 && tamanho_direita > 1) return 0;
  if(tamanho_esquerda > 1 && tamanho_direita == 1) return zigzag(a->esq);
  if(tamanho_esquerda == 1 && tamanho_direita > 1) return zigzag(a->dir);
  return 1;
}

void imprime_folhas(TAB* a){
  if (!a) return;
  else {
    if(a->esq == NULL && a->dir == NULL) {
    printf("%d\t", a->info);
    return;
    }
  }
  imprime_folhas(a->esq);
  imprime_folhas(a->dir);
}

int soma_nos (TAB* p){
  int cont = 0;
  if(p){
    return cont = p->info + soma_nos(p->esq) + soma_nos(p->dir);
  } else {
    return cont;
  }
}

void imprime_nivel (TAB* a, int nivel, int valor){
  if (!a) return;
  imprime_nivel(a->esq, nivel+1, valor);
  if(nivel == valor) printf("%d\t",a->info);
  imprime_nivel(a->dir, nivel+1, valor);
}

TAB *v2abb(int *v, int n){
  if(n <= 0) return NULL;
  return TAB_cria(v[n/2], v2abb(v, n/2), v2abb (&v[n/2 + 1], n - n/2 - 1));
}

/* Função que verifica se um elemento pertence ou não à árvore */
int existInTree(TAB* t, int info) {
  if(!t) return 0;
  return t->info == info || existInTree(t->esq, info) || existInTree(t->dir, info);
}

TAB* inserir_invertido(TAB* t, int x) {
  if (!t) return TAB_cria(x, NULL, NULL);
  if (t->info < x) t->esq = TAB_insere(t->esq, x);
  if (t->info > x) t->dir = TAB_insere(t->dir, x);
  return t;
}

TAB* buscaSetPai (TAB* raiz, int info, TAB **pai) {
	TAB *no = NULL;
	if(raiz == NULL) *pai = NULL;
	else {
		if( raiz->info == info) no = raiz;
		else {
			*pai = raiz;
			if( raiz->info > info) no = buscaSetPai(raiz->esq, info, pai);
			else no = buscaSetPai(raiz->dir, info, pai);
		}
	}
	return no;
}

// ######################################################################################################################
// Refazer tudo para ABB
// 10. Escreva uma função em C para testar se uma árvore é zigue-zague, isto é, se todos os nós internos possuem exatamente uma sub-árvore vazia: int zz(TAB *a);
// retornar todos os ancestrais de um nó na árvore de busca binária, da raiz da árvore até o elemento passado como parâmetro, usando a biblioteca de lista encadeada - TLSE* ancestrais(TABB *a, int elem); 