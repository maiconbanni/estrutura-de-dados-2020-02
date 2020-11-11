#include "./TLSE.h"

TLSE* TLSE_insere_inicio(TLSE *l, int elem){
  TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
  novo->prox = l;
  novo->info = elem;
  return novo;
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

TLSE* TLSE_insere_ordenado(TLSE *l, int elem){
  TLSE *p = l, *ant = NULL;
  TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
  novo->info = elem;
  while(p && p->info < elem) {
    ant = p;
    p = p->prox;
  }
  // Se anterior esta nulo, esta entrando no inicio da lista
  if(!ant) { // ant == NULL
    novo->prox = l;
    l = novo;
  } else {
    novo->prox = ant->prox;
    ant->prox = novo;
  }
  return l;
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

void TLSE_retira_duplicados(TLSE *l, int elem){
  TLSE *ptr = l, *q_ptr, *q_prev, *dummy;
  while(ptr){
    q_prev = ptr;
    q_ptr = ptr->prox;
    while(q_ptr){
      if (q_ptr->info==ptr->info){
        dummy = q_ptr;
        q_prev->prox = q_ptr->prox;
        q_ptr = q_ptr->prox;
        free(dummy);
      } else {
        q_prev = q_ptr;
        q_ptr = q_ptr->prox;
      }
    }
    ptr = ptr->prox;
  }
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

void* inverte(TLSE *l){
    TLSE *anterior = NULL;
    TLSE *proximo = NULL;
    TLSE *atual = l;
    while (atual != NULL) {
      proximo = atual->prox;
      atual->prox = anterior;
      anterior = atual;
      atual = proximo;
    }
    l = anterior;
    return l;
 }

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
    li = TLSE_insere_inicio(li, l->info);
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
      auxiliar = TLSE_insere_inicio(auxiliar, lista->info);
      lista = lista->prox;
    }
    lista = NULL;
    lista = TLSE_insere_inicio(lista, info);
    while(auxiliar) {
      lista = TLSE_insere_inicio(lista, auxiliar->info);
      auxiliar = auxiliar->prox;
    }
  } else { // deslocamento par para esquerda
    lista = l;
    while(lista) {
      if(lista->prox != NULL ) {
        auxiliar = TLSE_insere_inicio(auxiliar, lista->info);
      } else {
        info = lista->info;
      }
      lista = lista->prox;
    }
    lista = NULL;
    while(auxiliar) {
      lista = TLSE_insere_inicio(lista, auxiliar->info);
      auxiliar = auxiliar->prox;
    }
    lista = TLSE_insere_inicio(lista, info);
  }
  return lista;
}


TLSE* copia(TLSE* l) {
  TLSE *c = NULL;
  TLSE *auxiliar = l;
  if(auxiliar) {
    c = copia(auxiliar->prox);
    c = TLSE_insere_inicio(c, auxiliar->info);
  }
  return c;
}

TLSE* rto (TLSE* l, int elem) {
  TLSE *c = NULL;
  TLSE *auxiliar = l;
  if(auxiliar) {
    c = rto(auxiliar->prox, elem);
    if(auxiliar->info != elem) c = TLSE_insere_inicio(c, auxiliar->info);
  } else {
    TLSE_libera(l);
  }
  return c;
}

TLSE* i_p ( TLSE *l) {
  TLSE *auxiliar = l;
  TLSE *impar = NULL;
  TLSE *par = NULL;

  while(auxiliar) {
    if(auxiliar->info % 2 != 0)
      impar = TLSE_insere_inicio(impar, auxiliar->info);
    auxiliar = auxiliar->prox;
  }

  auxiliar = l;
  while(auxiliar) {
    if(auxiliar->info % 2 == 0)
      par = TLSE_insere_inicio(par, auxiliar->info);
    auxiliar = auxiliar->prox;
  }

  while(par) {
    auxiliar = TLSE_insere_inicio(auxiliar, par->info);
    par = par->prox;
  }

  while(impar){
    auxiliar = TLSE_insere_inicio(auxiliar, impar->info);
    impar = impar->prox;
  }

  TLSE_libera(impar);
  TLSE_libera(par);

  return auxiliar;
}

void* i_pv ( TLSE *l) {
  TLSE *auxiliar = l;
  TLSE *impar = NULL;
  TLSE *par = NULL;

  while(auxiliar) {
    if(auxiliar->info % 2 != 0)
      impar = TLSE_insere_inicio(impar, auxiliar->info);
    auxiliar = auxiliar->prox;
  }

  auxiliar = l;
  while(auxiliar) {
    if(auxiliar->info % 2 == 0)
      par = TLSE_insere_inicio(par, auxiliar->info);
    auxiliar = auxiliar->prox;
  }

  while(par) {
    auxiliar = TLSE_insere_inicio(auxiliar, par->info);
    par = par->prox;
  }

  while(impar){
    auxiliar = TLSE_insere_inicio(auxiliar, impar->info);
    impar = impar->prox;
  }

  TLSE_libera(impar);
  TLSE_libera(par);

  return auxiliar;
}

int igual (TLSE *l1, TLSE *l2) {
  int qtd_l1 = 0, qtd_l2 = 0;
  TLSE *a1 = NULL;
  TLSE *a2 = NULL;
  a1 = l1;
  a2 = l2;

  while(a1) { qtd_l1++; a1 = a1->prox; }
  while(a2) { qtd_l2++; a2 = a2->prox; }

  if(qtd_l1 != qtd_l2) return 0; // Listas de Tamanhos diferentes

  a1 = l1;
  a2 = l2;
  while(a1) {
    if(a1->info != a2->info){
      return 0; // Listas com algum valor diferente
    }
    a1 = a1->prox;
    a2 = a2->prox;
  }

  return 1;
}

TLSE* union_all (TLSE* l1, TLSE* l2) {
  TLSE* auxiliar = NULL;
  while(l1) {
    auxiliar = TLSE_insere_fim(auxiliar, l1->info);
    l1 = l1->prox;
  }
  while(l2) {
    auxiliar = TLSE_insere_fim(auxiliar, l2->info);
    l2 = l2->prox;
  }
  return auxiliar;
}

TLSE* junta_listas (TLSE* l1, TLSE* l2) {
  TLSE* auxiliar = NULL;
  while(l1) {
    auxiliar = TLSE_insere_inicio(auxiliar, l1->info);
    l1 = l1->prox;
  }
  while(l2) {
    auxiliar = TLSE_insere_inicio(auxiliar, l2->info);
    l2 = l2->prox;
  }
  return inverte_nl(auxiliar);
}

int contrario (TLSE *l1, TLSE *l2) {
  int qtd_l1 = 0, qtd_l2 = 0;
  TLSE *a1 = NULL;
  TLSE *a2 = NULL;
  a1 = l1;
  a2 = l2;

  while(a1) { qtd_l1++; a1 = a1->prox; }
  while(a2) { qtd_l2++; a2 = a2->prox; }

  if(qtd_l1 != qtd_l2) return 0; // Listas de Tamanhos diferentes

  a1 = l1;
  a2 = NULL;

  while(l2) {
    a2 = TLSE_insere_inicio(a2, l2->info);
    l2 = l2->prox;
  }

  while(a1) {
    if(a1->info != a2->info){
      return 0; // Listas com algum valor diferente
    }
    a1 = a1->prox;
    a2 = a2->prox;
  }

  return 1;
}

TLSE * ordena (TLSE* l){
  if(!l || !l->prox) return l; // lista vazia ou com apenas um elemento
  TLSE *novaLista=NULL, *principal, *aux;
  int elem;

  for(principal = l; principal; principal = principal->prox) {
    for(aux = principal->prox; aux; aux = aux->prox) {
      if(principal->info < aux->info){
        elem     = principal->info;
        principal->info = aux->info;
        aux->info = elem;
      }
    }
    novaLista = TLSE_insere_inicio(novaLista, principal->info);
  }
  return novaLista;
}

void misc (TLSE *l, int x) {
  TLSE *p = l;
  while(p){
    if(p->info == x) {
      p->info = x - 1;
      TLSE *q = p->prox;
      p->prox = TLSE_insere_inicio(p->prox, x + 1);
      p->prox = TLSE_insere_inicio(p->prox, x);
      p = q;
    } else {
      p = p->prox;
    }
  }
}