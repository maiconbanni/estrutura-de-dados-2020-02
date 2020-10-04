/*
    Q4) Refaça o exemplo feito em aula para usar no lugar de TCAND vet[n]:
        TCAND *vet[n]
        TCAND **vet
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct candidato{
  int num_insc;
  float nota;
} TCAND;

int cmp(const void *x, const void *y);

int main(void){
  int n;
  scanf("%d", &n);
  if(n > 0) {
    TCAND *vet[n];
    int i;
    for(i = 0; i < n; i++) vet[i] = (TCAND*) malloc(sizeof(TCAND));
    for(i = 0; i < n; i++) scanf("%d%f", &vet[i]->num_insc, &vet[i]->nota);
    for(i = 0; i < n; i++) printf("%d: %f\n", vet[i]->num_insc, vet[i]->nota);
    printf("Depois da ordenacao...\n");
    qsort(vet, n, sizeof(TCAND), cmp);
    for(i = 0; i < n; i++) printf("%d: %f\n", vet[i]->num_insc, vet[i]->nota);
    for(i = 0; i < n; i++) free(vet[i]);
  }
  return 0; 
}

int cmp(const void *x, const void *y){
  TCAND **px = (TCAND **) x, **py = (TCAND **) y;
  if(px[0]->nota > py[0]->nota) return -1;
  if(px[0]->nota < py[0]->nota) return 1;
  if(px[0]->num_insc < py[0]-> num_insc) return -1;
  return 1;
}