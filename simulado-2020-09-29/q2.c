#include <stdio.h>
#include <stdlib.h>

int* axd(int *vet, int n, int x, int *tam);

int main(void){
  while(1){
    int n;
    scanf("%d", &n);
    if(n <= 0) return 0;
    int vet[n], x;
    int i;
    for(i = 0; i < n; i++) scanf("%d", &vet[i]);
    scanf("%d", &x);
    int nresp;
    int* resp = axd(vet, n, x, &nresp);
    for(i = 0; i < nresp; i++) printf("%d ", resp[i]);
    printf("\n");
    free(resp);
  }
}

int* axd(int *vet, int n, int x, int *tam) {
    int qtd_1 = 0;
    int index = 0;
    // Obtendo quantos 1 eu tenho
    for (int cont = 0; cont < n; cont++) {
        if(vet[cont] == x) qtd_1++;
    }

    int tamanho_vetor_final = n - qtd_1 + (qtd_1 * 3);
    int *lista = (int *) malloc (sizeof(int) * tamanho_vetor_final);
    
    // printf("tamanho_vetor_final = %d\n", tamanho_vetor_final);

    for(int i = 0; i < n; i++) {
        if(vet[i] == x) {
            lista[index] = x -1;
            // printf("index = %d, valor = %d\n", index, lista[index]);
            lista[++index] = vet[i];
            // printf("index = %d, valor = %d\n", index, lista[index]);
            lista[++index] = x + 1;
            // printf("index = %d, valor = %d\n", index, lista[index]);
        } else {
            lista[index] = vet[i];
            // printf("index = %d, valor = %d\n", index, lista[index]);
        }
        index++;
    }
    *tam = tamanho_vetor_final;
    return lista;
}