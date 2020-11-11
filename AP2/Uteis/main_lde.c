#include "TLDE.h"

void ordena(TLDE *l);
TLDE *axd(TLDE *l, int x);

int main(void){
  TLDE *l = NULL;
  int x;
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l = TLDE_insere_inicio(l, x);
  }while(1);
  TLDE_imprime(l);
  printf("\n");
  
  scanf("%d", &x);
  TLDE_ordena(l);
  TLDE_imprime(l);
  printf("\n");

  TLDE_libera(l);
  return 0;
}

TLDE *axd(TLDE *l, int x){
  TLDE *p = TLDE_busca(l, x);
  while(p){
    TLDE *novo = TLDE_insere_inicio(NULL, x - 1);
    if(p->ant) p->ant->prox = novo;
    else l = novo;
    novo->ant = p->ant;
    novo->prox = p;
    p->ant = novo;

    novo = TLDE_insere_inicio(NULL, x + 1);
    if(p->prox) p->prox->ant = novo;
    novo->ant = p;
    novo->prox = p->prox;
    p->prox = novo;          
    p = TLDE_busca(p->prox, x);
  }
  return l;
}
 
void ordena(TLDE *l){
  TLDE *p;
  int i = 0;
  for(p = l; p; p = p->prox){
    TLDE *menor = p, *q;
    for(q = p->prox; q; q = q->prox)
      if(menor->info > q->info) menor = q;
            
    if(menor != p){
      int temp = p->info;
      p->info = menor->info;
      menor->info = temp;
    }
    printf("iteracao %d: ", (++i));
    TLDE_imprime(l);
    printf("\n");   
  }
}