#include <stdio.h>
#include <stdlib.h>

typedef struct lc{
  int info;
  struct lc *prox;
} TLC;

TLC* TLC_insere(TLC *l, int info){
  TLC* novo = (TLC*) malloc (sizeof(TLC));
  novo->info = info;
  if(!l){
    novo->prox = novo;
    return novo;
  }
  TLC *p = l->prox, *ant = l;
  while(p != l){
    ant = p;
    p = p->prox;
  }
  novo->prox = l;
  ant->prox = novo;
  return l;
}

TLC* TLC_retira(TLC *l, int info){
  if((!l) || ((l->prox == l) && (l->info == info))){
    if(l) free(l);
    return NULL;
  }

  TLC *p = l->prox, *ant = l;
  if(l->info == info){
    while(p != l){
      ant = p;
      p = p->prox;
    }
  }
  
  while((p != l) && (p->info != info)){
    ant = p;
    p = p->prox;
  }
  
  if((p == l) && (p->info != info)) return l;
  ant->prox = p->prox;
  if(p == l) l = l->prox;
  free(p);
  return l;
}
 
void TLC_imprime(TLC *l){
  if(l){
    printf("%d ", l->info);
    TLC *p = l->prox;
    while(p != l){
      printf("%d ", p->info);
      p = p->prox;
    }
    printf("\n");
  }
}

void TLC_libera(TLC *l){
  if(l){
    TLC *p = l->prox;
    while(p != l){
      TLC *temp = p;
      p = p->prox;
      free(temp);
    }
    free(l);
  }
}


TLC *meio(TLC *l, int *pos){
  if(l == NULL){
    (*pos) = -1;
    return NULL;
  }
  // So tem um elemento
  if(l == l->prox){
    (*pos) = 1;
    return l;
  } 
  
  TLC *proximo = l->prox, *meio = l;
  int resp = 1;

  while(proximo != l && proximo->prox != l){
    meio = meio->prox;
    proximo = proximo->prox->prox;
    resp++;
  }
  (*pos) = resp;
  return meio;
}

int main(void){
  TLC *l = NULL;
  int n;
  do{
    scanf("%d", &n);
    if(n < 0) break;
    l = TLC_insere(l, n);
  }while(1);

  int pos;
  TLC *resp = meio(l, &pos);
  if(resp) 
    printf("O elemento do meio da lista (info: %d) esta na pos %d\n", resp->info, pos); 
  
  TLC_libera(l);
  return 0;
}
