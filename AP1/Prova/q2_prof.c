#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int info, prox;
}TNO;

typedef struct lista{
  int tam, ini, fim; 
  TNO **vet;
}TLSEV;

TLSEV* TLSEV_cria(int n){
  TLSEV *l = (TLSEV *) malloc(sizeof(TLSEV));
  l->tam = n;
  l->ini = l->fim = -1;
  l->vet = (TNO**) malloc(sizeof(TNO*) * n);
  int i;
  for(i = 0; i < n; i++) l->vet[i] = NULL;
  return l; 
}

void TLSEV_insere(TLSEV *l, int elem){
  int i;
  for(i = 0; i < l->tam; i++)
    if(!l->vet[i]) break;
  if(i == l->tam) return;
  l->vet[i] = (TNO*) malloc(sizeof(TNO*));
  l->vet[i]->info = elem;
  l->vet[i]->prox = -1;
  if(l->ini == -1) l->ini = i;
  else l->vet[l->fim]->prox = i;
  l->fim = i;
}

void TLSEV_imprime(TLSEV *l){
  int i = l->ini;
  while(i != -1){
    printf("info[%d] = %d\tprox = %d\n", i, l->vet[i]->info, l->vet[i]->prox);
    i = l->vet[i]->prox;
  }
}

void TLSEV_libera(TLSEV *l){
  int j, i = l->ini;
  while(i != -1){
    j = i;
    i = l->vet[i]->prox;
    free(l->vet[j]);
  }
  free(l->vet);
  free(l);
}

void TLSEV_retira(TLSEV *l, int elem){
  int ant = -1, p = l->ini;
  while((p != -1) && (l->vet[p]->info != elem)){
    ant = p;
    p = l->vet[p]->prox;
  }
  if(p == -1) return;
  if(ant == -1){
    l->ini = l->vet[p]->prox;
    if(l->ini == -1) l->fim = -1;
  }
  else l->vet[ant]->prox = l->vet[p]->prox;
  free(l->vet[p]);
  l->vet[p] = NULL;
}

TNO* meio(TLSEV *l, int *pos){
  if(l->ini == -1){
    (*pos) = -1;
    return NULL;
  }
  int p = l->ini, resp = -1;
  while(p != -1){
    if(p == l->ini) resp = l->ini;
    else resp = l->vet[resp]->prox;
    p = l->vet[p]->prox;
    if(p != -1) p = l->vet[p]->prox;
  }
  (*pos) = resp;
  return l->vet[resp];
}

int main(void){
  int n, x;
  scanf("%d", &n);
  if(n <= 0) return 0;
  TLSEV *l = TLSEV_cria(n);
  do{
    scanf("%d", &x);
    if(x < 0) break;
    TLSEV_insere(l, x);
  }while(1);

  int pos;
  TNO *resp = meio(l, &pos);
  if(resp) printf("O elemento do meio da lista (info: %d e prox: %d) esta na pos %d\n", resp->info, resp->prox, pos); 
    
  TLSEV_libera(l);
  return 0;
}