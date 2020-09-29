#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct candidato{
  int mat;
  float nota;
  char data_nasc[11];
}TC;

int cmp(const void *x, const void *y);
void ordena(TC **vet, int n);
char *dateToString(char * data);

int main(void){
  int n;
  scanf("%d", &n);
  if(n > 0){
    TC *vet[n];
    int i;
    for(i = 0; i < n; i++) vet[i] = (TC *) malloc(sizeof(TC *));
    for(i = 0; i < n; i++){
      scanf("%d%f", &vet[i]->mat, &vet[i]->nota);
      scanf(" %10[^\n]", vet[i]->data_nasc);
    }
    ordena(vet, n);
    for(i = 0; i < n; i++) {
        printf("%d\n", vet[i]->mat);
    }
    for(i = 0; i < n; i++) free(vet[i]);
  }
  return 0; 
}

void ordena(TC **vet, int n) {
    qsort(vet, n, sizeof(TC*), cmp);
}

// 22/09/2020
char *dateToString(char *data) {
    char *string = (char *) malloc (sizeof(int) * 9);
    string[0] = data[6]; // Y
    string[1] = data[7]; // Y
    string[2] = data[8]; // Y
    string[3] = data[9]; // Y
    string[4] = data[3]; // M
    string[5] = data[4]; // M
    string[6] = data[0]; // D
    string[7] = data[1]; // D
    string[8] = '\0'; // D
    return string;
}

int cmp(const void *x, const void *y){
    TC **px = (TC **) x, **py = (TC **) y;

    // printf("px[0]->mat = %d, py[0]->mat = %d \n", px[0]->mat, py[0]->mat);
    // printf("px[0]->nota = %f, py[0]->nota = %f \n", px[0]->nota, py[0]->nota);
    // printf("px[0]->data_nasc = %s, py[0]->data_nasc = %s \n", px[0]->data_nasc, py[0]->data_nasc);

    if(px[0]->nota > py[0]->nota) return -1;
    if(px[0]->nota < py[0]->nota) return 1;

    int compara_data = strcmp(dateToString(px[0]->data_nasc) , dateToString(py[0]->data_nasc));
    if(compara_data != 0) return compara_data;

    if(px[0]->mat < py[0]->mat) return -1;
    if(px[0]->mat > py[0]->mat) return 1;
    return 1;
}
