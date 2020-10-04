#include <stdio.h>
#include <stdlib.h>

typedef struct data{
    int mes, ano;
} TD;

typedef struct prod{
    int cod;
    float peso, preco;
    TD *valid;
} TPROD;

void ordena1 (TPROD **prat, int n);
int cmp(const void *x, const void *y);

int main(){
    int n;
    scanf("%d", &n);
    if(n <= 0) return 0;
    TPROD *vet[n];
    int i;

    for(i = 0; i < n; i++) {
        vet[i] = (TPROD *) malloc(sizeof(TPROD *));
        vet[i]->valid = (TD *) malloc(sizeof(TD));
    }

    for(i = 0; i < n; i++){
        scanf("%d%f%f%d%d", &vet[i]->cod, &vet[i]->peso, &vet[i]->preco, &vet[i]->valid[0].mes, &vet[i]->valid[0].ano);
    }

    ordena1(vet, n);
    for(i = 0; i < n; i++) {
        printf("cod = %d, peso = %f, preco = %f, mes = %d, ano = %d\n", vet[i]->cod, vet[i]->peso, vet[i]->preco, vet[i]->valid[0].mes, vet[i]->valid[0].ano);
    }

    for(i = 0; i < n; i++) {
        free(vet[i]->valid);
        free(vet[i]);
    }

  return 0; 
}

int cmp(const void *x, const void *y) {
  TPROD **px = (TPROD **) x, **py = (TPROD **) y;

  if(px[0]->cod > py[0]->cod) return 1;
  if(px[0]->cod < py[0]->cod) return -1;

  if(px[0]->valid->ano < py[0]->valid->ano) return -1;
  if(px[0]->valid->ano < py[0]->valid->ano) return 1;

  if(px[0]->preco < py[0]->preco) return 1;
  if(px[0]->preco > py[0]->preco) return -1;

  return 1;
}

void ordena1 (TPROD **prat, int n) {
    qsort(prat, n, sizeof(TPROD**), cmp);
}